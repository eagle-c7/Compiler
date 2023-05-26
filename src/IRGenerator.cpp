#include "AST.hpp"
#include "IRGenerator.hpp"

void IRGenerator::GenerateCode(BaseAST* root) {
    root->IRGen(*this);
	this->Module->print(llvm::outs(), NULL);
}

void IRGenerator::GenObjectCode(std::string outputfile) {
	auto TargetTriple = llvm::sys::getDefaultTargetTriple();
    llvm::InitializeAllTargetInfos();
    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmParsers();
    llvm::InitializeAllAsmPrinters();

    auto Features = "";
    auto CPU = "generic";
    std::string Error;
    auto Target = llvm::TargetRegistry::lookupTarget(TargetTriple, Error);

    llvm::TargetOptions opt;
    auto RM = llvm::Optional<llvm::Reloc::Model>();
    auto TargetMachine = Target->createTargetMachine(TargetTriple, CPU, Features, opt, RM);
    Module->setDataLayout(TargetMachine->createDataLayout());
    Module->setTargetTriple(TargetTriple);

    std::error_code EC;
    llvm::raw_fd_ostream Dest(outputfile, EC, llvm::sys::fs::OF_None);

    auto FileType = llvm::CGFT_ObjectFile;
    llvm::legacy::PassManager PM;
    TargetMachine->addPassesToEmitFile(PM, Dest, nullptr, FileType);

    PM.run(*Module);
    Dest.flush();
}

void IRGenerator::CreateVar(VarType type, std::string name, llvm::Value* value){
    // first judge name
    int conflictCnt; 
    int varCnt = this->varList_.size(); 
    if (this->curBasicBlock_) conflictCnt = this->curBasicBlock_->varCnt_; 
    else conflictCnt = varCnt;
    for (int i = 1; i <= conflictCnt; i++) {
        if (this->varList_[varCnt-i]->name_ == name) {
            // already has the same name
            throw std::logic_error("Already Create a Variable with Name: "+name);
        }
    } 

    this->varList_.push_back(new IRVarAttr(type, name, value));
    if (this->curBasicBlock_) this->curBasicBlock_->varCnt_ += 1; 
}

void IRGenerator::DiscardVar() {
    if (this->curBasicBlock_)
        for (int i = 0; i < this->curBasicBlock_->varCnt_; i++) {
            auto var = this->varList_[this->varList_.size()-1];
            this->varList_.pop_back();
            delete var; 
        }
}

llvm::Value* IRGenerator::FindVar(std::string name){
	if(this->varList_.size() == 0){
		return NULL;
	}
	for(auto symbol = this->varList_.end() - 1; symbol >= this->varList_.begin(); symbol--){
		if((*symbol)->name_ == name){
			return (*symbol)->value_;
		}
	}
	return NULL;
}

void IRGenerator::SetCurFunc(llvm::Function* curFunc) {
    this->curFunc_ = curFunc; 
}

llvm::Function* IRGenerator::GetCurFunc() {
    return this->curFunc_; 
}

void IRGenerator::SetPreBrSignal() {
    this->bbCreatePreBrSignal_ = true; 
}

bool IRGenerator::ClearPreBrSignal() {
    bool bbCreatePreBrSignal = this->bbCreatePreBrSignal_; 
    this->bbCreatePreBrSignal_ = false;
    return bbCreatePreBrSignal;
}

bool IRGenerator::GetPreBrSignal() {
    return this->bbCreatePreBrSignal_; 
}

BlockAST* IRGenerator::GetBasicBlock() {
    return this->curBasicBlock_; 
}

void IRGenerator::SetBasicBlock(BlockAST* newBasicBlock){
    this->curBasicBlock_ = newBasicBlock; 
}

void IRGenerator::EnterLoop(llvm::BasicBlock* condBlock, llvm::BasicBlock* iterBlock, llvm::BasicBlock* exitBlock) {
    this->loopLevel_.push_back(new IRLoopAttr(condBlock, iterBlock, exitBlock));
}

void IRGenerator::LeaveCurrentLoop() {
    this->loopLevel_.pop_back();
}

llvm::BasicBlock* IRGenerator::BreakCurrentLoop() {
    auto currentLoop = this->loopLevel_[this->loopLevel_.size()-1];
    return currentLoop->exitBlock_; 
}

llvm::BasicBlock* IRGenerator::ContinueCurrentLoop() {
    auto currentLoop = this->loopLevel_[this->loopLevel_.size()-1];
    return currentLoop->iterBlock_?currentLoop->iterBlock_:currentLoop->condBlock_; 
}
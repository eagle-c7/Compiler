/**
 * @file AST.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <cstdio>
#include <iostream>
#include <vector>
#include "AST.hpp"
#include "IRGenerator.hpp"


/**
 * @brief 考虑到逻辑运算中需要用到true or false的判断
 * 通过该函数把类型转换成bool型（即1bit）
 * 
 */
llvm::Value* ToBoolType(llvm::Value* Value, IRGenerator& IRContext) {
	auto IRBuilder = IRContext.IRBuilder; 
	if (Value->getType() == IRBuilder->getInt1Ty()) return Value;
	else if (Value->getType()->isIntegerTy()){
		auto v2 = llvm::ConstantInt::get((llvm::IntegerType*)Value->getType(), 0, true);
		return IRBuilder->CreateICmpNE(Value, v2);
	}else{
		return NULL;
	}
}


llvm::Value* ProgramAST::IRGen(IRGenerator& IRContext) {
    std::cout << "ProgramAST" << std::endl;

	for (auto compUnit : *(this->compUnit_)){
		if(compUnit){
			compUnit->IRGen(IRContext);
		}
	}

	return NULL;
}

// llvm::Value* VarDeclAST::IRGen(IRGenerator& IRContext) {
// 	std::cout << "VarDeclAST" << std::endl;

// 	auto IRBuilder = IRContext.IRBuilder; 

// 	//Get the llvm type
// 	llvm::Type* VarType = this->_VarType->GetLLVMType(__Generator);

// 	if (this->type_.GetType() == Int)
//         varType = IRBuilder->getInt32Ty();

// 	llvm::Constant* Initializer = NULL;

// 	if(this->varInit_->initExpr_){

// 	}
	
// }



llvm::Value* FuncDefAST::IRGen(IRGenerator& IRContext) {
    //Get return type
    std::cout << "FunctionAST" << std::endl;

    auto IRBuilder = IRContext.IRBuilder; 
    llvm::Type* ReturnType; 
    if (this->type_.GetType() == Int)
        ReturnType = IRBuilder->getInt32Ty();

    std::vector<llvm::Type*> ArgTypes; 

    //Get function type
    llvm::FunctionType* FuncType = llvm::FunctionType::get(ReturnType, ArgTypes, false);
    //Create function
    llvm::Function* Func = llvm::Function::Create(FuncType, llvm::Function::ExternalLinkage, this->funcName_, IRContext.Module);
	IRContext.SetCurFunc(Func);
    // IRContext.AddFunction(this->funcname, Func);
    // IRContext.Module->print(llvm::outs(), NULL);
    // llvm::BasicBlock* FuncBlock = llvm::BasicBlock::Create(*(IRContext.Context), "entry", Func);
    // IRBuilder->SetInsertPoint(FuncBlock);

	IRContext.clearPreBrSignal();
    this->block_->IRGen(IRContext);
    return NULL;
}

llvm::Value* BlockAST::IRGen(IRGenerator& IRContext) {
    std::cout << "BlockAST" << std::endl;
	auto IRBuilder = IRContext.IRBuilder; 

	llvm::Function* Func = IRContext.GetCurFunc();
	llvm::BasicBlock* newBlock = llvm::BasicBlock::Create(*(IRContext.Context), "entry", Func);
	if (IRContext.clearPreBrSignal()) {
		IRBuilder->CreateBr(newBlock);
	}
	IRContext.setPreBrSignal();
    IRBuilder->SetInsertPoint(newBlock);

	for (auto stmt : *(this->stmts_)){
		if(stmt){
			stmt->IRGen(IRContext);
		}
	}
    return NULL; 
}

llvm::Value* ReturnStmtAST::IRGen(IRGenerator& IRContext) {
    std::cout << "ReturnAST" << std::endl;
    auto IRBuilder = IRContext.IRBuilder; 
    IRBuilder->CreateRet(this->RetVal_->IRGen(IRContext));
    return NULL; 
}


/**
 * @brief 算术运算
 * 
 */
llvm::Value* MoncPlus::IRGen(IRGenerator& IRContext) {
	std::cout << "ExprAST +1" << std::endl;
	llvm::Value* val = this->RHS_->IRGen(IRContext);
	return val;

}

llvm::Value* MoncMinus::IRGen(IRGenerator& IRContext) {
	std::cout << "ExprAST -1" << std::endl;
	llvm::Value* val = this->RHS_->IRGen(IRContext);
	auto IRBuilder = IRContext.IRBuilder; 
	return IRBuilder->CreateNeg(val);

}

llvm::Value* Addition::IRGen(IRGenerator& IRContext) {
    std::cout << "ExprAST +" << std::endl;
	auto IRBuilder = IRContext.IRBuilder; 
	llvm::Value* LHS = this->LHS_->IRGen(IRContext);
	llvm::Value* RHS = this->RHS_->IRGen(IRContext);
	return IRBuilder->CreateAdd(LHS, RHS);
}

llvm::Value* Subtraction::IRGen(IRGenerator& IRContext) {
    std::cout << "ExprAST -" << std::endl;
	auto IRBuilder = IRContext.IRBuilder; 
	llvm::Value* LHS = this->LHS_->IRGen(IRContext);
	llvm::Value* RHS = this->RHS_->IRGen(IRContext);
	return IRBuilder->CreateSub(LHS, RHS);
}

llvm::Value* Multiplication::IRGen(IRGenerator& IRContext) {
    std::cout << "ExprAST *" << std::endl;
	auto IRBuilder = IRContext.IRBuilder; 
	llvm::Value* LHS = this->LHS_->IRGen(IRContext);
	llvm::Value* RHS = this->RHS_->IRGen(IRContext);
	return IRBuilder->CreateMul(LHS, RHS);
}

llvm::Value* Division::IRGen(IRGenerator& IRContext) {
    std::cout << "ExprAST /" << std::endl;
	auto IRBuilder = IRContext.IRBuilder; 
	llvm::Value* LHS = this->LHS_->IRGen(IRContext);
	llvm::Value* RHS = this->RHS_->IRGen(IRContext);
	return IRBuilder->CreateSDiv(LHS, RHS);
}

llvm::Value* Modulation::IRGen(IRGenerator& IRContext) {
    std::cout << "ExprAST %" << std::endl;
	auto IRBuilder = IRContext.IRBuilder; 
	llvm::Value* LHS = this->LHS_->IRGen(IRContext);
	llvm::Value* RHS = this->RHS_->IRGen(IRContext);
	return IRBuilder->CreateSRem(LHS, RHS);
}


/**
 * @brief 逻辑运算
 * 
 */
llvm::Value* LogicNot::IRGen(IRGenerator& IRContext) {
	std::cout << "ExprAST !" << std::endl;
	llvm::Value* val = this->RHS_->IRGen(IRContext);
	auto IRBuilder = IRContext.IRBuilder;
	return IRBuilder->CreateICmpEQ(ToBoolType(val, IRContext), IRBuilder->getInt1(false));
}

llvm::Value* AndOp::IRGen(IRGenerator& IRContext) {
	std::cout << "ExprAST &&" << std::endl;
	auto IRBuilder = IRContext.IRBuilder; 
	llvm::Value* LHS = ToBoolType(this->LHS_->IRGen(IRContext), IRContext);
	llvm::Value* RHS = ToBoolType(this->RHS_->IRGen(IRContext), IRContext);
	return IRBuilder->CreateLogicalAnd(LHS, RHS);
}

llvm::Value* OrOp::IRGen(IRGenerator& IRContext) {
	std::cout << "ExprAST ||" << std::endl;
	auto IRBuilder = IRContext.IRBuilder; 
	llvm::Value* LHS = ToBoolType(this->LHS_->IRGen(IRContext), IRContext);
	llvm::Value* RHS = ToBoolType(this->RHS_->IRGen(IRContext), IRContext);
	return IRBuilder->CreateLogicalOr(LHS, RHS);
}

llvm::Value* Equal::IRGen(IRGenerator& IRContext) {
	std::cout << "ExprAST ==" << std::endl;
	auto IRBuilder = IRContext.IRBuilder; 
	llvm::Value* LHS = this->LHS_->IRGen(IRContext);
	llvm::Value* RHS = this->RHS_->IRGen(IRContext);
	return IRBuilder->CreateICmpEQ(LHS, RHS);
}

llvm::Value* NotEqual::IRGen(IRGenerator& IRContext) {
	std::cout << "ExprAST !=" << std::endl;
	auto IRBuilder = IRContext.IRBuilder; 
	llvm::Value* LHS = this->LHS_->IRGen(IRContext);
	llvm::Value* RHS = this->RHS_->IRGen(IRContext);
	return IRBuilder->CreateICmpNE(LHS, RHS);
}

llvm::Value* GreThan::IRGen(IRGenerator& IRContext) {
	std::cout << "ExprAST >" << std::endl;
	auto IRBuilder = IRContext.IRBuilder; 
	llvm::Value* LHS = this->LHS_->IRGen(IRContext);
	llvm::Value* RHS = this->RHS_->IRGen(IRContext);
	return IRBuilder->CreateICmpSGT(LHS, RHS);
}

llvm::Value* LessThan::IRGen(IRGenerator& IRContext) {
	std::cout << "ExprAST >" << std::endl;
	auto IRBuilder = IRContext.IRBuilder; 
	llvm::Value* LHS = this->LHS_->IRGen(IRContext);
	llvm::Value* RHS = this->RHS_->IRGen(IRContext);
	return IRBuilder->CreateICmpSLT(LHS, RHS);
}

llvm::Value* GreEqu::IRGen(IRGenerator& IRContext) {
	std::cout << "ExprAST >" << std::endl;
	auto IRBuilder = IRContext.IRBuilder; 
	llvm::Value* LHS = this->LHS_->IRGen(IRContext);
	llvm::Value* RHS = this->RHS_->IRGen(IRContext);
	return IRBuilder->CreateICmpSGE(LHS, RHS);
}

llvm::Value* LessEqu::IRGen(IRGenerator& IRContext) {
	std::cout << "ExprAST >" << std::endl;
	auto IRBuilder = IRContext.IRBuilder; 
	llvm::Value* LHS = this->LHS_->IRGen(IRContext);
	llvm::Value* RHS = this->RHS_->IRGen(IRContext);
	return IRBuilder->CreateICmpSLE(LHS, RHS);
}

llvm::Value* Constant::IRGen(IRGenerator& IRContext) {
	std::cout << "Constant" << std::endl;
	auto IRBuilder = IRContext.IRBuilder; 
	return IRBuilder->getInt32(this->int_);
}

llvm::Value* FunctionCall::IRGen(IRGenerator& __Generator) {
	llvm::Function* Func = __Generator.FindFunction(this->_FuncName);
	//Get the function. Throw exception if the function doesn't exist.
	if (Func == NULL) {
		throw std::domain_error(this->_FuncName + " is not a defined function.");
		return NULL;
	}
	//Check the number of args. If Func took a different number of args, reject.
	if (Func->isVarArg() && this->_ArgList->size() < Func->arg_size() ||
		!Func->isVarArg() && this->_ArgList->size() != Func->arg_size()) {
		throw std::invalid_argument("Args doesn't match when calling function " + this->_FuncName + ". Expected " + std::to_string(Func->arg_size()) + ", got " + std::to_string(this->_ArgList->size()));
		return NULL;
	}
	//Check arg types. If Func took different different arg types, reject.
	std::vector<llvm::Value*> ArgList;
	size_t Index = 0;
	for (auto ArgIter = Func->arg_begin(); ArgIter < Func->arg_end(); ArgIter++, Index++) {
		llvm::Value* Arg = this->_ArgList->at(Index)->IRGen(__Generator);
		Arg = TypeCasting(Arg, ArgIter->getType());
		if (Arg == NULL) {
			throw std::invalid_argument(std::to_string(Index) + "-th arg type doesn't match when calling function " + this->_FuncName + ".");
			return NULL;
		}
		ArgList.push_back(Arg);
	}
	//Continue to push arguments if this function takes a variable number of arguments
	//According to the C standard, bool/char/short should be extended to int, and float should be extended to double
	if (Func->isVarArg())
		for (; Index < this->_ArgList->size(); Index++) {
			llvm::Value* Arg = this->_ArgList->at(Index)->CodeGen(__Generator);
			if (Arg->getType()->isIntegerTy())
				Arg = TypeUpgrading(Arg, IRBuilder.getInt32Ty());
			else if (Arg->getType()->isFloatingPointTy())
				Arg = TypeUpgrading(Arg, IRBuilder.getDoubleTy());
			ArgList.push_back(Arg);
		}
	//Create function call.
	return IRBuilder.CreateCall(Func, ArgList);
}
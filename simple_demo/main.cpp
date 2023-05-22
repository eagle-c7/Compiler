/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <fstream>
#include <exception>
#include "AST.hpp"
#include "IRGenerator.hpp"

extern int yyparse();
extern BaseAST* Root;

int main(int argc, const char* argv[]) {
    string inputfile = argv[1]; 
    freopen(inputfile.c_str(), "r", stdin);

    yyparse();
    //Generating code
    IRGenerator Gen;
    Gen.GenerateCode(*Root);

    Gen.GenObjectCode('a.out');

}
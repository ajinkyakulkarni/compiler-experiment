//
// Created by wax on 12/14/16.
//

#include "util/PrettyPrint.h"
#include "gen/Gen.h"
#include "FunctionDecl.h"

FunctionDecl::FunctionDecl(std::string identifier, std::vector<VariableDecl*>* parameters, BlockStmt* body) : Decl(identifier) {
    this->parameters = parameters;
    this->body = body;
}

void FunctionDecl::analyze(Scope* scope) {
    scope->declare(this);
    Scope* innerScope = new Scope(scope);
    body->analyze(innerScope);
}

void FunctionDecl::dump(size_t indent) {
    printIndent(indent);
    std::cout << "func " << identifier << std::endl;
    body->dump(indent + 1);
}

void FunctionDecl::generate(X86Compiler &c) {
    Generate::function(c, this);
}
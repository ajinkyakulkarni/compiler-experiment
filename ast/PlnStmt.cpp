//
// Created by wax on 12/16/16.
//

#include "util/PrettyPrint.h"
#include "PlnStmt.h"

PlnStmt::PlnStmt(Expr* expression) {
    this->expression = expression;
}

void PlnStmt::analyze(Scope* scope) {
    expression->analyze(scope);
}

void PlnStmt::dump(size_t indent) {
    printIndent(indent);
    std::cout << "pln ";
    expression->dump();
    std::cout << std::endl;
}

bool PlnStmt::equals(const Node &other) const {
    const PlnStmt* o = dynamic_cast<const PlnStmt*>(&other);
    if (o == nullptr) return false;

    return *o->expression == *expression;
}

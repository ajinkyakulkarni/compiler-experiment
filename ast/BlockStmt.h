//
// Created by wax on 12/14/16.
//

#ifndef DIG_BLOCKEXPRESSION_H
#define DIG_BLOCKEXPRESSION_H

#include <vector>
#include "Stmt.h"

class BlockStmt : public Stmt {
public:
    BlockStmt(std::vector<Stmt*> statements);
    ~BlockStmt();

    virtual void generate(X86Compiler &c);

    void analyze(Scope* scope);
    virtual bool equals(const Node& other) const;

    void dump(size_t indent);

private:
    std::vector<Stmt*> statements;
};


#endif //DIG_BLOCKEXPRESSION_H

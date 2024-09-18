// twoStringOperation.h
#ifndef TWOSTRINGOPERATIONS_H
#define TWOSTRINGOPERATIONS_H

#include "operationBase.h" 
#include <string>

class ConcatOperation : public StringOperationBase {
public:
    ConcatOperation(std::string* s1, std::string* s2);

    void generate() override;

    std::string execute() override;
};

// Write other operations with 2 input strings below.

#endif // TWOSTRINGOPERATIONS_H
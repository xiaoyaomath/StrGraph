#ifndef OPERATION_H
#define OPERATION_H

#include <string>
#include <vector>
#include <memory>
#include <functional>

class Node;

class Operation {
public:
    Operation(const std::function<std::string(const std::vector<std::string>&)>& func,
              const std::vector<int>& params = {},
              const std::string& name = "");
    
    std::string compute(const std::vector<std::string>& inputStrings) const;

    std::string getName() const;
    void printInfo() const;
    std::shared_ptr<Operation> clone() const;
    void setParams(const std::vector<int>& params);
    void setName(const std::string& name);
    void setFunc(const std::function<std::string(const std::vector<std::string>&)>& func);


private:
    std::string name_;
    std::vector<int> params_;
    std::function<std::string(const std::vector<std::string>&)> func_;
};

#endif // OPERATION_H

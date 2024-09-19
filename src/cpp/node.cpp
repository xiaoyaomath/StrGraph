#include "Node.h"
#include "OperationFactory.h"
#include "Operation.h"

Node::Node(const std::string& value, std::shared_ptr<Operation> op)
    : value_(value), operation_(op), isComputing_(false) {}

std::string Node::getString() const {
    return value_;
}

std::string Node::getSubstring(size_t pos, size_t len) const {
    if (pos >= value_.size()) {
        return "";
    }
    return value_.substr(pos, len);
}

void Node::setString(const std::string& newValue) {
    value_ = newValue;
}

void Node::setOperation(const std::string& opName, const std::vector<std::string>& params) {
    operation_ = OperationFactory::createOperation(opName, params);
    computeString();
}

std::string Node::computeString() {
    if (!operation_) {
        return value_;
    }

    if (isComputing_) {
        throw std::runtime_error("Detected loop in computation.");
    }

    isComputing_ = true;
    value_ = operation_->compute(*this);
    isComputing_ = false;

    return value_;
}

std::shared_ptr<Node> Node::clone() const {
    auto clonedOp = operation_ ? operation_->clone() : nullptr;
    return std::make_shared<Node>(value_, clonedOp);
}

void Node::printInfo() const {
    std::cout << "Node Info:" << std::endl;
    std::cout << "  Value: " << value_ << std::endl;
    if (operation_) {
        std::cout << "  Operation: " << operation_->getName() << std::endl;
        operation_->printInfo();
    } else {
        std::cout << "  Operation: None" << std::endl;
    }
}

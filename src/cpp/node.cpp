#include "node.h"
#include "operationBase.h"  // 确保包含正确的头文件
#include <utility>

Node::Node(const std::string& value, std::shared_ptr<StringOperationBase> operation)
    : value_(value), operation_(std::move(operation)) {}

std::shared_ptr<Node> Node::getptr() {
    return shared_from_this();
}

std::string Node::get_value() const {
    return value_;
}

void Node::set_value(const std::string& new_value) {
    value_ = new_value;
}

void Node::set_operation(std::shared_ptr<StringOperationBase> operation) {
    operation_ = std::move(operation);
}

std::string Node::apply_operation() {
    if (operation_) {
        value_ = operation_->execute();
    }
    return value_; 
}
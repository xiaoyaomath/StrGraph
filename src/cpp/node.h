#ifndef NODE_H
#define NODE_H

#include <memory>
#include <string>

class StringOperationBase;  // 前向声明

class Node : public std::enable_shared_from_this<Node> {
public:
    explicit Node(const std::string& value, std::shared_ptr<StringOperationBase> operation = nullptr);

    Node(const Node& other) = delete;
    Node(Node&& other) = delete;
    Node& operator=(const Node& other) = delete;
    Node& operator=(Node&& other) = delete;

    virtual ~Node() = default;

    std::shared_ptr<Node> getptr();

    std::string get_value() const;

    void set_value(const std::string& new_value);

    void set_operation(std::shared_ptr<StringOperationBase> operation);

    std::string apply_operation();

private:
    std::string value_;
    std::shared_ptr<StringOperationBase> operation_;
};

#endif // NODE_H
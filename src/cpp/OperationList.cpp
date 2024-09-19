#include "OperationFactory.h"
#include "Node.h"
#include <algorithm>

// 字符串连接操作
std::string ConcatOperation(const Node& node, const std::vector<std::string>& params) {
    if (params.empty()) {
        throw std::runtime_error("Concat operation requires at least one parameter.");
    }
    return node.getString() + params[0];
}

// 字符串切片操作
std::string SliceOperation(const Node& node, const std::vector<std::string>& params) {
    if (params.size() < 2) {
        throw std::runtime_error("Slice operation requires two parameters: start and length.");
    }
    size_t start = std::stoi(params[0]);
    size_t length = std::stoi(params[1]);
    return node.getSubstring(start, length);
}

// 字符串截断操作
std::string TruncateOperation(const Node& node, const std::vector<std::string>& params) {
    if (params.empty()) {
        throw std::runtime_error("Truncate operation requires a length parameter.");
    }
    size_t length = std::stoi(params[0]);
    return node.getString().substr(0, length);
}

// 字符串反转操作
std::string ReverseOperation(const Node& node, const std::vector<std::string>&) {
    std::string str = node.getString();
    std::reverse(str.begin(), str.end());
    return str;
}

// 字符串重复操作
std::string RepeatOperation(const Node& node, const std::vector<std::string>& params) {
    if (params.empty()) {
        throw std::runtime_error("Repeat operation requires a repeat count.");
    }
    int count = std::stoi(params[0]);
    std::string result;
    for (int i = 0; i < count; ++i) {
        result += node.getString();
    }
    return result;
}

// 字符串修剪操作（去除首尾空格）
std::string TrimOperation(const Node& node, const std::vector<std::string>&) {
    std::string str = node.getString();
    size_t first = str.find_first_not_of(" \t\n");
    size_t last = str.find_last_not_of(" \t\n");
    return str.substr(first, (last - first + 1));
}

// 字符串插入操作
std::string InsertOperation(const Node& node, const std::vector<std::string>& params) {
    if (params.size() < 2) {
        throw std::runtime_error("Insert operation requires position and substring.");
    }
    size_t pos = std::stoi(params[0]);
    std::string toInsert = params[1];
    std::string str = node.getString();
    return str.insert(pos, toInsert);
}

// 字符串替换操作
std::string ReplaceOperation(const Node& node, const std::vector<std::string>& params) {
    if (params.size() < 2) {
        throw std::runtime_error("Replace operation requires target and replacement strings.");
    }
    std::string str = node.getString();
    size_t pos = str.find(params[0]);
    if (pos != std::string::npos) {
        str.replace(pos, params[0].length(), params[1]);
    }
    return str;
}

// 全局字符串替换操作
std::string ReplaceAllOperation(const Node& node, const std::vector<std::string>& params) {
    if (params.size() < 2) {
        throw std::runtime_error("ReplaceAll operation requires target and replacement strings.");
    }
    std::string str = node.getString();
    size_t pos = 0;
    while ((pos = str.find(params[0], pos)) != std::string::npos) {
        str.replace(pos, params[0].length(), params[1]);
        pos += params[1].length();
    }
    return str;
}

// 字符串删除操作
std::string DeleteOperation(const Node& node, const std::vector<std::string>& params) {
    if (params.empty()) {
        throw std::runtime_error("Delete operation requires a target string to delete.");
    }
    std::string str = node.getString();
    size_t pos = str.find(params[0]);
    if (pos != std::string::npos) {
        str.erase(pos, params[0].length());
    }
    return str;
}

// 注册所有操作
void registerOperations() {
    OperationFactory::registerOperation("concat", ConcatOperation);
    OperationFactory::registerOperation("slice", SliceOperation);
    OperationFactory::registerOperation("truncate", TruncateOperation);
    OperationFactory::registerOperation("reverse", ReverseOperation);
    OperationFactory::registerOperation("repeat", RepeatOperation);
    OperationFactory::registerOperation("trim", TrimOperation);
    OperationFactory::registerOperation("insert", InsertOperation);
    OperationFactory::registerOperation("replace", ReplaceOperation);
    OperationFactory::registerOperation("replace_all", ReplaceAllOperation);
    OperationFactory::registerOperation("delete", DeleteOperation);
}

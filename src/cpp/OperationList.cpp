#include "OperationList.h"
#include "OperationManager.h"
#include "Node.h"

// Concatenate operation
std::string ConcatOperation(const std::vector<std::string>& inputStrings) {
    if (inputStrings.size() < 2) {
        throw std::runtime_error("Concat operation requires at least two input nodes.");
    }
    return inputStrings[0] + inputStrings[1];
}

// Slice operation
std::string SliceOperation(const std::vector<std::string>& inputStrings) {
    if (inputStrings.size() < 1) {
        throw std::runtime_error("Slice operation requires at least one input node.");
    }
    // Assuming params[0] = start, params[1] = end
    int start = std::stoi(inputStrings[1]);
    int end = std::stoi(inputStrings[2]);
    return inputStrings[0].substr(start, end - start);
}

// Reverse operation
std::string ReverseOperation(const std::vector<std::string>& inputStrings) {
    if (inputStrings.size() != 1) {
        throw std::runtime_error("Reverse operation requires exactly one input node.");
    }
    std::string reversedString = inputStrings[0];
    std::reverse(reversedString.begin(), reversedString.end());
    return reversedString;
}

// Repeat operation
std::string RepeatOperation(const std::vector<std::string>& inputStrings) {
    if (inputStrings.size() != 2) {
        throw std::runtime_error("Repeat operation requires two input nodes (string and repetition count).");
    }
    int count = std::stoi(inputStrings[1]);
    std::string result;
    for (int i = 0; i < count; ++i) {
        result += inputStrings[0];
    }
    return result;
}

// Trim operation
std::string TrimOperation(const std::vector<std::string>& inputStrings) {
    if (inputStrings.size() != 1) {
        throw std::runtime_error("Trim operation requires exactly one input node.");
    }
    std::string str = inputStrings[0];
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](int ch) {
        return !std::isspace(ch);
    }));
    str.erase(std::find_if(str.rbegin(), str.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), str.end());
    return str;
}

// Insert operation
std::string InsertOperation(const std::vector<std::string>& inputStrings) {
    if (inputStrings.size() != 3) {
        throw std::runtime_error("Insert operation requires three input nodes (string, position, and substring).");
    }
    std::string original = inputStrings[0];
    int pos = std::stoi(inputStrings[1]);
    std::string toInsert = inputStrings[2];
    if (pos < 0 || pos > original.size()) {
        throw std::runtime_error("Insert position is out of bounds.");
    }
    return original.insert(pos, toInsert);
}

// Replace operation
std::string ReplaceOperation(const std::vector<std::string>& inputStrings) {
    if (inputStrings.size() != 3) {
        throw std::runtime_error("Replace operation requires three input nodes (string, target, and replacement).");
    }
    std::string original = inputStrings[0];
    std::string target = inputStrings[1];
    std::string replacement = inputStrings[2];
    
    size_t pos = original.find(target);
    if (pos != std::string::npos) {
        original.replace(pos, target.length(), replacement);
    }
    return original;
}

// Replace All operation
std::string ReplaceAllOperation(const std::vector<std::string>& inputStrings) {
    if (inputStrings.size() != 3) {
        throw std::runtime_error("ReplaceAll operation requires three input nodes (string, target, and replacement).");
    }
    std::string original = inputStrings[0];
    std::string target = inputStrings[1];
    std::string replacement = inputStrings[2];
    
    size_t pos = 0;
    while ((pos = original.find(target, pos)) != std::string::npos) {
        original.replace(pos, target.length(), replacement);
        pos += replacement.length();
    }
    return original;
}

// Delete operation
std::string DeleteOperation(const std::vector<std::string>& inputStrings) {
    if (inputStrings.size() != 2) {
        throw std::runtime_error("Delete operation requires two input nodes (string and target).");
    }
    std::string original = inputStrings[0];
    std::string target = inputStrings[1];
    
    size_t pos = original.find(target);
    if (pos != std::string::npos) {
        original.erase(pos, target.length());
    }
    return original;
}



// Register all operations
void registerOperations() {
    auto& manager = OperationManager::getInstance();

    manager.registerOperation("Concat", std::make_shared<Operation>(
        std::function<std::string(const std::vector<std::string>&)>(ConcatOperation),
        std::vector<int>{}, "Concat")
    );

    manager.registerOperation("Slice", std::make_shared<Operation>(
        std::function<std::string(const std::vector<std::string>&)>(SliceOperation),
        std::vector<int>{}, "Slice")
    );

    manager.registerOperation("Reverse", std::make_shared<Operation>(
        std::function<std::string(const std::vector<std::string>&)>(ReverseOperation),
        std::vector<int>{}, "Reverse")
    );

    manager.registerOperation("Repeat", std::make_shared<Operation>(
        std::function<std::string(const std::vector<std::string>&)>(RepeatOperation),
        std::vector<int>{}, "Repeat")
    );

    manager.registerOperation("Trim", std::make_shared<Operation>(
        std::function<std::string(const std::vector<std::string>&)>(TrimOperation),
        std::vector<int>{}, "Trim")
    );

    manager.registerOperation("Insert", std::make_shared<Operation>(
        std::function<std::string(const std::vector<std::string>&)>(InsertOperation),
        std::vector<int>{}, "Insert")
    );

    manager.registerOperation("Replace", std::make_shared<Operation>(
        std::function<std::string(const std::vector<std::string>&)>(ReplaceOperation),
        std::vector<int>{}, "Replace")
    );

    manager.registerOperation("ReplaceAll", std::make_shared<Operation>(
        std::function<std::string(const std::vector<std::string>&)>(ReplaceAllOperation),
        std::vector<int>{}, "ReplaceAll")
    );

    manager.registerOperation("Delete", std::make_shared<Operation>(
        std::function<std::string(const std::vector<std::string>&)>(DeleteOperation),
        std::vector<int>{}, "Delete")
    );
}

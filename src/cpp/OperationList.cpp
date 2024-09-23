#include "OperationList.h"
#include "OperationManager.h"
#include "Node.h"

// Concatenate operation
std::string ConcatOperation(const std::vector<std::string>& inputStrings, const std::vector<int>& params) {
    if (inputStrings.size() < 2) {
        throw std::runtime_error("Concat operation requires at least two input nodes.");
    }
    if (!params.empty()) {
        throw std::runtime_error("Concat operation does not require any parameters.");
    }
    return inputStrings[0] + inputStrings[1];
}

// Slice operation
std::string SliceOperation(const std::vector<std::string>& inputStrings, const std::vector<int>& params) {
    if (inputStrings.size() != 1) {
        throw std::runtime_error("Slice operation requires exactly one input string.");
    }
    if (params.size() != 2) {
        throw std::runtime_error("Slice operation requires exactly two parameters (start and end indices).");
    }

    int start = params[0];  // Start index from params
    int end = params[1];    // End index from params

    if (start < 0 || end > static_cast<int>(inputStrings[0].size()) || start >= end) {
        throw std::runtime_error("Invalid slice indices.");
    }

    return inputStrings[0].substr(start, end - start);
}

// Reverse operation
std::string ReverseOperation(const std::vector<std::string>& inputStrings, const std::vector<int>& params) {
    if (inputStrings.size() != 1) {
        throw std::runtime_error("Reverse operation requires exactly one input node.");
    }
    if (!params.empty()) {
        throw std::runtime_error("Reverse operation does not require any parameters.");
    }
    std::string reversedString = inputStrings[0];
    std::reverse(reversedString.begin(), reversedString.end());
    return reversedString;
}

// Repeat operation
std::string RepeatOperation(const std::vector<std::string>& inputStrings, const std::vector<int>& params) {
    if (inputStrings.size() != 1) {
        throw std::runtime_error("Repeat operation requires exactly one input node (the string to repeat).");
    }
    if (params.size() != 1) {
        throw std::runtime_error("Repeat operation requires exactly one parameter (the repetition count).");
    }

    int count = params[0];  // Repetition count from params
    if (count < 0) {
        throw std::runtime_error("Repetition count cannot be negative.");
    }

    std::string result;
    for (int i = 0; i < count; ++i) {
        result += inputStrings[0];
    }

    return result;
}

// Trim operation
std::string TrimOperation(const std::vector<std::string>& inputStrings, const std::vector<int>& params) {
    if (inputStrings.size() != 1) {
        throw std::runtime_error("Trim operation requires exactly one input node.");
    }
    if (!params.empty()) {
        throw std::runtime_error("Trim operation does not require any parameters.");
    }
    std::string str = inputStrings[0];
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), str.end());
    return str;
}

// Insert operation
std::string InsertOperation(const std::vector<std::string>& inputStrings, const std::vector<int>& params) {
    if (inputStrings.size() != 2) {
        throw std::runtime_error("Insert operation requires exactly two input nodes (string and substring to insert).");
    }
    if (params.size() != 1) {
        throw std::runtime_error("Insert operation requires exactly one parameter (the insertion position).");
    }

    std::string original = inputStrings[0];
    std::string toInsert = inputStrings[1];
    int pos = params[0];  // Insertion position from params

    if (pos < 0 || pos > static_cast<int>(original.size())) {
        throw std::runtime_error("Insert position is out of bounds.");
    }

    original.insert(pos, toInsert);
    return original;
}

// Replace operation
std::string ReplaceOperation(const std::vector<std::string>& inputStrings, const std::vector<int>& params) {
    if (inputStrings.size() != 3) {
        throw std::runtime_error("Replace operation requires exactly three input nodes (string, target, and replacement).");
    }
    if (!params.empty()) {
        throw std::runtime_error("Replace operation does not require any parameters.");
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
std::string ReplaceAllOperation(const std::vector<std::string>& inputStrings, const std::vector<int>& params) {
    if (inputStrings.size() != 3) {
        throw std::runtime_error("ReplaceAll operation requires exactly three input nodes (string, target, and replacement).");
    }
    if (!params.empty()) {
        throw std::runtime_error("ReplaceAll operation does not require any parameters.");
    }

    std::string original = inputStrings[0];
    std::string target = inputStrings[1];
    std::string replacement = inputStrings[2];

    if (target.empty()) {
        throw std::runtime_error("Target string for replacement cannot be empty.");
    }

    size_t pos = 0;
    while ((pos = original.find(target, pos)) != std::string::npos) {
        original.replace(pos, target.length(), replacement);
        pos += replacement.length();
    }
    return original;
}

// Delete operation
std::string DeleteOperation(const std::vector<std::string>& inputStrings, const std::vector<int>& params) {
    if (inputStrings.size() != 2) {
        throw std::runtime_error("Delete operation requires exactly two input nodes (string and target).");
    }
    if (!params.empty()) {
        throw std::runtime_error("Delete operation does not require any parameters.");
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
        ConcatOperation,
        std::vector<int>{}, "Concat")
    );

    manager.registerOperation("Slice", std::make_shared<Operation>(
        SliceOperation,
        std::vector<int>{}, "Slice")
    );


    manager.registerOperation("Reverse", std::make_shared<Operation>(
        ReverseOperation,
        std::vector<int>{}, "Reverse")
    );

    manager.registerOperation("Repeat", std::make_shared<Operation>(
        RepeatOperation,
        std::vector<int>{}, "Repeat")
    );


    manager.registerOperation("Trim", std::make_shared<Operation>(
        TrimOperation,
        std::vector<int>{}, "Trim")
    );

    manager.registerOperation("Insert", std::make_shared<Operation>(
        InsertOperation,
        std::vector<int>{}, "Insert")
    );

    manager.registerOperation("Replace", std::make_shared<Operation>(
        ReplaceOperation,
        std::vector<int>{}, "Replace")
    );

    manager.registerOperation("ReplaceAll", std::make_shared<Operation>(
        ReplaceAllOperation,
        std::vector<int>{}, "ReplaceAll")
    );


    manager.registerOperation("Delete", std::make_shared<Operation>(
        DeleteOperation,
        std::vector<int>{}, "Delete")
    );
}

StrGraph 是一个用于操作字符串的图结构实现。它允许创建节点（Node），设置操作，并通过输入节点的依赖进行字符串计算。支持的操作可以通过 OperationManager 注册和管理。

功能
    创建基本节点和带有操作（Operation）的节点。
    设置节点的输入节点并通过图计算其值。
    检测节点依赖图中的循环。
    使用 OperationManager 注册、获取和管理操作。

// 创建一个基础节点，值为 "Hello"
std::shared_ptr<Node> node = std::make_shared<Node>("Hello");
node->printInfo();  // 输出该节点的详细信息

// 创建两个基础节点
std::shared_ptr<Node> nodeA = std::make_shared<Node>("Hello");
std::shared_ptr<Node> nodeB = std::make_shared<Node>("World");
// 获取 "concat" 操作
auto concatOperation = OperationManager::getInstance().getOperation("concat");
// 创建一个带有操作的节点，并将 nodeA 和 nodeB 作为输入
std::shared_ptr<Node> concatNode = std::make_shared<Node>("", concatOperation, std::vector<std::shared_ptr<Node>>{nodeA, nodeB});
// 计算该节点的值并输出
std::string result = concatNode->computeString();
std::cout << "Concatenated result: " << result << std::endl;

// 注册所有操作
registerOperations();
// 创建基础节点
std::shared_ptr<Node> nodeA = std::make_shared<Node>("A");
std::shared_ptr<Node> nodeB = std::make_shared<Node>("B");
// 创建一个空节点
std::shared_ptr<Node> node = std::make_shared<Node>("");
// 获取 "concat" 操作
auto operation = OperationManager::getInstance().getOperation("concat");
// 为该节点设置操作
node->setOperation(operation);
// 设置输入节点
node->setInputNodes({nodeA, nodeB});
// 计算该节点的值并输出
std::string result = node->computeString();
std::cout << "Concatenated result: " << result << std::endl;

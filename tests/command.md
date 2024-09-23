g++ -std=c++14 -I /Users/xiaoyao/googletest/googletest/include -L /Users/xiaoyao/googletest/build/lib -lgtest -lgtest_main -pthread /Users/xiaoyao/Documents/CS/0_项目管理/06/StrGraph/tests/cpp/operationConcat.cpp /Users/xiaoyao/Documents/CS/0_项目管理/06/StrGraph/src/cpp/twoStringOperations.cpp -o test_operationConcat

// node
g++ -std=c++14 -I /Users/xiaoyao/googletest/googletest/include -L /Users/xiaoyao/googletest/build/lib -lgtest -lgtest_main -pthread /Users/xiaoyao/Documents/CS/0_项目管理/06/StrGraph/tests/cpp/nodeTest.cpp /Users/xiaoyao/Documents/CS/0_项目管理/06/StrGraph/src/cpp/node.h -o nodeTest

g++ -std=c++14 \
    -I /Users/xiaoyao/googletest/googletest/include \
    -I /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp \
    -L /Users/xiaoyao/googletest/build/lib \
    -lgtest -lgtest_main -pthread \
    /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/tests/cpp/TestNode.cpp \
    /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/Node.cpp \
    /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/Operation.cpp \
    /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/NodeFactory.cpp \
    /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/OperationManager.cpp \
    /Users/xiaoyao/Documents/CS/0_projects/06/StrGraph/src/cpp/OperationList.cpp \
    -o TestNode





cd StrGraph/tests/cpp


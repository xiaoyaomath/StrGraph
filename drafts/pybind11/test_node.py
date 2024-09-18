import node

# 创建一个 Node 对象，初始值为 10
n = node.Node(10)

# 获取当前值
print(f"Initial value: {n.get_value()}")  # 输出: 10

# 设置新值为 20
n.set_value(20)

# 获取更新后的值
print(f"Updated value: {n.get_value()}")  # 输出: 20
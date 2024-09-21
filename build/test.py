import strgraph
from strgraph import Node, Concat, manager, Operations, Operation

# List available operations using the globally exposed 'manager'
manager.list_operations()

# Retrieve the 'concat' operation
concat_op = Operations("Concat")


# Print operation info
concat_op.print_info()

# Test concatenation operation using NodeFactory
# node1 = Node("Hello, ")
# node2 = Node("World!")

"""
# concat_node = strgraph.NodeFactory.create_operation_node("Concat", [node1, node2])
# node3 = strgraph.NodeFactory.create_operation_node("Concat", [node1, node2])
node3 = Concat(node1, node2)

node1.set_string("你好, ")

node3.set_string("foo")
node3.print_info()

node4 = Node("世界")

node3.set_input_nodes([node1, node4])

result = node3.compute_string()

# Compute the result
# result = concat_node.compute_string()
print("Concatenation result:", result)
"""

def self_defined_function(s):
    return s[0].upper()


upper_op = Operation(self_defined_function, [], "Upper")

"""
node5 = Node("", upper_op, [node1])

node5.compute_string()

print(node5.get_string())

node5.print_info()
"""

"""
manager.register("Upper", upper_op)

upper2_op = Operations("Upper")

node6 = Node("", upper_op, [node1])

node6.compute_string()

print(node6.get_string())

node6.print_info()
"""


nodea = Node('a')
nodeb = Node('b')
nodec = Node('c')
nodeab = Concat(nodea, nodeb)
nodeabc = Concat(nodeab, nodec)
# nodeab.compute_string()
# nodeabc.compute_string()
nodeabc.print_graph(0)
nodeabc.compute_graph()
nodeabc.print_graph(0)


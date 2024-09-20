import strgraph

# Get the OperationManager instance
manager = strgraph.OperationManager.get_instance()

# List available operations
manager.list_operations()

# Retrieve the 'concat' operation
concat_op = manager.get_operation("concat")

# Print operation info
concat_op.print_info()

# Test concatenation operation using NodeFactory
from strgraph import NodeFactory

node1 = NodeFactory.create_value_node("Hello, ")
node2 = NodeFactory.create_value_node("World!")

concat_node = NodeFactory.create_operation_node("concat", [node1, node2])

# Compute the result
result = concat_node.compute_string()
print("Concatenation result:", result)

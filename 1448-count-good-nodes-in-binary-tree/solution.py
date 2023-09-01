# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
def good_nodes_util(root, maximum_value):
    if root is None:
        return 0
    counter = 1 if root.val >= maximum_value else 0
    maximum_value = max(root.val, maximum_value)
    return counter + good_nodes_util(root.left, maximum_value) + good_nodes_util(root.right, maximum_value)


class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        return good_nodes_util(root, -10 ** 4 - 1)

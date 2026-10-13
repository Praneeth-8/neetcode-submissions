# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pred(self,root):
        curr = root
        while(curr and curr.left):
            curr = curr.left
        return curr.val
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        root=self.deleteHelper(root,key)
        return root
    def deleteHelper(self,root,key):
        if not root:
            return
        if key<root.val:
            root.left = self.deleteHelper(root.left,key)
        elif key>root.val:
            root.right = self.deleteHelper(root.right,key)
        else:
            if root.left and root.right:
                predval = self.pred(root.right)
                root.val = predval
                root.right=self.deleteHelper(root.right,predval)
            elif not root.left and not root.right:
                return None
            else:
                node = root.left
                if not node:
                    node = root.right
                return node
        return root


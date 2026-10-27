# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        return self.lcarecur(root,p,q)
    
    def lcarecur(self,root,p,q):
        if p.val==root.val:
            return p
        if q.val==root.val:
            return q
        if p.val<root.val and q.val<root.val:
            return self.lcarecur(root.left,p,q)
        elif p.val>root.val and q.val>root.val:
            return self.lcarecur(root.right,p,q)
        else:
            return root
    
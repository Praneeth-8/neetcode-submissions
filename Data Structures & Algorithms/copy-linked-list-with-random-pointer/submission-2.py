"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return head
        d_copy={}
        node = head
        while(node):
            new_node=Node(node.val)
            if node.random != None:
                d_copy[id(node)]=[new_node,id(node.random)]
            else:
                d_copy[id(node)]=[new_node,None]
            node = node.next

        data = list(d_copy.items())
        for i in range(len(data)-1):
            key,val = data[i]
            keyn,valn = data[i+1]
            val[0].next = valn[0]
            if val[1] is None:
                val[0].random=None
            else:
                val[0].random=d_copy[val[1]][0]
        keyl,vall = data[len(data)-1]
        vall[0].next=None
        if vall[1] !=None:
            vall[0].random = d_copy[vall[1]][0]
        else:
            vall[0].random = None
        return data[0][1][0]

        
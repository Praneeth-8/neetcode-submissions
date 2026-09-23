# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:   
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        n1=l1
        n2=l2
        new_head=ListNode()
        ret=new_head
        carry=0
        while n1 or n2:
            if not n1:
                val = (n2.val + carry)
                n2=n2.next
            elif not n2:
                val = (n1.val+ carry) 
                n1=n1.next
            else:
                val = (n1.val+n2.val + carry) 
                n1=n1.next
                n2=n2.next
            carry = val//10
            new_head.next=ListNode(val%10)
            new_head=new_head.next
        
        if carry!=0:
            new_head.next=ListNode(carry)
        return ret.next

            
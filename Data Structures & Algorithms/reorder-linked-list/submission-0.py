# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def relink(self,start,n):
        if n==1:
            start.next=None
            return start
        if n<1:
            return None
        i=1
        end=start
        while(i<n):##true
            i+=1
            end=end.next
            
        
        nxt=start.next
        start.next=end
        end.next=self.relink(nxt,n-2)
        return start
        
        
    def reorderList(self, head: Optional[ListNode]) -> None:
        n=1;
        nxt=head
        while(nxt.next):##true
            n+=1
            nxt=nxt.next
        self.relink(head,n)

        
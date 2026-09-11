/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p=head;
        ListNode *q=head;
        int len=1;

        while(!(p->next==nullptr)){
            p=p->next;
            len++;
        }
        if(len==1 && n==1){
            head=nullptr;
            return head;
        }
        else if(n==len){
            head=head->next;
            return head;
        }
        for(int i=0;i<len-n-1;i++){
            q=q->next;
        }
        q->next=q->next->next;
        return head;

        
    }
};

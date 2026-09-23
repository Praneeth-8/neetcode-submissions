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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *new_node = new ListNode();
        ListNode *ret = new_node;
        int carry =0 ;
        int val;
        while(l1 || l2){
            if(!l1){
                val = l2->val + carry;
                l2=l2->next;
            }
            else if(!l2){
                val = l1->val + carry;
                l1=l1->next;
            }
            else{
                val= l1->val+l2->val+carry;
                l1=l1->next;
                l2=l2->next;
            }
            carry = val/10;
            ListNode *node = new ListNode(val%10);
            new_node->next = node;
            new_node=new_node->next;
        }
        if(carry!=0){
            ListNode* node = new ListNode(carry);
            new_node->next=node;
        }
        ListNode *ans = ret->next;
        delete ret;
        return ans;
    }
};

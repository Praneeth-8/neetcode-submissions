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
    bool hasCycle(ListNode* head) {
        ListNode* ptr1 = head;
        ListNode* ptr2=head;
        while (ptr2 != nullptr){
            ptr1=ptr1->next;
            if(ptr1==nullptr){
                return false;
            }
            ptr2=ptr2->next;
            if(ptr2==nullptr){
                return false;
            }
            ptr2=ptr2->next;
            if (ptr1==ptr2){
                return true;
            }
        }
        return false;
    }        
    
};

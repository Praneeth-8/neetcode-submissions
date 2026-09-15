/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        deque<TreeNode*> que;
        que.push_back(root);
        while(!que.empty()){
            TreeNode* front=que.front();
            que.pop_front();
            if(same(front,subRoot)){
                return true;
            }
            if(!(front->left==nullptr)){
                que.push_back(front->left);
            }
            if(!(front->right==nullptr)){
                que.push_back(front->right);
            }

        }
        return false;
        
    }
private:
    bool same(TreeNode* p,TreeNode* q){
        if(!p && !q){
            return true;
        }
        if(p && q && p->val==q->val){
            return same(p->left,q->left) && same(p->right,q->right);
        }
        else{
            return false;
        }
    }
};

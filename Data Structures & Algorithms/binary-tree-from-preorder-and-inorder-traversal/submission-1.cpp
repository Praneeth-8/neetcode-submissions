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
    int findIndex(vector<int>& inorder,int left,int right,int num){
        for(int i=left;i<=right;i++){
            if(inorder[i]==num){
                return i;
            }
        }
        return -1;
    }
    TreeNode *constructor(vector<int>& preorder, vector<int>& inorder,int inStart,int inEnd,int &preind){
        if(inStart>inEnd){
            return nullptr;
        }
        if(preind>=preorder.size()){
            return nullptr;
        }
        if(inStart==inEnd){
            preind++;
            return new TreeNode(preorder[preind-1]);
        }
        int elem = preorder[preind];
        int ind = findIndex(inorder,inStart,inEnd,elem);
        if(ind==-1){
            return nullptr;
        }

        TreeNode *root = new TreeNode(elem);
        preind++;
        root->left = constructor(preorder,inorder,inStart,ind-1,preind);
        root->right = constructor(preorder, inorder,ind+1,inEnd,preind);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n =inorder.size();
        int preord =0;
        return constructor(preorder,inorder,0,n-1,preord);
        
    }
};

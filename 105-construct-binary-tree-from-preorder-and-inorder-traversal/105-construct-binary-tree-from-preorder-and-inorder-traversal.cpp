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
    TreeNode* makeTree(vector<int> preorder,vector<int> inorder,int pos,int l,int r){
        if(l>r)return NULL;
        TreeNode* root=new TreeNode(preorder[pos]);
        int i=0;
        for(int n=l;n<=r;n++){
            if(inorder[n]==preorder[pos]){
                i=n;break;
            }
        }
        root->left=makeTree(preorder,inorder,pos+1,l,i-1);
        root->right=makeTree(preorder,inorder,pos+(i-l+1),i+1,r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return makeTree(preorder,inorder,0,0,inorder.size()-1);        
    }
};
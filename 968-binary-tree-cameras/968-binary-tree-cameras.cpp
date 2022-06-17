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
    int sol(TreeNode* root,int &ans){
        if(root==NULL)return 1; //being covered
        int l=sol(root->left,ans);
        int r=sol(root->right,ans);
        if(l==-1 || r==-1){ //Need camera
            ans++;return 0;
        }
        if(l==0 || r==0) // camera on node
            return 1;
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        if(!root)return 0;
        int ans=0;
        if(sol(root,ans)==-1)ans++;
        return ans;
    }
};
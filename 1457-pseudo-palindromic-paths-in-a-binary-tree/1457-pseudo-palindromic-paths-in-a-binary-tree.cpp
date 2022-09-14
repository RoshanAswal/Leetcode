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
    bool ispali(vector<int> &v){
        int f=0;
        for(int i=1;i<=9;i++){
            if(v[i]&1){
                if(!f)f=1;
                else return false;
            }
        }
        return true;
    }
    int ans=0;
    void sol(TreeNode *root,vector<int> &v){
        if(!(root->left) && !(root->right)){
            v[root->val]++;
            if(ispali(v))ans++;
            v[root->val]--;
            return;
        }
        v[root->val]++;
        if(root->left)sol(root->left,v);
        if(root->right)sol(root->right,v);
        v[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> v(10,0);
        sol(root,v);
        return ans;
    }
};
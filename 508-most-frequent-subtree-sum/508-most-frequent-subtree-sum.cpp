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
    map<int,int> m;
    int maxi=0;
    int sol(TreeNode* root){
        if(!root)return 0;
        int s=root->val+sol(root->left)+sol(root->right);
        m[s]++;
        maxi=max(m[s],maxi);
        return s;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(!root->left && !root->right)return {root->val};
        sol(root);
        vector<int> v;
        for(auto it:m){
            if(it.second==maxi)
                v.push_back(it.first);
        }
        return v;
    }
};
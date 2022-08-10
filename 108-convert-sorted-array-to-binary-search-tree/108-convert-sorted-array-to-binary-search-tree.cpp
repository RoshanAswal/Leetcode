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
    TreeNode* sol(vector<int> &nums,int l,int r){
        if(l<=r){
            int m=(l+r)/2;
            TreeNode* temp=new TreeNode(nums[m]);
            temp->left=sol(nums,l,m-1);
            temp->right=sol(nums,m+1,r);
            return temp;
        }
        return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sol(nums,0,nums.size()-1);
    }
};
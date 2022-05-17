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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans=INT_MIN,lvl=1,res=0;
        while(!q.empty()){
            int s=q.size();
            int temp=0;
            for(int i=0;i<s;i++){
                TreeNode* temp_node=q.front();
                q.pop();
                temp+=temp_node->val;
                if(temp_node->left)q.push(temp_node->left);
                if(temp_node->right)q.push(temp_node->right);
            }
            if(temp>ans){
                ans=temp;
                res=lvl;
            }
            lvl++;
        }
        return res;
    }
};
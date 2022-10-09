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
    bool findTarget(TreeNode* root, int k) {
        multiset<int> st;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            while(s--){
                TreeNode* fr=q.front();
                q.pop();
                int f=k-(fr->val);
                if(st.count(f)){
                    if(fr->val==f){
                        if(st.count(f)>1)return true;
                    }else return true;
                }
                st.insert(fr->val);
                if(fr->left)q.push(fr->left);
                if(fr->right)q.push(fr->right);
            }
        }
        return false;
    }
};
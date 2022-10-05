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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* ans=new TreeNode(val);
            ans->left=root;
            return ans;
        }else{
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                int s=q.size();
                depth--;
                while(s--){
                    TreeNode* fr=q.front();
                    q.pop();
                    if(depth==1){
                        TreeNode* t1=new TreeNode(val);
                        TreeNode* t2=new TreeNode(val);
                        TreeNode* temp=fr->left;
                        fr->left=t1;t1->left=temp;
                        temp=fr->right;
                        fr->right=t2;t2->right=temp;
                    }else{
                        if(fr->left)q.push(fr->left);
                        if(fr->right)q.push(fr->right);
                    }
                }
                if(depth==1)return root;
            }
        }
        return root;
    }
};
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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        map<int,TreeNode*> m;
        set<int> s;
        for(auto &it:des){
            TreeNode* root,*newNode;
            if(m.find(it[0])==m.end()){
                root=new TreeNode(it[0]);
                m[it[0]]=root;
            }else
                root=m[it[0]];
            if(m.find(it[1])==m.end()){
                newNode=new TreeNode(it[1]);
                m[it[1]]=newNode;
            }else
                newNode=m[it[1]];
            if(it[2]==0)
                root->right=newNode;
            else
                root->left=newNode;
            s.insert(it[1]);
        }
        for(auto &it:des){
            if(s.find(it[0])==s.end())
                return m[it[0]];
        }
        return NULL;
    }
};
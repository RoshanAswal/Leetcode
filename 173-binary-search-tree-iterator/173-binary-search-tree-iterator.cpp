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
class BSTIterator {
public:
    vector<int> temp;
    int i=0;
    void ini(TreeNode* root){
        if(!root)return;
        ini(root->left);
        temp.push_back(root->val);
        ini(root->right);
    }
    BSTIterator(TreeNode* root) {
        ini(root);
    }
    
    int next() {
        return temp[i++];
    }
    
    bool hasNext() {
        return i<temp.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
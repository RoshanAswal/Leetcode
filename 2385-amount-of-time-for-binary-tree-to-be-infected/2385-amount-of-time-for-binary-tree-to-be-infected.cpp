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
    int bfs(map<int,vector<int>> &graph,int s){
        queue<int> q;
        map<int,int> vis;
        q.push(s);
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int f=q.front();
                q.pop();
                vis[f]=1;
                for(int j=0;j<graph[f].size();j++){
                    if(vis[graph[f][j]]==0){
                        q.push(graph[f][j]);
                    }
                }
            }
            if(q.empty())break;
            ans++;
        }
        return ans;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<int,vector<int>> graph;
        queue<TreeNode*> q;
        q.push(root);
        int source=-1;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* f=q.front();
                q.pop();
                if(f->val==start)source=f->val;
                if(f->left){
                    graph[f->val].push_back(f->left->val);
                    graph[f->left->val].push_back(f->val);
                    q.push(f->left);
                }
                if(f->right){
                    graph[f->val].push_back(f->right->val);
                    graph[f->right->val].push_back(f->val);
                    q.push(f->right);
                }
            }
        }
        int ans=bfs(graph,source);
        return ans;
    }
};
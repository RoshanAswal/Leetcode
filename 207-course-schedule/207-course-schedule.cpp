class Solution {
public:
    bool dfs(int i,vector<vector<int>> &graph,vector<int> &vis,vector<int> &pre){
        vis[i]=1;
        pre[i]=1;
        for(int j:graph[i]){
            if(!vis[j]){
                if(dfs(j,graph,vis,pre))return true; 
            }else if(pre[j])return true;
        }
        pre[i]=0;
        return false;
    }
    bool canFinish(int c, vector<vector<int>>& p) {
        vector<vector<int>> graph(c);
        for(int i=0;i<p.size();i++){
            graph[p[i][0]].push_back(p[i][1]);
        }
        vector<int> vis(c,0),present(c,0);
        for(int i=0;i<c;i++){
            if(!vis[i] && dfs(i,graph,vis,present))
                return false;                
        }
        return true;
    }
};
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int &time,int i,int par,vector<vector<int>> &graph,vector<int> &disc,vector<int> &low,vector<int> &vis){
        vis[i]=1;
        disc[i]=low[i]=time++;
        for(int j:graph[i]){
            if(j==par)continue;
            if(!vis[j]){
                dfs(time,j,i,graph,disc,low,vis);
                low[i]=min(low[i],low[j]);
                if(low[j]>disc[i]){

                    vector<int> temp;
                    temp.push_back(i);temp.push_back(j);
                    ans.push_back(temp);                    
                }
            }else{
                low[i]=min(low[i],disc[j]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& cn) {
        vector<vector<int>> graph(n);
        for(int i=0;i<cn.size();i++){
            graph[cn[i][0]].push_back(cn[i][1]);
            graph[cn[i][1]].push_back(cn[i][0]);
        }
        vector<int> disc(n+1,-1),low(n+1,-1);
        vector<int> vis(n+1,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int time=0;
                dfs(time,i,-1,graph,disc,low,vis);                
            }
        }
        return ans;
    }
};
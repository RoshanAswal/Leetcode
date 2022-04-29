class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,0);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(color[i])continue;
            color[i]=1;
            q.push(i);
            while(!q.empty()){
                int n=q.front();
                q.pop();
                for(int j:graph[n]){
                    if(color[j]==color[n])return false;
                    else if(color[j]==0){
                        color[j]=-color[n];
                        q.push(j);
                    }
                }
            }
        }
        return true;
    }
};
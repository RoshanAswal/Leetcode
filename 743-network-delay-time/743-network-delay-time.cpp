class Solution {
public:
    void dij(vector<vector<pair<int,int>>> &g,int s,vector<int> &dis){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,s});
        dis[s]=0;
        vector<int> vis(g.size()+1,0);
        while(!q.empty()){
            int d=q.top().first;
            int n=q.top().second;
            q.pop();
            if(vis[n])continue;
            vis[n]=1;
            for(auto i:g[n]){
                if(dis[i.first]>d+i.second){
                    dis[i.first]=d+i.second;
                    q.push({dis[i.first],i.first});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<int> dis(n+1,INT_MAX);
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto &it:times){
            graph[it[0]].push_back({it[1],it[2]});
        }
        dij(graph,k,dis);
        int ans=*max_element(dis.begin()+1,dis.end());
        if(ans==INT_MAX)return -1;
        return ans;
    }
};
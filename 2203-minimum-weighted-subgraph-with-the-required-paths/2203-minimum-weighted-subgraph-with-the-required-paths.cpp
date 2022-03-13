class Solution {
public:
    const long long ml=1e18;
    vector<long long> dij(int n,vector<vector<pair<long long,long long>>> &graph,int s){
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        vector<long long> dis(n+1,ml);
        vector<long long> vis(n+1,0);
        dis[s]=0;
        pq.push({0,s});
        while(!pq.empty()){
            long long prev=pq.top().second;
            long long d=pq.top().first;
            vis[prev]=1;
            pq.pop();
            if(dis[prev]!=d)continue;
            for(auto it:graph[prev]){
                long long nxt=it.first;
                long cost=it.second;
                if(!vis[nxt] && dis[nxt]>dis[prev]+cost){
                    dis[nxt]=dis[prev]+cost;
                    pq.push({dis[nxt],nxt});
                }
            }
        }
        return dis;
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<long long,long long>>> graph(n),graph1(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            graph1[edges[i][1]].push_back({edges[i][0],edges[i][2]});            
        }
        vector<long long> dis1=dij(n,graph,src1);
        vector<long long> dis2=dij(n,graph,src2);
        vector<long long> dis3=dij(n,graph1,dest);
        long long ans=ml;
        for(int i=0;i<n;i++){
            ans=min(ans,dis1[i]+dis2[i]+dis3[i]);
        }
        if(ans==ml)return -1;
        return ans;
    }
};
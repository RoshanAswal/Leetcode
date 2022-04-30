class Solution {
public:
    double dij(string src,string des,int l,map<string,vector<pair<string,double>>> graph,map<string,double> dis,map<string,int> vis){
        if(dis.find(src)==dis.end() || dis.find(des)==dis.end())return -1.0;
        priority_queue<pair<double,string>,vector<pair<double,string>>,greater<pair<double,string>>> pq;
        pq.push({1.0,src});
        dis[src]=1.0;
        while(!pq.empty()){
            string prev=pq.top().second;
            vis[prev]=1;
            pq.pop();
            for(auto it:graph[prev]){
                double cost=it.second;
                string nxt=it.first;
                if(vis[nxt])continue;
                if(dis.find(nxt)!=dis.end() && dis[nxt]>dis[prev]*cost){
                    dis[nxt]=dis[prev]*cost;
                    pq.push({dis[nxt],nxt});
                    if(nxt==des)return dis[nxt];
                }
            }
        }
        if(dis[des]==DBL_MAX)
            return -1.0;
        return dis[des];
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& q) {
        map<string,vector<pair<string,double>>> graph;
        vector<double> ans;
        map<string,double> m;
        map<string,int> vis;
        for(int i=0;i<eq.size();i++){
            graph[eq[i][0]].push_back({eq[i][1],val[i]});
            graph[eq[i][1]].push_back({eq[i][0],1.0/val[i]});
            m[eq[i][0]]=DBL_MAX;
            m[eq[i][1]]=DBL_MAX;
            vis[eq[i][0]]=0;
            vis[eq[i][1]]=0;
        }
        for(int i=0;i<q.size();i++){
            map<string,double> temp=m;
            ans.push_back(dij(q[i][0],q[i][1],eq.size(),graph,m,vis));
        }
        return ans;
    }
};
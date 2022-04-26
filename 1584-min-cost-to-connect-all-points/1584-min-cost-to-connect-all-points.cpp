class Solution {
public:
    vector<int> par;
    int parent(vector<int> &P,int x){
        if(P[x]==-1)return x;
        return P[x]=parent(P,P[x]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        par.resize(points.size());
        vector<int> P(points.size(),-1);
        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int dis=(abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]));
                v.push_back({dis,{i,j}});
            }
        }
        int ans=0;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            int x=parent(P,v[i].second.first);
            int y=parent(P,v[i].second.second);
            if(x==y)continue;
            P[x]=y;
            ans+=v[i].first;
        }
        return ans;
    }
};
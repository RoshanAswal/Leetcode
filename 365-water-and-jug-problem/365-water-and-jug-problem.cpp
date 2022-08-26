class Solution {
public:
    bool canMeasureWater(int j1, int j2, int t) {
        if(j1+j2<t)return false;
        if(j1<j2)swap(j1,j2);
        queue<pair<int,int>> q;
        map<pair<int,int>,int> vis;
        q.push({0,0});
        while(!q.empty()){
            int s=q.size();
            while(s--){
                auto it=q.front();
                q.pop();
                int l=it.first,r=it.second;
                if(l+r==t || l==t || r==t)return true;
                if(vis[{l,r}])continue;
                vis[{l,r}]=1;
                q.push({0,j2});q.push({j1,0});
                if(l<=j2-r)q.push({0,min(j2,l+r)});
                else q.push({l-(j2-r),min(j2,l+r)});
                if(r<=j1-l)q.push({min(j1,l+r),0});
                else q.push({min(j2,l+r),r-(j1-l)});
                q.push({l,j2});q.push({j1,r});
            }
        }
        return false;
    }
};
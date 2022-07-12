class Solution {
public:
    bool sol(vector<int> &m,vector<bool> &vis,int tar,int s,int ind,int k){
        if(k==4)return true;
        if(s==tar)return sol(m,vis,tar,0,0,k+1);
        for(int i=ind;i<m.size();i++){
            if(vis[i] || s+m[i]>tar)continue;
            vis[i]=true;
            if(sol(m,vis,tar,s+m[i],i+1,k))return true;
            vis[i]=false;
        }
        return false;
    }
    bool makesquare(vector<int>& m) {
        int sum=0;
        for(int &i:m)sum+=i;
        if(m.size()<4 || sum%4>0)return false;
        vector<bool> vis(m.size(),false);
        return sol(m,vis,sum/4,0,0,1);
    }
};
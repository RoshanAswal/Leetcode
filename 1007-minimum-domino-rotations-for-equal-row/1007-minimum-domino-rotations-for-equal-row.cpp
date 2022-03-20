class Solution {
public:
    int sol(vector<int> &tops,vector<int> &bottoms){
        map<int,int> m;
        int mx=0,n=0;
        stack<int> inds;
        for(int i:tops)m[i]++;
        for(auto it:m){
            if(it.second>mx){
                mx=it.second;
                n=it.first;
            }
        }
        for(int i=0;i<tops.size();i++){
            if(tops[i]==n)inds.push(i);
        }
        int ans=0;
        for(int i=bottoms.size()-1;i>=0;i--){
            if(!inds.empty() && i==inds.top())inds.pop();
            else if(bottoms[i]!=n){
                return -1;
            }else ans++;
        }
        return ans;
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int f=sol(tops,bottoms);
        int s=sol(bottoms,tops);
        if(f==-1 && s==-1)return -1;
        else if(s==-1)return f;
        else if(f==-1)return s;
        return min(f,s);
    }
};
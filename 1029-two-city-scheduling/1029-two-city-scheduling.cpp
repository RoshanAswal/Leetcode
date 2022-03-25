class Solution {
public:
    static bool com(vector<int> &a,vector<int> &b){
        if(a[0]-a[1]<b[0]-b[1])return true;
        return false;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size()-1,ans=0;
        sort(costs.begin(),costs.end(),com);
        for(int i=0;i<costs.size()/2;i++)
            ans+=costs[i][0]+costs[n-i][1];
        return ans;
    }
};
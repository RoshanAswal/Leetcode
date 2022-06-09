class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        return a[0]<b[0];        
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int n=pairs.size();
        vector<int> dp(n+1,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0])
                    dp[i]=max(dp[i],dp[j]+1);                    
            }
        }
        return dp[n-1];
    }
};
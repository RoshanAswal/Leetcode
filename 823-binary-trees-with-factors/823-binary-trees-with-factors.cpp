class Solution {
public:
    int mod=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int ans=0;
        sort(arr.begin(),arr.end());
        map<int,long> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]=1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    m[arr[i]]=(m[arr[i]]+m[arr[j]]*m[arr[i]/arr[j]])%mod;
                }
            }
            ans=(ans+m[arr[i]])%mod;
        }
        return ans;
    }
};
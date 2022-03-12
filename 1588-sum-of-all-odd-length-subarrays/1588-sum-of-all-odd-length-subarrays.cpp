class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans=0,s=arr.size();
        for(int i=0;i<arr.size();i++){
            ans+=(((i+1)*(s-i)+1)/2)*arr[i];
        }
        return ans;
    }
};
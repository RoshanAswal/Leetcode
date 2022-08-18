class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> m;
        for(int &i:arr)m[i]++;
        vector<int> v;
        for(auto &it:m)v.push_back(it.second);
        sort(v.begin(),v.end());
        int num=arr.size(),ori=num,ans=0;
        for(int i=v.size()-1;i>=0;i--){
            if(num-v[i]<=ori/2)return ans+1;
            num-=v[i];
            ans++;
        }
        return ans;
    }
};
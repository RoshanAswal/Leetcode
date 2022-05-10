class Solution {
public:
    vector<vector<int>> ans;
    void sol(vector<int> &temp,int n,int t,int sum,int ind){
        if(sum==t && n==0){
            ans.push_back(temp);return;
        }
        if(sum>t)return;
        for(int i=ind;i<10;i++){
            if(temp.size()>0 && temp.back()>=i)continue;
            temp.push_back(i);
            sol(temp,n-1,t,sum+i,ind+1);                
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        int sum=0;
        sol(temp,k,n,sum,1);
        return ans;
    }
};
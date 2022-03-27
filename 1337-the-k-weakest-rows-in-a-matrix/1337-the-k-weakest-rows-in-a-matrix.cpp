class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m=mat.size(),n=mat[0].size();
        map<int,vector<int>> mp;
        for(int i=0;i<m;i++){
            int temp=0;
            for(int j=0;j<n;j++){
              if(mat[i][j]==0)break;
              temp++;
            }
            mp[temp].push_back(i);
        }
        auto it=mp.begin();
        vector<int> ans;
        while(it!=mp.end() && k){
            for(int i:it->second){
                if(!k)break;
                ans.push_back(i),k--;
            }
            it++;
        }
        return ans;
    }
};
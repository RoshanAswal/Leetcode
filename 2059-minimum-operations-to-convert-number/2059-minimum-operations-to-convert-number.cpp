class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int ans=0;
        queue<int> q;
        q.push(start);
        int vis[10005];
        memset(vis,0,sizeof(vis));
        while(!q.empty()){
            int s=q.size();
            while(s--){
                int n=q.front();
                q.pop();
                if(n==goal)return ans;
                if(n>1000 || n<0)continue;
                if(vis[n])continue;
                vis[n]=1;
                for(int &i:nums){
                    q.push(n-i);
                    q.push(n+i);
                    q.push(n^i);
                }
            }
            ans++;
        }
        return -1;
    }
};
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if(start==end)return 0;
        map<string,vector<string>> graph;
        bank.push_back(start);
        int n=bank.size();
        for(int j=0;j<n;j++){
            if(graph.count(bank[j]))continue;
            for(int i=0;i<n;i++){
                if(i==j)continue;
                int cnt=0;
                for(int k=0;k<bank[i].length();k++){
                    if(bank[j][k]!=bank[i][k])cnt++;
                    if(cnt>1)break;
                }
                if(cnt==1)graph[bank[j]].push_back(bank[i]);
            }
        }
        int ans=0,found=0;
        queue<string> q;
        map<string,int> vis;
        q.push(start);
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                string a=q.front();
                q.pop();
                if(a==end)return ans;
                if(vis[a]==1)continue;
                vis[a]=1;
                for(string &st:graph[a]){
                    if(vis[st]==0)
                        q.push(st);
                }
            }
            ans++;
        }
        return -1;
    }
};
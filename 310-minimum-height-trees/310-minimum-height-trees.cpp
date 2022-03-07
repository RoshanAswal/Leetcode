class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0)return {};
        if(n==1)return {0};
        vector<vector<int>> graph(n);
        vector<int> ed(n,0);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);    
            graph[edges[i][1]].push_back(edges[i][0]);    
            ed[edges[i][0]]++;
            ed[edges[i][1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(ed[i]==1)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int s=q.size();
            ans.clear();
            for(int i=0;i<s;i++){
                int n=q.front();
                q.pop();
                ans.push_back(n);
                for(auto x:graph[n]){
                    ed[x]--;
                    if(ed[x]==1)
                        q.push(x);
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m=matrix.size(),n=matrix[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        for(int i=0;i<m;i++)pq.push({matrix[i][0],i,0});
        int ans=matrix[0][0];
        for(int i=0;i<k;i++){
            vector<int> top=pq.top();pq.pop();
            ans=top[0];
            if(top[2]+1<n)pq.push({matrix[top[1]][top[2]+1],top[1],top[2]+1});
        }
        return ans;
    }
};
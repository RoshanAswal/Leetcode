class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row=matrix.size(),col=matrix[0].size();
        int arr[row][col];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                arr[i][j]=matrix[i][j];
            }
        }
        int ans=INT_MIN;
        for(int l=0;l<col;l++){
            int sum[row];
            memset(sum,0,sizeof(sum));
            for(int r=l;r<col;r++){
                for(int i=0;i<row;i++){
                    sum[i]+=arr[i][r];
                }
                set<int> s;
                s.insert(0);
                int currsum=0,temp=INT_MIN;
                for(int &i:sum){
                    currsum+=i;
                    set<int>::iterator it=s.lower_bound(currsum-k);
                    if(it!=s.end()){
                        temp=max(temp,currsum-*it);
                    }
                    s.insert(currsum);
                }
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};
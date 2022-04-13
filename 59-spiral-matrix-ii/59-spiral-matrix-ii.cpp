class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int num=1,r=0,c=0,l=0;
        vector<vector<int>> ans(n,vector<int>(n,0));
        while(num<=n*n){
            for(int i=c;i<n-l;i++)
                ans[r][i]=num++;
            r++;c=n-l-1;
            if(num>n*n)break;
            for(int i=r;i<n-l;i++)
                ans[i][c]=num++;
            r=n-l-1;c--;
            for(int i=c;i>=l;i--)
                ans[r][i]=num++;
            r--;c=l;l++;
            for(int i=r;i>=l;i--)
                ans[i][c]=num++;
            c++;r=l;
        }
        return ans;
    }
};
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size(),col=matrix[0].size();
        int f1=-1,f2=-1,s1=row,s2=-1,t1=row,t2=col,fo1=-1,fo2=col;
        while(1){
            f1++;f2++;s1--;s2++;t1--;t2--;fo1++;fo2--;
            int tf1=f1,tf2=f2,ts1=s1,ts2=s2,tt1=t1,tt2=t2,tfo1=fo1,tfo2=fo2;
            int cnt=s1-f1,cntt=cnt;
            while(cntt && tf1<row-1){
                swap(matrix[tf1][tf2],matrix[ts1][ts2]);
                swap(matrix[ts1][ts2],matrix[tt1][tt2]);
                swap(matrix[tt1][tt2],matrix[tfo1][tfo2]);
                tf1++;ts2++;
                tt1--;tfo2--;
                cntt--;
            }
            if(cnt<=1)break;
        }
        
    }
};
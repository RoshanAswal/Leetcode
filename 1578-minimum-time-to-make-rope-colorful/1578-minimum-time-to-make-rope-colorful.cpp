class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=neededTime.size();
        int temp=0,i=0;
        while(i<n){
            char c=colors[i];
            int res=INT_MIN,cnt=-1,tempsum=0;
            while(i<n && colors[i]==c){
                tempsum+=neededTime[i];
                res=max(res,neededTime[i++]);
                cnt++;
            }
            if(cnt)temp+=tempsum-res;
        }
        return temp;
    }
};
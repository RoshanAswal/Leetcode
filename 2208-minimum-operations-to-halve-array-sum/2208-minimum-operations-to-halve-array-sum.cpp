class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double ans=0;
        for(int i:nums){
            pq.push(i);
            ans+=i;            
        }
        int res=0;
        double temp=ans;
        while(temp>ans/2){
            double n=pq.top();
            temp-=n;
            pq.pop();
            temp+=n/2;
            pq.push(n/2);
            res++;
        }
        return res;
    }
};
class Solution {
public:
    bool isPossible(vector<int>& tar) {
        priority_queue<long> pq(tar.begin(),tar.end());
        long sum=0;
        for(int i=0;i<tar.size();i++)sum+=tar[i];
        while(pq.top()>1){
            long temp=pq.top();
            pq.pop();
            sum-=temp;
            if(temp==1 || sum==1)return true;
            if(sum>temp || sum==0 || temp%sum==0)return false;
            temp%=sum;
            sum+=temp;
            pq.push(temp);
        }
        return true;
    }
};
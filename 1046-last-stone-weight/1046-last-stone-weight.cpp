class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i:stones)pq.push(i);
        while(!pq.empty()){
            int f=pq.top();
            pq.pop();
            if(pq.empty())return f;
            int s=pq.top();
            pq.pop();
            if(f-s>0)pq.push(f-s);
        }
        return 0;
    }
};
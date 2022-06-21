class Solution {
public:
    int furthestBuilding(vector<int>& ar, int br, int lad) {
        priority_queue<int> qq;
        int i=1;
        for(;i<ar.size();i++){
            int req = ar[i] - ar[i-1];
            
            if(req<=0) continue;
            
            br-=req;
            qq.push(req);
            
            if(br<0){
                br+=qq.top();
                qq.pop();
                if(lad) lad--;
                else break;
            }
            
            
        }
        
        return i-1; 
        
        
    }
};
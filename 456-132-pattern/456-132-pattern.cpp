class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        
        stack<int> st;
        int mx=INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(mx>nums[i]) return 1;
            
            if(st.size()){
                
                while(st.size() && st.top()<nums[i]) { mx=max(mx,st.top()); st.pop();}
                
                // if(fl && st.size()>1) return 1;
                
            }
            st.push(nums[i]);
            
        }
        return 0;
        
        
    }
};
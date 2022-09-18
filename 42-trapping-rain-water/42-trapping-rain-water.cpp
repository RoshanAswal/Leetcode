class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<3)return 0;
        stack<int> st;
        int i=0,ans=0;
        while(i<height.size()){
           while(!st.empty() && height[st.top()]<height[i]){
               int top=st.top();
               st.pop();
               if(!st.size())break;
               
               int temp=min(height[i],height[st.top()])-height[top];
                int len=i-st.top()-1;
               ans+=temp*len;
           } 
            st.push(i++);
        }
        return ans;
    }
};
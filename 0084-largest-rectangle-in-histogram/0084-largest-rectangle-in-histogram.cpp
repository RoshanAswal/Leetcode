class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0,n=heights.size();
        stack<int> st;
        for(int i=0;i<=n;i++){
            int curr=-1;
            if(i<n)curr=heights[i];
            while(!st.empty() && heights[st.top()]>curr){
                int h=heights[st.top()];
                int l=-1;
                st.pop();
                if(!st.empty())l=st.top();
                int area=h*(i-l-1);
                ans=max(ans,area);
            }
            st.push(i);
        }
        return ans;
    }
};
class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[0]!=b[0])return a[0]<b[0];
        return a[1]>b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),cmp);
        stack<pair<int,int>> st;
        st.push({v[0][0],v[0][1]});
        int ans=0;
        for(int i=1;i<v.size();i++){
            if(st.top().first<v[i][0]){
                while(!st.empty() && st.top().first<v[i][0] && st.top().second<v[i][1]){
                    st.pop();ans++;
                }
            }
            st.push({v[i][0],v[i][1]});
        }
        pair<int,int> p=st.top();
        st.pop();
        while(!st.empty() && st.top().first<p.first && st.top().second<p.second){
            st.pop();ans++;
        }
        return ans;
    }
};
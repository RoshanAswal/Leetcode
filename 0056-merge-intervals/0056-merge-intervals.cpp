class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int i=0,n=intervals.size();
        vector<vector<int>> ans;
        while(i<n){
            vector<int> temp;
            int last=intervals[i][1];
            temp.push_back(intervals[i][0]);
            i++;
            while(i<n && last>=intervals[i][0]){
                last=max(intervals[i][1],last);
                i++;
            }
            temp.push_back(last);
            ans.push_back(temp);
        }
        return ans;
    }
};
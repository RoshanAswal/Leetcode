class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(),arr.end());
        int mindiff=100000,ind=0;
        for(int i=0;i<arr.size();i++){
            if(abs(arr[i]-x)<mindiff){
                mindiff=abs(arr[i]-x);
                ind=i;
            }
        }
        vector<int> ans;
        int l=ind,r=ind;
        while(k-- && (l>=0 || r<arr.size())){
            if(l==r){
                ans.push_back(arr[l]);
                l--;r++;
            }else{
                if(l>=0 && r<arr.size()){
                    if(abs(x-arr[l])>abs(x-arr[r]))
                        ans.push_back(arr[r++]);
                    else
                        ans.push_back(arr[l--]);
                }else if(l<0)ans.push_back(arr[r++]);
                else ans.push_back(arr[l--]);
            } 
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
#define ll long long
#define f(a,b) for(int i=a;i<b;i++)
#define f2(x,a,b) for(int x=a;x<b;x++)
#define fr(b,a) for(int i=b;i>=a;i--)
#define fit(nums) for(auto &it:nums)
#define v vector
#define pb push_back
#define ppb pop_back
#define p priority_queue
#define um unordered_map
#define us unordered_set
#define TN TreeNode
#define LN ListNode
#define endl "\n"
class Solution {
public:
    int fq(v<int>v1,v<int>v2){
        f(0,26)if(v1[i]!=v2[i])return 0;
        return 1;
    }
    vector<int> findAnagrams(string s, string p) {
        if(size(p)>size(s))return {};
        v<int>v1(26,0),v2(26,0),ans;
        um<char,int>um1;
        f(0,size(p)){
            um1[p[i]]=1;
            v1[p[i]-'a']++;
            v2[s[i]-'a']++;
        }
        if(fq(v1,v2))ans.pb(0);
        f(size(p),size(s)){
            v2[s[i]-'a']++;
            v2[s[i-size(p)]-'a']--;
            if(um1.count(s[i])!=0 && fq(v1,v2))ans.pb(i-size(p)+1);
        }
        return ans;
    }
};
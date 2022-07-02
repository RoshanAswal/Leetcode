class Solution {
public:
    int maxArea(int h, int w, vector<int>& hori, vector<int>& verti) {
        hori.push_back(h);verti.push_back(w);
        sort(hori.begin(),hori.end());
        sort(verti.begin(),verti.end());
        int l=hori[0],r=verti[0],mod=1e9+7;
        for(int i=1;i<hori.size();i++){
            l=max(l,hori[i]-hori[i-1]);
        }
        for(int i=1;i<verti.size();i++){
            r=max(r,verti[i]-verti[i-1]);
        }
        return 1LL*(l%mod)*(r%mod)%mod;
    }
};
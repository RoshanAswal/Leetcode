class Solution {
public:
    int countCollisions(string dir) {
        int l=0,r=dir.length()-1;
        int ans=0;
        while(l<dir.length() && dir[l]=='L')l++;
        while(r>l && dir[r]=='R')r--;
        if(l>=r)return ans;
        r=l+1;
        while(r<dir.length()){
            if(dir[l]=='R' && dir[r]=='L')ans+=2;
            else if(dir[l]=='S' && dir[r]=='L')ans++;
            else if(dir[l]=='R' && dir[r]=='S')ans++;
            else if(dir[l]=='R' && dir[l]==dir[r]){
                while(r<dir.length() && dir[r]=='R')r++;
                if(r>=dir.length())return ans;
                if(dir[r]=='S')ans+=(r-l);
                else ans+=(r-l)+1;
                dir[r]='S';
                l=r;
                r=l+1;
                continue;
            }
            dir[l]='S';
            if(dir[r]!='R')
                dir[r]='S';
            l++;r++;
        }
        return ans;
    }
};
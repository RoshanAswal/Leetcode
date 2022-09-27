class Solution {
public:
    string pushDominoes(string dom) {
        vector<int> v;   
        for(char &c:dom){
            if(c=='.')v.push_back(0);
            if(c=='L')v.push_back(-1);
            if(c=='R')v.push_back(1);
        }
        vector<int> v1(v.begin(),v.end());
        vector<int> v2(v.begin(),v.end());
        int prev=0;
        for(int i=0;i<v.size();i++){
            if(v1[i]==0 && prev==1)v1[i]=1;
            if(v1[i]==1)prev=1;
            if(v1[i]<0)prev=0;
        }
        prev=0;
        for(int i=v.size()-1;i>=0;i--){
            if(v2[i]==0 && prev==-1)v2[i]=-1;
            if(v2[i]==-1)prev=-1;
            if(v2[i]>0)prev=0;
        }
        for(int i=0;i<dom.length();i++){
            if(!v1[i] && !v2[i])v[i]=5;
            else v[i]=v1[i]+v2[i];   
        }
        map<int,int> m;
        for(int i=0;i<v.size();i++){
            int ind=i;
            if(v[i]!=0){
                if(v[i]==5)dom[i]='.';
                else if(v[i]>0)dom[i]='R';
                else dom[i]='L';
            }
            while(ind>0 && ind<v.size() && !v[ind])ind++;
            if(ind<v.size() && ind!=i){
                m[i]=ind-1;i=ind;
            }
        }
        for(auto it:m){
            int l=it.first,r=it.second;
            while(l<=r){
                if(l==r)dom[l]='.';
                else{
                    dom[l]='R';
                    dom[r]='L';
                }
                l++;r--;
            }
        }
        return dom;
    }
};
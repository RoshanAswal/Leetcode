class Solution {
public:
    string pushDominoes(string dom) {
        map<int,int> m;
        int i=0;
        while(i<dom.size()){
            if(dom[i]=='R'){
                i++;
                int ind=i;
                while(i<dom.size() && dom[i]=='.')i++;
                if(i<dom.size() && dom[i]=='L')m[ind]=i-1;
            }else i++;
        }
        i=dom.size()-1;
        while(i>=0){
            if(!m.count(i) && dom[i]=='L'){
                i--;
                while(i>=0 && dom[i]=='.'){
                    dom[i]='L';i--;
                }
            }else i--;
        }
        i=0;
        while(i<dom.size()){
            if(!m.count(i) && dom[i]=='R'){
                i++;
                while(i<dom.size() && dom[i]=='.'){
                    dom[i]='R';i++;
                }
            }else i++;
        }
        for(auto &it:m){
            int l=it.first,r=it.second;
            while(l<=r){
                if(l==r)dom[l]='.';
                else{
                    dom[l]='R';dom[r]='L';
                }
                l++;r--;
            }
        }
        return dom;
    }
};
class KthLargest {
public:
    vector<int> temp;
    int t;
    KthLargest(int k, vector<int>& nums) {
        temp=nums;
        sort(temp.begin(),temp.end());
        t=k;
    }
    
    int add(int val) {
        int i=temp.size();
        if(i==0 || temp[i-1]<val)temp.push_back(val);
        else{
            temp.push_back(temp[i-1]);
            i--;
            while(i-1>=0 && temp[i-1]>=val){
                temp[i]=temp[i-1];
                i--;
            }       
            temp[i]=val;
        }
        if(t>temp.size())return temp[temp.size()-1];
        return temp[temp.size()-t];
    }
};

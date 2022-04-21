class MyHashSet {
public:
    vector<int> temp;
    int n=0;
    MyHashSet() {
    }
    void add(int key) {
        if(n==0 || n==temp.size())temp.push_back(key);
        else temp[n]=key;
        n++;
        int l=n-2;
        while(l>=0 && temp[l]>key){
            temp[l+1]=temp[l];
            l--;
        }
        temp[l+1]=key;
    }
    void remove(int key) {
        if(n==0)return;
        int s=0,i=0;
        for(;i<n;i++){
            if(temp[i]==key){
                s=i;break;
            }
        }
        while(i<n && temp[i]==key)i++;
        while(i<n && i!=s){
            temp[s]=temp[i];
            s++;i++;
        }
        if(s>0)n=s;
    }
    bool contains(int key) {
        for(int i=0;i<n;i++){
            if(temp[i]==key)return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
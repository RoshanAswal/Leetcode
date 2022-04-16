class ATM {
public:
    vector<long long> temp;
    ATM() {
        for(int i=0;i<5;i++)
            temp.push_back(0);
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0;i<5;i++)
            temp[i]+=banknotesCount[i];
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ans(5);
        long long notes[5]={20,50,100,200,500};
        for(int i=4;i>=0;i--){
            ans[i]=min(temp[i],amount/notes[i]);
            amount-=(ans[i]*notes[i]);
        }
        if(amount)
            return {-1};
        for(int i=0;i<5;i++)temp[i]-=ans[i];
        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
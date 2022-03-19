class FreqStack {
public:
    map<int,stack<int>> ms;
    map<int,int> m;
    int mx=0;
    FreqStack() {
        //
    }
    void push(int val) {
        m[val]++;
        ms[m[val]].push(val);
        mx=max(mx,m[val]);
    }
    int pop() {
        int n=ms[mx].top();
        ms[mx].pop();
        if(ms[mx].empty())mx--;
        m[n]--;
        return n;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
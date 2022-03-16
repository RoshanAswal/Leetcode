class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i=0;
        for(int n:pushed){
            s.push(n);
            while(!s.empty() && popped[i]==s.top()){
                i++;
                s.pop();
            }
        }
        return s.empty();
    }
};
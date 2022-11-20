class Solution {
public:
    int eval(stack<string> &st,int temp=0){
        string a=st.top();
        st.pop();
        if(st.top()=="(")return stoi(a);
        string op=st.top();
        st.pop();
        if(st.top()=="("){
            if(op=="-")return -1*(stoi(a));
        }
        string b=st.top();
        st.pop();
        int num1=stoi(a);
        int num2=stoi(b);
        int sign=1;
        if(!st.empty() && st.top()!="("){
            if(st.top()=="-")sign=-1;
            st.pop();
        }
        num2*=sign;
        if(op=="+")temp+=(num2+num1);
        else if(op=="-")temp+=(num2-num1);
        else if(op=="*")temp+=(num2*num1);
        else if(op=="/")temp+=(num2/num1);  
        return temp;
    }
    int calculate(string s) {
        stack<string> st;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]==' ')continue;
            if(s[i]>='0' && s[i]<='9'){
                string num;
                while(i<n && s[i]>='0' && s[i]<='9')num+=s[i++];
                i--;
                st.push(num);
            }else if(s[i]==')'){
                int temp=0;
                while(1){
                    temp=eval(st);
                    if(st.top()!="(")
                        st.push("+");
                    else{
                        st.pop();
                        st.push(to_string(temp));
                        break;
                    }
                    st.push(to_string(temp));
                }
            }else{
                string str(1,s[i]);
                st.push(str);
            }
        }
        int ans=0;
        while(!st.empty() && st.size()>2){
            ans+=eval(st);
        }
        if(!st.empty() && st.size()<3){
            string a=st.top();
            int temp=stoi(a);
            st.pop();
            if(!st.empty() && st.top()=="-")temp*=-1;
            ans+=temp;
        }
        return ans;
    }
};
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        map<char,string> m;
        m['a']=".-";
        m['b']="-...";
        m['c']="-.-.";
        m['d']="-..";
        m['e']=".";
        m['f']="..-.";
        m['g']="--.";
        m['h']="....";
        m['i']="..";
        m['j']=".---";
        m['k']="-.-";
        m['l']=".-..";
        m['m']="--";
        m['n']="-.";
        m['o']="---";
        m['p']=".--.";
        m['q']="--.-";
        m['r']=".-.";
        m['s']="...";
        m['t']="-";
        m['u']="..-";
        m['v']="...-";
        m['w']=".--";
        m['x']="-..-";
        m['y']="-.--";
        m['z']="--..";
        unordered_set<string> m2;
        for(int i=0;i<words.size();i++){
            string temp;
            for(char &c:words[i]){
                temp+=m[c];
            }
            m2.insert(temp);
        }
        return m2.size();
    }
};
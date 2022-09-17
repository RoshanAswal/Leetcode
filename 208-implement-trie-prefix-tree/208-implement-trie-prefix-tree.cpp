class Trie {
private:
    struct node{
        node *nodes[26];
        bool ends=false;
        bool present(int i){return !(nodes[i]==NULL);}
        void add(int i,node *t){nodes[i]=t;}
    };  
    node *root;
public:
    Trie() {
        root=new node();
    }
    void insert(string s) {
        node* temp=root;
        for(int i=0;i<s.length();i++){
            if(temp->present(s[i]-'a')==false){
                temp->add(s[i]-'a',new node());
            }
            temp=temp->nodes[s[i]-'a'];
        }
        temp->ends=true;
    }
    bool search(string s) {
        node *temp=root;
        for(int i=0;i<s.length();i++){
            if(!temp->present(s[i]-'a'))return false;
            temp=temp->nodes[s[i]-'a'];
        }
        return temp->ends;
    }
    
    bool startsWith(string s) {
        node *temp=root;
        for(int i=0;i<s.length();i++){
            if(!temp->present(s[i]-'a'))return false;
            temp=temp->nodes[s[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
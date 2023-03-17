class Trie {
public:
    vector<string> st;
    Trie() {
        
    }
    
    void insert(string word) {
        st.push_back(word);
    }
    
    bool search(string word) {
        for(auto x : st) if(x == word) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        for(auto x : st){
            if(x.substr(0, prefix.size()) == prefix) return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
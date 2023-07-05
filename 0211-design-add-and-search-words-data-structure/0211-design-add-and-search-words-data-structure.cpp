class WordDictionary {
public:
    class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        
        TrieNode(char ch){
            data = ch;
            for(int i=0;i<26;i++) children[i] = NULL;
            isTerminal = false;
        }
    };
    
    class Trie{
    public:
        TrieNode* root;
        
        Trie(){
            root = new TrieNode('\0');
        }
        
        void AddWord(string s){
            addUtil(root, s);
        }
        
        void addUtil(TrieNode* root, string s){
            if(s.size() == 0){
                root-> isTerminal = true;
                return;
            }

            TrieNode* child;
            int index = s[0]-'a';

            if(root-> children[index]!=NULL){
                child = root-> children[index];
            }
            else{
                child = new TrieNode(s[0]);
                root-> children[index] = child;
            }

            addUtil(child, s.substr(1));
        }

        bool searchWord(string s){
            return searchUtil(root, s);
        }
        
        bool searchUtil(TrieNode* root, string s){
            if(s.size() == 0){
                return root-> isTerminal;
            }
            
            if(s[0]!='.'){
                TrieNode* child;
                int index = s[0]-'a';
                
                if(root-> children[index]!=NULL){
                    child = root-> children[index];
                }
                else{
                    return false;
                }
                
                return searchUtil(child, s.substr(1));
            }
            else{
                bool ans = false;
                TrieNode* child;
                for(int i=0;i<26;i++){
                    if(root-> children[i] != NULL){
                        child = root-> children[i];
                        ans |= searchUtil(child, s.substr(1));
                    }
                }
                
                return ans;
            }
        }
    };
    
    Trie* t;
    WordDictionary() {
        t = new Trie();
    }
    
    void addWord(string word) {
        t-> AddWord(word);
    }
    
    bool search(string word) {
        return t-> searchWord(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
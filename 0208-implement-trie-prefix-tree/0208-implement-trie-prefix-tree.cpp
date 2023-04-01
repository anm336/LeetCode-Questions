struct Node{
    Node* links[26];
    //26 further nodes from this point for each alphabet
    bool flag = false;
    //flag to determine whehther thid node is end node
    
    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }
    
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    
    Node* getNext(char ch){
        return links[ch - 'a'];
    }
    
    void setEnd(){
        flag = true;
    }   
};

class Trie {
private: Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string words) {
        Node* node = root;
        for(int i=0;i<words.size();i++){
            if(!node-> containsKey(words[i])){
                node -> put(words[i], new Node());
            }
            //moves to reference trie
            node = node-> getNext(words[i]);
        }
        //set end of word
        node -> setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node-> containsKey(word[i])){
                return false;
                break;
            }
            else node = node-> getNext(word[i]); 
        }
        return node-> flag == true;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0;i<prefix.size();i++){
            if(!node-> containsKey(prefix[i])){
                return false;
                break;
            }
            else node = node-> getNext(prefix[i]); 
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
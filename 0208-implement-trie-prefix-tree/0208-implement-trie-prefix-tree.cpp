class Trie {
public:
    bool is_leaf;
    Trie* children[26];
    /** Initialize your data structure here. */
    Trie() {
        this->is_leaf = false;
        for(int i=0;i<26;i++)
            this->children[i] = NULL;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root = this;
        for (int i=0;i<word.length();i++)
        {
            int index = word[i] - 'a';
            if (root->children[index] == NULL)
                root->children[index] = new Trie();
            root = root->children[index];
        }
        root->is_leaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (this == NULL)
            return false;
        Trie* root = this;
        for(int i=0;i<word.length();i++)
        {
            int index = word[i] - 'a';
            root = root->children[index];
            if (root == NULL)
                return false;
        }
        if (root->is_leaf)
            return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (this == NULL)
            return false;
        Trie* root = this;
        for(int i=0;i<prefix.length();i++)
        {
            int index = prefix[i] - 'a';
            root = root->children[index];
            if (root == NULL)
                return false;
        }
        return true;
    }
};
class Node{
public:    
    Node* next[26];
    int num;
    Node(){
        num = 0;
        for(int i=0;i<26;i++)
            next[i] = NULL;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *p = root;
        for(int i = 0;i < word.length();i++)
        {
            if(p->next[word[i]-'a']==NULL)
                p->next[word[i]-'a'] = new Node;
            p = p->next[word[i]-'a'];
        }
        p->num++;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *p = root;
        for(int i = 0;i < word.length();i++)
        {
            if(p->next[word[i]-'a'] == NULL)
                return false;
            p = p->next[word[i]-'a'];
        }
        if(p->num!=0)
            return true;
        else
            return false;

    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *p = root;
        for(int i = 0 ;i < prefix.length();i++)
        {
            if(p->next[prefix[i]-'a'] == NULL)
                return false;
            p = p->next[prefix[i]-'a'];
        }
        return true;
    }
};
/*https://leetcode.com/problems/implement-trie-prefix-tree
git@Pedro-Mendes*/


/*Map search insertion and delete: O(logn)
So if word size is M, O(M*Logn) for all of them for time complexity
Space complexity = O(M) for insert*/
class Trie {
private:
    map<char, Trie*> letters = {};
    bool isWord = false;

    bool searchImproved(string word, bool prefixSearch) {
        Trie* child = this;        
        for (int i = 0; i < word.length(); i++) {
            if (child->letters[word[i]]) {
                child = child->letters[word[i]];
            } else {
                return false;
            }
        }
        return child->isWord || prefixSearch;
    }
public:
    Trie() {}
    
    void insert(string word) {
        Trie* child = this;
        for (int i = 0; i < word.length(); i++) {
            if (!child->letters[word[i]]) {
                child->letters[word[i]] = new Trie ();
            }
            child = child->letters[word[i]];
        }
        child->isWord = true;
    }
    bool search(string word) { return searchImproved(word, false); }
    bool startsWith(string word) { return searchImproved(word, true); }

};
#include <string>
#include <vector>
using namespace std;

class TrieNode
{
  public:
    bool is_word;
    vector<TrieNode*> sons;
    TrieNode()
    {
        int i;
        sons.resize(26); // assume all the chars are lower-case alphabatic
        for (i = 0; i < 26; i++)
            sons[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    vector<Trie> sons;
    
    // string word; (optional)

    Trie() {
        // do intialization if necessary
        root = new TrieNode;
    }

    /*
     * @param word: a word
     * @return: nothing
     */
    void insert(string &word) {
        // write your code here
        int n = word.size();

        TrieNode* cur = root;
        for (int i = 0; i < n; i++)
        {
            if (cur->sons[word[i]-'a'] == nullptr)
                cur->sons[word[i]-'a'] = new TrieNode;
            cur = cur->sons[word[i]-'a'];
        }
        cur->is_word = true;
    }

    /*
     * @param word: A string
     * @return: if the word is in the trie.
     */
    bool search(string &word) {
        // write your code here
        int n = word.size();

        TrieNode* cur = root;
        for (int i = 0; i < n; i++)
        {
            if (cur->sons[word[i]-'a'] == nullptr)
                return false;
            cur = cur->sons[word[i]-'a'];
        }

        if (cur == nullptr || cur->is_word == false)
            return false;
        return true;
    }

    /*
     * @param prefix: A string
     * @return: if there is any word in the trie that starts with the given prefix.
     */
    bool startsWith(string &prefix) {
        // write your code here
        int n = prefix.size();

        TrieNode* cur = root;
        for (int i = 0; i < n; i++)
        {
            if (cur->sons[prefix[i]-'a'] == nullptr)
                return false;
            cur = cur->sons[prefix[i]-'a'];
        }
        if (cur == nullptr)
            return false;
        return true;
    }
};
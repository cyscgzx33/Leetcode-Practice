#include <string>
#include <vector>

using namespace std;

class TrieNode
{
  public:
    vector<TrieNode*> sons;
    bool is_word;

    TrieNode()
    {
        sons.resize(26); // assume all the chars are lower-case alphabatic
        for (int i = 0; i < 26; i++)
            sons[i] = nullptr;
        is_word = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;
public:
    WordDictionary()
    {
        root = new TrieNode;
    }

    /*
     * @param word: Adds a word into the data structure.
     * @return: nothing
     */
    void addWord(string &word) {
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

    bool find(string& word, int index, TrieNode* cur)
    {
        if (index == word.size())
            return cur->is_word;
        
        if (word[index] == '.')
        {
            // have to try every non-empty son
            for (int i = 0; i < 26; i++)
            {
                if (cur->sons[i] != nullptr)
                {
                    if (find(word, index+1, cur->sons[i]))
                        return true;
                    // Note: even it fails to find here, wait for the next
                    //       trial; only after all the trials fail, return false 
                }
            }
            return false;
        }
        else
        {
            if (cur->sons[word[index]-'a'] == nullptr)
                return false;
            else
                return find(word, index+1, cur->sons[word[index]-'a']);
        }
    }

    /*
     * @param word: A word could contain the dot character '.' to represent any one letter.
     * @return: if the word is in the data structure.
     */
    bool search(string &word) {
        // write your code here

        return find(word, 0, root);
    }
};
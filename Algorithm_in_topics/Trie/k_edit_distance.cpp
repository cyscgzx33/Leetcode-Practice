#include <vector>
#include <string>

using namespace std;

class TrieNode
{
  public:
    vector<TrieNode*> sons;
    bool is_word;
    string word;

    TrieNode() : sons(26, nullptr), is_word(false) {}

    void insert(string word)
    {
        TrieNode* curr = this;
        for (int i = 0; i < word.size(); i++)
        {
            if (curr->sons[word[i]-'a'] == nullptr)
                curr->sons[word[i]-'a'] = new TrieNode();
            curr = curr->sons[word[i]-'a'];
        }

        curr->is_word = true;
        curr->word = word;
    }
};

class Solution {
public:
    TrieNode* root;      // must init later
    vector<string> res;
    
    void dfs(TrieNode* p, vector<int> dp, string& target, int n, int k)
    {
        if (p->is_word == true && dp[n] <= k)
            res.push_back(p->word);

        for (int c = 0; c < 26; c++)
        {
            if (p->sons[c] == nullptr)
                continue;
            vector<int> dp_new(n + 1, 0);

            // For the dp update, the order is essentially important!
            // Case A: if update within one loop, the order is SUGGESTED;
            // CASE B: if update within multiple loops, the order is NECESSARY!
            // Thus, maybe update with one loop is a good idea.
            // 
            // Illustration:
            // 
            // Op-II/III   Op-I
            //          \   |
            // Op-IV  ---  Curr

            for (int i = 0; i <= n; i++)
            {
                // Option I: delete
                dp_new[i] = dp[i] + 1;
                if (i == 0)
                    continue;
                
                // Option II: replace
                dp_new[i] = min(dp_new[i], dp[i-1] + 1);

                // Option III: same
                //
                // Illustration:
                //     p   ("sp": prefix-s)
                //     |
                //     c
                //     |
                //   p.sons[c]   ("sp" + "c")
                if (c + 'a' == target[i-1])
                    dp_new[i] = min(dp_new[i], dp[i-1]);

                // Option IV: insert
                dp_new[i] = min(dp_new[i], dp_new[i-1] + 1);
            }

            dfs(p->sons[c], dp_new, target, n, k);
        }
    }
    /**
     * @param words: a set of stirngs
     * @param target: a target string
     * @param k: An integer
     * @return: output all the strings that meet the requirements
     */
    vector<string> kDistance(vector<string> &words, string &target, int k) {
        int n = target.size();
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n + 1; i++)
            dp[i] = i;

        root = new TrieNode(); // initialization is necessary here
                               // otherwise it's only declared without assigning memory allocation
        for (auto word : words)
            root->insert(word);
        dfs(root, dp, target, n, k);
        return res;
    }
};
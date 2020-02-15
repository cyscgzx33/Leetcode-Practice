#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class TrieNode
{
  public:
    vector<TrieNode*> sons;
    bool is_word;
    string word;

    TrieNode() : is_word(false), word(""), sons(vector<TrieNode*>(26, nullptr)) {}
};

class Solution {
  private:
    TrieNode* root;

  public:
    void dfs(TrieNode* p, vector<int>& dp, vector<string>& res, string& target, int k)
    {
        int n = target.size();
        if (p->is_word == true && dp[n] <= k)
            res.push_back(p->word);


        //     p    (prev) = "sp"
        //     |
        //     c    (curr) = "c"
        //     |
        //  p.sons[c]     ==> "sp" + "c"

        vector<int> dp_next(n+1, 0);
        for (int c = 0; c < 26; c++)
        {
            if (p->sons[c] == nullptr)
                continue;
            
            /* discuss how the tail of target is matched */

            /* style I */
            // Important Note: order is VERY important! 
            //                 IF ITERATE LINE BY LINE: HAVE TO LOOK AT TOP THEN SAME LEVEL!

            // // method 1: cut the tail of source (look at top)
            // for (int i = 0; i <= n; i++)
            //     dp_next[i] = dp[i] + 1;
            // // method 3: change the tail of source to the one of target (look at top-left)
            // for (int i = 1; i <= n; i++)
            //     dp_next[i] = min(dp_next[i], dp[i-1] + 1);
            
            // // method 4: the tail of source is the same as the one of target (look at top-left w/ condition)
            // // method 2: add the tail of target into source (look at left)
            // for (int i = 1; i <= n; i++)
            // {
            //     if (target[i-1] - 'a' == c)
            //         dp_next[i] = min(dp_next[i], dp[i-1]);
            //     dp_next[i] = min(dp_next[i], dp_next[i-1] + 1);
            // }
            
            /* style II ( <==> style I ) */ 

            // initialization: recall that in the 1D problem: dp[0][0...i] = i, dp[0...i][0] = i 
            dp_next[0] = dp[0] + 1;

            for (int i = 1; i <= n; i++)
            {
                dp_next[i] = min(dp[i] + 1, dp_next[i-1] + 1); // method 1 : method 2
                dp_next[i] = min(dp[i-1] + 1, dp_next[i]);     // method 3 : min(method 1, 2)
                if (target[i-1] - 'a' == c)
                    dp_next[i] = min(dp[i-1], dp_next[i]);     // method 4 : min(method 1, 2, 3)
            }

            dfs(p->sons[c], dp_next, res, target, k);
        }
    }

    void insert(TrieNode* p, string word)
    {
        for (int i = 0; i < word.size(); i++)
        {
            int c = word[i];
            if (p->sons[c-'a'] == nullptr)
                p->sons[c-'a'] = new TrieNode;
            p = p->sons[c-'a'];
        }
        p->is_word = true;
        p->word = word;
    }
    /**
     * @param words: a set of stirngs
     * @param target: a target string
     * @param k: An integer
     * @return: output all the strings that meet the requirements
     */
    vector<string> kDistance(vector<string> &words, string &target, int k) {
        root = new TrieNode;
        for (auto word : words)
            insert(root, word);
        
        int n = target.size();
        vector<string> res;

        // using sliding array to optimize the result
        // as each time calling the dfs, inside of it we don't need more than 2 dp's
        vector<int> dp(n + 1, 0);
        for (int i = 0; i <= n; i++)
            dp[i] = i;
        
        dfs(root, dp, res, target, k);

        return res;
    }
};
class Solution {
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    string alienOrder(vector<string> &words) {
        map<char, vector<char>> edges; // edges in graph: prev char -> next char
        map<char, int> indegrees;
        int n = words.size();

        /* Step I: construct the graph */

        // I-(a):
        // loop all the chars in the given words to assign edge space and indegrees
        // tedious, but very useful to corner cases avoidance in next steps
        for (auto word : words)
        {
            for (auto c : word)
            {
                edges[c] = vector<char>{};
                indegrees[c] = 0;
            }
        }

        // I-(b):
        // contruct edges
        for (int i = 0; i < n - 1; i++)
        {
            string word1 = words[i];
            string word2 = words[i+1];
            int n1 = word1.size();
            int n2 = word2.size();

            // remove a corner case: e.g,  word1 = "abc", word2 = "ab"
            if (n1 > n2 && word1.find(word2) != string::npos)
                return "";

            // start iteration and construct edges
            int n_min = min(n1, n2);
            for (int j = 0; j < n_min; j++)
            {
                if (word1[j] != word2[j])
                {
                    edges[word1[j]].push_back(word2[j]);
                    indegrees[word2[j]]++;
                    break;
                }
            }
        }
        
        /* Step II: topological sort */
        
        // Note: as the Lintcode needs the min alphabatical order: 
        // need to use set to sort, instead of queue
        
        // II-(a):
        // collect all the nodes with 0 indegree
        set<char> q;
        for (auto it = indegrees.begin(); it != indegrees.end(); it++)
        {
            if (it->second == 0)
                q.insert(it->first);
        }

        // II-(b):
        // BFS and construct the final res
        string res = "";
        while (q.size() > 0)
        {
            char curr = *(q.begin());
            q.erase(q.begin());

            res.push_back(curr);

            for (char child : edges[curr])
            {
                if (--indegrees[child] == 0)
                    q.insert(child);
            }
        }

        return res.size() < edges.size() ? "" : res;
    }
};
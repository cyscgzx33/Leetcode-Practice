class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // init source
        std::vector<std::unordered_set<int>> source( n, std::unordered_set<int>{} );
        for (auto& edge : edges)
        {
            source[ edge[0] ].insert( edge[1] );
            source[ edge[1] ].insert( edge[0] );
        }

        // init rebuilt (result)
        std::unordered_set<int> rebuilt{ {0} };

        // init queue
        std::queue<int> q{ {0} };
        while (q.size() > 0)
        {
            int cur = q.front();
            q.pop();

            for ( auto src : source[cur] )
            {
                if (rebuilt.count(src) > 0) // already visited
                    return false;
                rebuilt.insert(src);
                q.push(src);
                source[src].erase(cur);
            }
        }

        return rebuilt.size() == n;
    }
};
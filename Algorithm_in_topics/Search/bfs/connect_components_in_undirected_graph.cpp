/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

/* A bfs method (find another union_find in solution in the union_find folder) */
class Solution {
public:
    /*
     * @param nodes: a array of Undirected graph node
     * @return: a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*> nodes) {
        unordered_set<UndirectedGraphNode*> visited;
        vector<vector<int>> res;

        for (auto curr_node : nodes)
        {
            if (visited.count(curr_node) > 0)
                continue;

            vector<int> island;
            queue<UndirectedGraphNode*> q({curr_node});
            visited.insert(curr_node);

            while (q.size() > 0)
            {
                auto front_node = q.front();
                q.pop();

                // process front_node's label
                island.push_back(front_node->label);

                // process front_node's neighbors
                for (auto nb : front_node->neighbors)
                {
                    if (visited.count(nb) > 0)
                        continue;

                    visited.insert(nb);
                    q.push(nb);
                }
            }
            
            // Notice:
            // Nodes in a connected component should sort by label in ascending order;
            // Different connected components can be in any order.
            sort(island.begin(), island.end());

            res.push_back(island);
        }

        return res;
    }
};
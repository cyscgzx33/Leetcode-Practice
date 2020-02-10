/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */


class Solution {
public:
    /*
     * @param graph: a list of Undirected graph node
     * @param values: a hash mapping, <UndirectedGraphNode, (int)value>
     * @param node: an Undirected graph node
     * @param target: An integer
     * @return: a node
     */
     UndirectedGraphNode* searchNode(vector<UndirectedGraphNode*>& graph,
                                    map<UndirectedGraphNode*, int>& values,
                                    UndirectedGraphNode* node,
                                    int target) {
        std::unordered_set<UndirectedGraphNode*> visit{ {node} };
        std::queue<UndirectedGraphNode*> q{ {node} };

        while (q.size() > 0)
        {
            UndirectedGraphNode* cur = q.front();
            q.pop();
            if (values[cur] == target)
                return cur;

            for (auto& nb : cur->neighbors)
            {
                if (visit.count(nb) > 0)
                    continue;
                q.push(nb);
                visit.insert(nb);
            }

        }

        return nullptr;
    }
};
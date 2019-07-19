/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        // write your code here
        if ( graph.empty() ) return std::vector<DirectedGraphNode*>{};
        
        std::vector<DirectedGraphNode*> res;
        DirectedGraphNode* start_node = graph[0];
        std::queue<DirectedGraphNode*> q;
        q.push(start_node);
        std::unordered_map<DirectedGraphNode*, int> count_indegree;

        // count the indegree first
        for (auto& graph_node : graph) count_indegree[graph_node]++;
        

        while ( !q.empty() ) {
        	DirectedGraphNode* cur_node = q.front();
        	q.pop();

        	for (auto& neighbor : cur_node->neighbors) {

        	}
        }

    }
};
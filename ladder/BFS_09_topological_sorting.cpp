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
        std::unordered_map<DirectedGraphNode*, int> count_indegree;

        // count the indegree first
        for (auto& graph_node : graph) {
        	for (auto& neighbor : graph_node->neighbors) {
        		count_indegree[neighbor]++;
        	}
        }

        // find the indegree val equals to 0 ones, 
        // assign the as start nodes by pushing into the queue
        std::queue<DirectedGraphNode*> q;
        for (auto& graph_node : graph) {
        	if (count_indegree.count(graph_node) == 0) q.push(graph_node);
        }

        while ( !q.empty() ) {
        	DirectedGraphNode* cur_node = q.front();
        	q.pop();
        	res.push_back(cur_node);

        	for (auto& neighbor : cur_node->neighbors) {
        	    // NOTE: VERY INPORTANT!
        	    // WHY INDEGREE == 0 MEANS IT SHOULD BE ADDED INTO SORTED RESULT?
        		if (--count_indegree[neighbor] == 0) {// it's guaranteed that it would not be 0 before --
        			q.push(neighbor);
        		}
        	}
        }

        return res;

    }
};
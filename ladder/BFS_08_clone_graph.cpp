// Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors. Nodes are labeled uniquely.

// You need to return a deep copied graph, which has the same structure as the original graph, 
// and any changes to the new graph will not have any effect on the original graph.

// Example
// Example1

// Input:
// {1,2,4#2,1,4#4,1,2}
// Output: 
// {1,2,4#2,1,4#4,1,2}
// Explanation:
// 1------2  
//  \     |  
//   \    |  
//    \   |  
//     \  |  
//       4   
// Clarification
// How we serialize an undirected graph: http://www.lintcode.com/help/graph/

// Notice
// You need return the node with the same label as the input node.


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

/* Method I: use two queues, plus one map, memory exceeded */

class Solution {
public:
    /*
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        // write your code here

        UndirectedGraphNode* cloned_node = new UndirectedGraphNode(node->label);


        std::unordered_map<UndirectedGraphNode*, bool> is_visited;
        is_visited[node] = true;

        std::queue<UndirectedGraphNode*> q_original, q_cloned;
        q_original.push(node);
        q_cloned.push(cloned_node);

        while ( !q.empty() ) {
        	UndirectedGraphNode* cur_original_node = q_original.front();
        	UndirectedGraphNode* cur_cloned_node = q_cloned.front();
        	q_original.pop();
        	q_cloned.pop();
        	for (auto& original_neighbor_node : cur_original_node->neighbors) {
        		if ( is_visited.find(original_neighbor_node) == is_visited.end() ) {// not found
        			UndirectedGraphNode* cloned_neighbor_node = new UndirectedGraphNode(original_neighbor_node->val);
        			cur_cloned_node->neighbors.push_back(cloned_neighbor_node);
        			q_original.push(original_neighbor_node);
        			q_cloned.push(cloned_neighbor_node);
        		}
        	}        	
        }

        return cloned_node;

    }
};

/* Method II: use one queue, plus one map, AC */

class Solution {
public:
    /*
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        // write your code here
    	if (!node) return NULL;

        UndirectedGraphNode* cloned_node = new UndirectedGraphNode(node->label);
        std::unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> original_2_cloned;
        original_2_cloned[node] = cloned_node;

        std::queue<UndirectedGraphNode*> q;
        q.push(node);

        while ( !q.empty() ) {
        	UndirectedGraphNode* cur_original_node = q.front();
        	UndirectedGraphNode* cur_cloned_node = original_2_cloned[cur_original_node];
        	q.pop();
        	for (auto& original_neighbor_node : cur_original_node->neighbors) {
        		if ( original_2_cloned.find(original_neighbor_node) == original_2_cloned.end() ) {// not found
        																						  // or: if (original_2_cloned.count(original_neighbor_node) > 0)
        			UndirectedGraphNode* cloned_neighbor_node = new UndirectedGraphNode(original_neighbor_node->label);
        			cur_cloned_node->neighbors.push_back(cloned_neighbor_node);
        			q.push(original_neighbor_node);
        			original_2_cloned[original_neighbor_node] = cloned_neighbor_node;
        		} else { // although the node is cloned, the boundary still needs to be cloned
        		    cur_cloned_node->neighbors.push_back( original_2_cloned[original_neighbor_node] );
        		}
        	}        	
        }

        return cloned_node;

    }
};
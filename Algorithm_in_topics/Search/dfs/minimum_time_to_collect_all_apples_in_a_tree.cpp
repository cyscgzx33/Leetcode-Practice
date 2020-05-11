class Solution {
public:
    int getDist(int node, unordered_map<int, vector<int>>& node_map, vector<bool>& hasApple)
    {
        int res = 0;
        for (auto nb : node_map[node])
            res += getDist(nb, node_map, hasApple);
        
        if (node == 0) // special case for root
            return res;
        else if (res == 0 && hasApple[node] == false)
            return 0;
        else
            return res + 2;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {        
        unordered_map<int, vector<int>> node_map;
        for (auto edge : edges)
        {
            int in_node = edge[0];
            int out_node = edge[1];
            if (node_map.count(in_node) == 0)
                node_map.insert( { in_node, {} } );
            node_map[in_node].push_back(out_node);
        }
        return getDist(0, node_map, hasApple);
    }
};
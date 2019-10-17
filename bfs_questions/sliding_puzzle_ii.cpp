class Solution {
public:
    /**
     * @param init_state: the initial state of chessboard
     * @param final_state: the final state of chessboard
     * @return: return an integer, denote the number of minimum moving
     */
	std::vector<std::vector<int>> next_indices = {
		{1, 3},
		{0, 2, 4},
		{1, 5},
		{0, 4, 6},
		{1, 3, 5, 7},
		{2, 4, 8},
		{3, 7},
		{4, 6, 8},
		{5, 7}
	};

    int minMoveStep(vector<vector<int>> &init_state, vector<vector<int>> &final_state) {
        if (init_state == final_state)
        	return 0;

        // # write your code here
        std::string begin = "";
        for (auto row : init_state)
        	for (auto elem : row)
        		begin += std::to_string(elem);

        std::string end = "";
        for (auto row : final_state)
        	for (auto elem : row)
        		end += std::to_string(elem);

        std::unordered_set<std::string> visit{ {begin} };
        std::queue<std::string> q{ {begin} };
        int step = 0;

        while (q.size() > 0)
        {
        	int sz = q.size();
        	for (int i = 0; i < sz; i++)
        	{
        		auto cur_node = q.front();
        		q.pop();
        		if (cur_node == end)
        			return step;
        		int zero_idx = (int)cur_node.find('0');
        		for ( auto next_index : next_indices[zero_idx] )
        		{
        			std::string candidate = cur_node;
        			std::swap( candidate[zero_idx], candidate[next_index] );
        			if (visit.count(candidate) > 0)
        				continue;
        			visit.insert(candidate);
        			q.push(candidate);
        		}
        	}

        	step++;
        }

        return -1;

    }
};
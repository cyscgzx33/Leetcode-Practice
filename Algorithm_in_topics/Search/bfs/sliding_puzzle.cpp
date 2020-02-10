class Solution {
public:
    std::vector<std::vector<int>> next_indices = {
                                                    {1, 3},
                                                    {0, 2, 4},
                                                    {1, 5},
                                                    {0, 4},
                                                    {1, 3, 5},
                                                    {2, 4}
                                                 };
    std::string target = "123450";
    int slidingPuzzle(vector<vector<int>>& board) {
        // init start node
        std::string start = "";
        for (auto row : board)
            for (auto elem : row)
                start += std::to_string(elem);

        if (start == target)
            return 0;

        std::unordered_set<std::string> visit{ {start} };
        std::queue<std::string> q{ {start} };
        int step = 0;
        while (q.size() > 0)
        {
            int sz = q.size();

            for (int i = 0; i < sz; i++)
            {
                auto cur_node = q.front();
                q.pop();
                if (cur_node == target)
                    return step;

                int zero_idx = (int)cur_node.find("0");
                for ( auto next_index : next_indices[zero_idx] )
                {
                    auto candidate = cur_node;
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
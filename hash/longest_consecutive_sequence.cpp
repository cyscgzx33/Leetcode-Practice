class Solution {
public:
    /**
     * @param num: A list of integers
     * @return: An integer
     */
    int longestConsecutive(vector<int> &num) {
        // write your code here
        std::unordered_set<int> num_set( num.begin(), num.end() );

        int res = 1;
        for (auto val : num)
        {
        	if (num_set.count(val) == 0)
        		continue;
        	
        	/* find range [prev, next] */
        	int prev = val - 1;
        	while (num_set.count(prev) > 0)
        	{
        		num_set.erase(prev);
        		prev--;
        	}
        	int next = val + 1;
        	while (num_set.count(next) > 0)
        	{
        		num_set.erase(next);
        		next++;
        	}

        	// update res
        	res = max(res, next - prev + 1);
        }

        return res;
    }
};
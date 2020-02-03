class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: An integer
     */
    int jump(vector<int> &A) {
        // write your code here
        int last_reach = 0, cur_reach = 0, cur_pos = 0, steps_count = 0;
        
        while (cur_reach < n - 1) // must not reach the destination
        {
        	steps_count++;
        	last_reach = cur_reach;
        	for (; cur_pos <= last_reach; cur_pos++)
        		cur_reach = max(cur_pos + A[cur_pos], cur_reach);
        	if (last_reach == cur_reach)
        		return -1;
        }

        return steps_count;
    }
};
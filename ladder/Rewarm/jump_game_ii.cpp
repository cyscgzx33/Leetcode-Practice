class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: An integer
     */
    int jump(vector<int> &A) {
        if (A.size() == 0)
            return 0;
        int prev_range = 0, cur_range = 0, cur_pos = 0;
        int steps = 0;

        while (cur_range < A.size() - 1) // haven't reached the last pos
        {
            prev_range = cur_range;
            for (; cur_pos <= prev_range; cur_pos++)
            {
                cur_range = max(cur_range, cur_pos + A[cur_pos]);
            }
            steps++;
        }

        return steps;
    }
};
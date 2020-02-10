
/** [M3 (Stack, monotonic decreasing stack)]
 *
 *  Only store smaller or equal bounds, every time a larger bound
 *  shows up, use while loop to fill up previous lower bound based 
 *  on distance & bounded height
 *
 */

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0)
            return 0;

        std::stack<int> stk;
        int water = 0;

        for (int i = 0; i < height.size(); i++)
        {
            while ( stk.size() > 0 && height[ stk.top() ] < height[i] )
            {
                int top_idx = stk.top();
                stk.pop();

                // important check
                if (stk.size() == 0)
                    break;

                // start to count water volume
                int dist = i - stk.top() - 1;
                int bounded_hgt = min(height[i], height[ stk.top() ]) - height[top_idx];

                water += dist * bounded_hgt;
            }

            stk.push(i);
        }

        return water;
    }
};
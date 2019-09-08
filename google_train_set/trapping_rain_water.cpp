class Solution {
public:
    int trap(vector<int>& height) {
        
        // approach 1: brute force
        int res = 0;

        for (int i = 0; i < height.size(); i++)
        {   
            int cur_hgt = height[i];
            int left_max = cur_hgt, right_max = cur_hgt;
            for (int j = i + 1; j < height.size(); j++)
            {
                if ( height[j] > right_max )
                    right_max = height[j];
            }

            for (int j = 0; j < i; j++)
            {
                if ( height[j] > left_max )
                    left_max = height[j];
            }

            res += (min(left_max, right_max) - height[i]);
        }
        

        return res;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        if ( height.size() == 0 )
            return 0;

        // approach 2: dp
        // memorize the possible right_max & left_max at each iteration you could find
        // stores the information into right_max[i] and left_max[i]
        int res = 0;
        int n = height.size();

        std::vector<int> left_max(n, 0);
        left_max[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            if ( height[i] > left_max[i-1] )
                left_max[i] = height[i];
            else
                left_max[i] = left_max[i-1]; 
        }

        std::vector<int> right_max(n, 0);
        right_max[n-1] = height[n-1];
        for (int i = n - 2; i >= 0; i--)
        {
            if ( height[i] > right_max[i+1] )
                right_max[i] = height[i];
            else
                right_max[i] = right_max[i+1];
        }

        for (int i = 0; i < n; i++)
            res += min( right_max[i], left_max[i] ) - height[i];

        return res;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        if ( height.size() == 0 )
            return 0;

        // approach 3: stack
        
        int res = 0;
        std::stack<int> stk_idx;
        for (int i = 0; i < height.size(); i++)
        {
            while ( stk_idx.size() > 0 && height[i] > height[ stk_idx.top() ] )
            {
                int idx_top = stk_idx.top();
                stk_idx.pop();
                if (stk_idx.size() == 0)
                    break;
                int dist = i - stk_idx.top() - 1;
                res += dist * ( min( height[i], stk_idx.top() ) - height[idx_top] );
            }
            std::cout << "i = " << i << " , res = " << res << std::endl;
            stk_idx.push(i);
        }

        return res;
    }
};
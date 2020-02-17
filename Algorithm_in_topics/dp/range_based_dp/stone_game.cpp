#include <vector>
#include <algorithm>

using namespace std;

/* Method 1: create a dp table directly */

class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int stoneGame(vector<int> &A) {
        // write your code here
        
        if (A.size() == 0)
            return 0;
        
        // dp[i][j] means the minimum efforts to arrange stones in [i, j]
        int sz = A.size();

        // init the dp vector
        // by definition, dp[i][i] = 0
        std::vector<std::vector<int>> dp( sz, std::vector<int>(sz, INT_MAX) );
        for (int i = 0; i < sz; i++)
            dp[i][i] = 0;

        // format the pfsum vector first for reference
        // definition: pfsum[i] = pfsum[i-1] + A[i-1]    for any i > 0
        //             pfsum[i] = 0				         for i = 0
        // note: in a word, pfsum[i] sums up elements within [0, i)
        std::vector<int> pfsum(sz + 1, 0);
        for (int i = 1; i <= sz; i++)
        	pfsum[i] = pfsum[i-1] + A[i-1];

        // format the upper part of the dp matrix (since i <= j must be maintained, we don't care about lower part)
        // the initial state transition formula is: dp[i][j] = min_{ for any k in [i, j) } ( dp[i][k], dp[k+1][j] ) + sum[i][j]
        for (int i = sz - 1; i >= 0; i--)
        {
        	for (int j = i + 1; j < sz; j++)
        	{
                for (int k = i; k < j; k++) // as we have to access dp[k+1][j], so k < j
                    dp[i][j] = min( dp[i][j], dp[i][k] + dp[k+1][j] + pfsum[j+1] - pfsum[i] );
        	}
        }

        return dp[0][sz - 1];
    }
};

/* rewarm of method 1 */
class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int stoneGame(vector<int> &A) {
        if (A.size() == 0)
            return 0;

        int n = A.size();
        
        // construct pfsum: pfsum[0] = 0, pfsum[i+1] = pfsum[i] + A[i] (i >= 0)
        std::vector<int> pfsum(n + 1, 0);
        for (int i = 0; i < n; i++)
            pfsum[i+1] = pfsum[i] + A[i];

        // init dp: dp[i][j] means minimum efforts to move stones in [i, j]
        // every diagnal elem should be 0
        std::vector<std::vector<int>> dp( n, std::vector<int>(n, INT_MAX) );
        for (int i = 0; i < n; i++)
            dp[i][i] = 0;

        // start iterating dp
        // note: the starting length from [i, j] must be 2 (or 1, but NOT n)
        for (int j = 0; j < n; j++)
        {
            for (int i = j; i >= 0; i--)
            {
                for (int k = i; k < j; k++)
                    dp[i][j] = min( dp[i][j], dp[i][k] + dp[k+1][j] + ( pfsum[j+1] - pfsum[i] ) );
            }
        }

        return dp[0][n-1];
    }
};

/* Method 2: use memoization */
class Solution {
private:
	int memoizedSearch(int start, int end, 
					   std::vector<int>& A,
					   std::vector<std::vector<int>>& dp,
					   std::vector<int>& pfsum)
	{
		if (start >= end)
			return 0;
		if (start + 1 == end) // for a valid i: dp[i][i+1] = sum[i][i+1]
			return A[start] + A[end];
		if (dp[start][end] != 0)
			return dp[start][end];

		int min_val = INT_MAX;
		for (int i = start; i < end; i++)
		{
			// just equivalent to: dp[start][i] + dp[i+1][end] + sum[start][end]
			int cost = memoizedSearch(start, i, A, dp, pfsum) + memoizedSearch(i + 1, end, A, dp, pfsum) 
					 + pfsum[end+1] - pfsum[start];
			min_val = min(min_val, cost);
		}

		dp[start][end] = min_val;
		return min_val;
	}

public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int stoneGame(vector<int> &A) {
        // write your code here
        
        if (A.size() == 0)
            return 0;
        
        // dp[i][j] means the minimum efforts to arrange stones in [i, j]
        int sz = A.size();

        // init the dp vector
        // by definition, dp[i][i] = 0
        // since here we init everything to 0, we don't need to process it
        std::vector<std::vector<int>> dp( sz, std::vector<int>(sz, 0) );

        // format the pfsum vector first for reference
        // definition: pfsum[i] = pfsum[i-1] + A[i-1]    for any i > 0
        //             pfsum[i] = 0				         for i = 0
        // note: in a word, pfsum[i] sums up elements within [0, i)
        std::vector<int> pfsum(sz + 1, 0);
        for (int i = 1; i <= sz; i++)
        	pfsum[i] = pfsum[i-1] + A[i-1];

        return memoizedSearch(0, sz-1, A, dp, pfsum);
    }
};


/* rewarm of method 1 */
class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int stoneGame(vector<int> &A) {
        int n = A.size();
        if (n == 0)
            return 0;
        
        vector<vector<int>> dp(n, vector<int>(n, 0x3f3f3f3f));

        // construct pfsum vector
        vector<int> pfsum(n+1, 0);
        for (int i = 0; i <= n; i++)
            pfsum[i+1] = pfsum[i] + A[i];

        // init: dp[i][i] = 0: by definition (no need to move, since only one cluster left) 
        // dp[i][i+1] = sum[i, i+1]: by definition (most basic step, move two clusters to one)
        for (int i = 0; i < n; i++)
            dp[i][i] = 0;
        for (int i = 0; i < n-1; i++)
            dp[i][i+1] = pfsum[i+2] - pfsum[i];
        
        // state transition function: dp[i][j] = sum[i, j] + min {i<=k<j} (dp[i][k] + dp[k+1][j])
        // main loop: first priority is l, following by i and j, then k
        for (int l = 2; l <= n; l++)
        {
            for (int i = 0; i < n; i++)
            {
                int j = i + l - 1;
                if (j >= n)
                    continue;
                for (int k = i; k < j; k++)
                    dp[i][j] = min(dp[i][j], pfsum[j+1] - pfsum[i] + dp[i][k] + dp[k+1][j]);
            }
        }

        return dp[0][n-1];
    }
};
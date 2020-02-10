/* method 1-1: binary search thru col */
class Solution {
public:
	int findPeak1d(vector<vector<int>>& A, int c)
	{
		int i = 0;
		for (int j = 0; j < A.size(); j++)
		{
			if (A[j][c] > A[i][c])
				i = j;
		}

		return i;
	}
    /*
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int>> &A) {
    	if (A.size() == 0 || A[0].size() == 0)
    		return {};
        int m = A.size(), n = A[0].size();

        int l = 1, r = n - 2;
        while (l + 1 < r)
        {
        	int mid = (r + l) / 2;
        	int max_r = findPeak1d(A, mid);

        	if (A[max_r][mid] > A[max_r][mid-1] && A[max_r][mid] > A[max_r][mid+1])
        		return {max_r, mid};
        	else if (A[max_r][mid] <= A[max_r][mid-1])
        		r = mid;
        	else
        		l = mid;
        }

        int max_r_l = findPeak1d(A, l);
        if (A[max_r_l][l] > A[max_r_l][l-1] && A[max_r_l][l] > A[max_r_l][l+1])
        	return {max_r_l, l};
       	else
       		return {findPeak1d(A, r), r};
    }
};


/* method 1-2: binary search thru row */
class Solution {
public:
    int findPeakCol(int r, vector<vector<int>>& A)
    {
        int c = 0;
        for (int i = 0; i < A[r].size(); i++)
        {
            if (A[r][i] > A[r][c])
                c = i;
        }
        
        return c;
    }
    /*
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int>> &A) {
        int m = A.size(), n = A[0].size();
        
        int u = 1, d = m - 2;

        while (u + 1 < d)
        {
        	int mid = (u + d) / 2;
        	int max_c = findPeakCol(mid, A);
        	if (A[mid-1][max_c] >= A[mid][max_c])
        		d = mid;
        	else if (A[mid+1][max_c] >= A[mid][max_c])
        		u = mid;
        	else
        		return {mid, max_c};
        }

        int max_c_u = findPeakCol(u, A);
        if (A[u-1][max_c_u] < A[u][max_c_u] && A[u+1][max_c_u] < A[u][max_c_u])
        	return {u, max_c_u};
        else
        	return {d, findPeakCol(d, A)};
    }
};
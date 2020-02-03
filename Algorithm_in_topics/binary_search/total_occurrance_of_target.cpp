class Solution {
public:

    int searchFristIdx(std::vector<int>& A, int target)
    {
    	int start = 0, end = A.size() - 1;

    	while (start + 1 < end)
    	{
    		int mid = start + (end - start) / 2;
    		if (A[mid] < target)
    			start = mid;
    		else
    			end = mid;
    	}

    	if (A[start] == target)
    		return start;
    	else if (A[end] == target)
    		return end;
    	else
    		return -1;
    }

    int searchLastIdx(std::vector<int>& A, int target)
    {
    	int start = 0, end = A.size() - 1;

    	while (start + 1 < end)
    	{
    		int mid = start + (end - start) / 2;
    		if (A[mid] <= target)
    			start = mid;
    		else
    			end = mid;
    	}

    	if (A[end] == target)
    		return end;
    	else if (A[start] == target)
    		return start;
    	else
    		return -1;
    }
    /**
     * @param A: A an integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
     
    int totalOccurrence(vector<int> &A, int target) {
        // write your code here
        if (A.size() == 0)
            return 0;
        int first_idx = searchFristIdx(A, target);
        int last_idx  = searchLastIdx(A, target);

        if (first_idx == -1 || last_idx == -1)
        	return 0;
        else
        	return last_idx - first_idx + 1;
    }
};
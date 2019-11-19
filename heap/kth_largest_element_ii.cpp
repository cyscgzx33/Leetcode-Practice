class Solution {
public:
    /**
     * @param nums: an integer unsorted array
     * @param k: an integer from 1 to n
     * @return: the kth largest element
     */
    int kthLargestElement2(vector<int> &nums, int k) {
        // write your code here

    	/* as N >> K, we have to maintain a min-heap, TC = O(NlogK) */
    	std::priority_queue< int, std::vector<int>, greater<int> > pq; // min-heap

    	for (auto num : nums)
    	{
    		if (pq.size() == k)
    		{
    			if (pq.top() < num)
    			{
    				pq.pop();
    				pq.push(num);
    			}
    		}
    		else
    			pq.push(num);
    	}

    	return pq.top();
    }
};
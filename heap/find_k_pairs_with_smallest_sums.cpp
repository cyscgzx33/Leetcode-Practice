class Comparator
{
public:
	bool operator() (const std::pair<std::pair<int, int>>& a, const std::pair<std::pair<int, int>>& b)
	{
		return a.first > b.first;
	}
}

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        

        int sz1 = nums1.size();
        int sz2 = nums2.size();

        int m = 0, n = 0;
        int cnt = 1; // suppose k is 1-based
        std::priority_queue<std::pair<std::pair<int, int>>, std::vector<std::pair<std::pair<int, int>>>,  Comparator> pq;
        pq.push_back( { num1[0] + nums2[0], {0, 0} } );
        while (cnt <= k)
        {
        	auto curr = pq.top();
        	int val = curr.first;
        	int x = curr.second.first;
        	int y = curr.second.second;
        }
    }
};
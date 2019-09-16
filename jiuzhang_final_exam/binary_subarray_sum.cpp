int numSubarrayWithSum(vector<int>& A, int S)
{
	std::vector<int> pf_sum(A.size() + 1, 0); // pf_sum[k + 1] = A[0] + A[1] + ... + A[k]
	std::unordered_map<int, int> pf_sum_cnt;  // key:pf_sum, val:cnt
	std::vector<int> cnt(A.size(), 0);        // cnt[i] indicates how many subarrays ending with i would satisfy the requirement
	pf_sum_cnt[0] = 1;

	int res = 0;
	for (int i = 0; i < A.size(); i++)
	{
		pf_sum[i + 1] = pf_sum[i] + A[i];

		// for each pf_sum[i + 1], count how many position k such that pf_sum[i + 1] - pf_sum[k] = S
		int target = pf_sum[i + 1] - S;
		if (pf_sum_cnt.count(target) > 0)
			cnt[i] = pf_sum_cnt[target];
		else
			cnt[i] = 0;

		pf_sum_cnt[ pf_sum[i + 1] ]++;
		res += cnt[i];
	}

	return res;
}
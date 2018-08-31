class Solution{
private:
	void backtrack(vector<vector<int>>& res, vector<int>& temp, vector<int> nums, vector<bool>& isVisit){
		if (temp.size() == nums.size()){
			res.push_back(temp);
			return;
		}

		for (int i = 0; i < nums.size(); i++) {
			// little bit treaky, because nums[i] == nums[i-1] must be satisfied,
			// and i > 0 otherwise you might have segmentation error
			
			// Here comes the critical point:
			// !isVisit[i-1] makes sure when you try second time,
			// you don't want to use the duplicate element again
			// think about eg. [1, 1, 2]
			// when you try to use the second 1 (nums[1]) as the first element in res,
			// the algorithm will deny it by continuing it, which makes sense. 
			if (isVisit[i] || i > 0 && !isVisit[i-1] && nums[i] == nums[i-1]) continue;
			isVisit[i] = true;
			temp.push_back(nums[i]);
			backtrack(res, temp, nums, isVisit);
			temp.pop_back();
			isVisit[i] = false;
		}
	}
public:
	vector<vector<int>> permuteUnique(vector<int> nums){
		vector<bool> isVisit(nums.size(), false);
		vector<int> temp;
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		backtrack(res, temp, nums, isVisit);

		return res;
	}
};
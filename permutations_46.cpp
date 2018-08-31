class Solution{
private:
	void backtrack(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, vector<bool>& isVisit){
		if (temp.size() == nums.size()) {
			res.push_back(temp);
			return;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (isVisit[i]) continue;
			isVisit[i] = true;
			temp.push_back(nums[i]);
			backtrack(res, temp, nums, isVisit);
			// attension: after a specific number is finished counting, 
			// one need to pop it out, and set the flag isVisit to flase
			isVisit[i] = false;
			temp.pop_back();
		}
	}
public:
	vector<vector<int>> permute(vector<int> nums){
		vector<bool> isVisit(nums.size(), false);
		vector<vector<int>> res;
		vector<int> temp;
		backtrack(res, temp, nums, isVisit);
		return res;
	}
}
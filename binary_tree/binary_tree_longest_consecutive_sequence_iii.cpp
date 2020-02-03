#include <algorithm>
#include <vector>
//Definition for a multi tree node.
struct MultiTreeNode {
    int val;
    std::vector<MultiTreeNode*> children;
    MultiTreeNode(int x) : val(x) {}
};


class ResultType
{
  public:
    int max_len;
	int max_incr_len;
	int max_decr_len;

	ResultType(int max_l, int max_i_l, int max_d_l) :
			   max_len(max_l),
			   max_incr_len(max_i_l),
			   max_decr_len(max_d_l) 
			   {}
};

class Solution {
public:
	ResultType helper(MultiTreeNode* root)
	{
		if (root == nullptr)
			return ResultType(0, 0, 0);
		
		int incr = 0, decr = 0;
		int max_len = 0;
		/* loop thru all the children and update incr, decr and max_len */
		for (auto cd : root->children)
		{
			auto cd_RT = helper(cd);
			/* case I: incr */
			if (cd && cd->val == root->val + 1)
				incr = std::max(incr, cd_RT.max_incr_len);

			/* case II: decr */
			if (cd && cd->val == root->val - 1)
				decr = std::max(decr, cd_RT.max_decr_len);

			/* update max_len */
			max_len = std::max(max_len, cd_RT.max_len);
		}

		max_len = std::max(max_len, incr + 1 + decr);

		return ResultType(max_len, incr + 1, decr + 1);
	}
    /**
     * @param root the root of k-ary tree
     * @return the length of the longest consecutive sequence path
     */
    int longestConsecutive3(MultiTreeNode* root) {
        // Write your code here
		auto res = helper(root);

		return res.max_len;
    }
};

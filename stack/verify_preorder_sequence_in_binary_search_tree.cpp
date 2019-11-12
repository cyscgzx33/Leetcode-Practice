class Solution {
public:
	bool traverse(std::vector<int>& preorder,
				  int idx,
				  std::stack<int>& dec_stk)
	{
		if ( idx >= preorder.size() )
			return true;
		if ( dec_stk.size() == 0 || preorder[idx] < dec_stk.top() )
			dec_stk.push( preorder[idx] ); // formualte a decreasing sequence inside of the stack
		else
		{	
			int parent = 0;
			while ( dec_stk.size() > 0 && preorder[idx] > dec_stk.top() ) // kick out every non-decreasing element, and
																		  // memorize the most recent one as parent
			{
				parent = dec_stk.top();
				dec_stk.pop();
			}
			if ( idx + 1 < preorder.size() && preorder[idx + 1] <= parent )
				return false;
		}

		return traverse(preorder, idx + 1, dec_stk);
	}
    /**
     * @param preorder: List[int]
     * @return: return a boolean
     */
    bool verifyPreorder(vector<int> &preorder) {
        // write your code here
    	std::stack<int> dec_stk;
    	return traverse(preorder, 0, dec_stk);
    }
};
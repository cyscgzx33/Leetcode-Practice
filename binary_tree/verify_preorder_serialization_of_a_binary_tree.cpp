class Solution {
private:
	bool traverse(std::string& preorder, int& idx)
	{
		if ( idx >= preorder.size() )
			return false;
		if ( preorder[idx] == '#' )
		{
			idx += 2;
			return true;
		}

		while (idx < preorder.size() && preorder[idx] <= '9' && preorder[idx] >= '0')
			idx++;

		if (idx < preorder.size() && preorder[idx] == ',')
			idx++;

		bool left = traverse(preorder, idx);
		bool right = traverse(preorder, idx);

		return left && right;
	}
public:
    /**
     * @param preorder: a string
     * @return: return a bool
     */
    bool isValidSerialization(string &preorder) {
        // write your code here
        int idx = 0;
        bool valid = traverse(preorder, idx);

        return valid && idx >= preorder.size();
    }
};
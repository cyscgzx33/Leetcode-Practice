class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here
        std::sort(S.begin(), S.end());
        
    	//  for 循环最大边的位置 i，接下来的任务就是在 
	    //  0~i-1 之间找到两数之和 > S[i]
	    int cnt = 0;
    	for (int i = 2; i < S.size(); i++)
    	{
    		int left = 0, right = i - 1;
    		while (left < right)
    		{
    			if ( S[left] + S[right] > S[i] ) // any comb ending with right would work
    			{
    				cnt += (right - left); 
    				right--;
    			}	
    			else // any comb starting with left would NOT work
    			{
    				left++;
    			}
    		}
    	}

    	return cnt;
    }
};
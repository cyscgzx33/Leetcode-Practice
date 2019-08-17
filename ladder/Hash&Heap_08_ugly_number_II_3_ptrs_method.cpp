class Solution {
public:
    /**
     * @param n: An integer
     * @return: return a  integer as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        int *ugly_nums = new int[n];
        ugly_nums[0] = 1;
        int next = 1;
        int* p2 = ugly_nums;
        int* p3 = ugly_nums;
        int* p5 = ugly_nums;
        while (next < n) {
        	int m = min( min(*p2 * 2, *p3 * 3), *p5 * 5 );
        	ugly_nums[next] = m;
        	while ( *p2 * 2 <= ugly_nums[next] ) p2++;
        	while ( *p3 * 3 <= ugly_nums[next] ) p3++;
        	while ( *p5 * 5 <= ugly_nums[next] ) p5++;
        	next++;
        }
        int ugly_num = ugly_nums[n - 1];
        delete[] ugly_nums;
        return ugly_num;
    }
};
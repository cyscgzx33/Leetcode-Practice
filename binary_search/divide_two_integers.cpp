class Solution {
public:
    /**
     * @param dividend: the dividend
     * @param divisor: the divisor
     * @return: the result
     */


	long ldivide(long ldividend, long ldivisor)
	{
		if (ldividend < ldivisor)
			return 0;
		long sum = ldivisor;
		long multiple = 1;
		while (sum + sum <= ldividend) // using "<=" will save some space
		{
			sum += sum;
			multiple += multiple;
		}

		return multiple + ldivide(ldividend - sum, ldivisor);
	}

	/**
	 * 1. +/-
	 * 2. 0
	 * 3. overflow
	 * 
	 */
    int divide(int dividend, int divisor) {
        // write your code here
    	int sign = 1;
    	if (dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0)
    		sign = -1;

    	long ldividend = abs( (long)dividend );
    	long ldivisor  = abs( (long)divisor );

    	if (ldividend < ldivisor || ldividend == 0)
    		return 0;

    	long lres = ldivide(ldividend, ldivisor);
    	int res = 0;
    	if (lres > INT_MAX)
    		res = (sign == 1) ? INT_MAX : INT_MIN;
    	else
    		res = (int)( sign * lres );

    	return res;
    }
};
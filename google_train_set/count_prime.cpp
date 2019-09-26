class Solution {
public:
    int countPrimes(int n) {
        /* Sieve of Eratosthenes */
        if (n <= 2)
        	return 0;

        int res = 0;
        std::vector<bool> is_prime(n, true);
        for (int i = 2; i < n; i++)
        {
        	if (is_prime[i] == false)
        		continue;
        	res++;
        	for (int j = 2; i * j < n; j++)
        		is_prime[i * j] = false;
        }

        return res;
    }
};


























class Solution {
public:
    /**
     * @param n: a integer
     * @return: return a integer
     */
    int countPrimes(int n) {
        /* Sieve of Eratosthenes */
        if (n <= 2)
            return 0;
        
        int res = 0;
        std::vector<bool> not_prime(n, false);
        
        for (int i = 2; i < n; i++) {
            if (notPrime[i] == false) {
                res++;
                for (int j = 2; i * j < n; j++)
                    notPrime[i * j] = true;
            }
        }
        
        return res;
    }
};
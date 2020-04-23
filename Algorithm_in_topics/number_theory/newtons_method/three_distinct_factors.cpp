class Solution {
public:
    /**
     * @param n: the given number
     * @return:  return true if it has exactly three distinct factors, otherwise false
     */
    
    long long getSqrt(long long n)
    {
        long long x = x < n ? pow(10, 9) : n; // as n coule be as large as pow(10, 18)
        long long x_last = 0;
        long long thres = 1; // according to Wikipedia, thres = 1 is the LARGEST choice for stopping criteria

        while (abs(x - x_last) >= thres)
        {
            x_last = x;
            x = (x_last + n / x_last) / 2;
            
            // check the Wikipedia as referece: https://en.wikipedia.org/wiki/Integer_square_root
            if (x_last == x - 1)
            {
                x = x_last; // take the smaller one as root
                break;
            }
        }

        return pow(x, 2) == n ? x : -1;
    }
    
    // another method using double type as intermediate value
    long long getSqrtByDouble(long long n)
    {
        double x = pow(10, 9) < n ? pow(10, 9) : n; // as n coule be as large as pow(10, 18)
        double x_last = 0;
        double thres = 1; // according to Wikipedia, thres = 1 is the LARGEST choice for stopping criteria

        while (abs(x - x_last) >= thres)
        {
            x_last = x;
            x = (x_last + n / x_last) / 2;
        }
        long long x_floor = floor(x); // why do we choose floor() here? check the Readme.md outside
        return pow(x_floor, 2) == n ? x_floor : -1;
    }

    bool isPrime(long long n)
    {
        if (n == -1)
            return false;

        for (long long i = 2; i <= n / i; i++)
        {
            if (n % i == 0)
                return false;
        }
        
        return true;
    }

    bool isThreeDisctFactors(long long n) {
        long long factor = getSqrt(n);
        if(factor*factor != n) 
            return false;
        return isPrime(factor);
    }
};
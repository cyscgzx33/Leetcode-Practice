/**
 * 1374. Generate a String With Characters That Have Odd Counts
Given an integer n, return a string with n characters such that each character in such string occurs an odd number of times.
The returned string must contain only lowercase English letters. If there are multiples valid strings, return any of them.  
*/


class Solution {
public:
    string generateTheString(int n) {
        int num1 = 0, num2 = 0, num3 = 0;
        if (n == 1)
            return "a";
        else if (n == 2)
        {
            num1 = 1;
            num2 = 1;
        }
        else if (n == 3)
        {
            num1 = 1;
            num2 = 1;
            num3 = 1;
        }
        else if (n % 2 == 0)
        {    
            int half = n / 2;
            if (half % 2 == 0)
            {
                num1 = n / 2 - 1;
                num2 = n / 2 + 1;
            }
            else
            {
                num1 = n / 2;
                num2 = n / 2;
            }   
        }
        else // n % 2 != 0
        {
            num1 = 1;
            int new_n = n - 1;
            int half = new_n / 2;
            if (half % 2 == 0)
            {
                num2 = new_n / 2 - 1;
                num3 = new_n / 2 + 1;
            }
            else
            {
                num2 = new_n / 2;
                num3 = new_n / 2;
            }   
        }
        
        string res = "";
        for (int i = 0; i < num1; i++)
            res.push_back('a');
        
        for (int i = 0; i < num2; i++)
            res.push_back('b');
        
        for (int i = 0; i < num3; i++)
            res.push_back('c');
        
        
        return res;
    }
};
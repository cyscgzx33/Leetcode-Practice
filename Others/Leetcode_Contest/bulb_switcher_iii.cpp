/**
 * 1375. Bulb Switcher III
 * 
There is a room with n bulbs, numbered from 1 to n, arranged in a row from left to right. Initially, all the bulbs are turned off.

At moment k (for k from 0 to n - 1), we turn on the light[k] bulb. A bulb change color to blue only if it is on and all the previous bulbs (to the left) are turned on too.

Return the number of moments in which all turned on bulbs are blue.
*/

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int max_val = 0, res = 0;
        for (int i = 0; i < light.size(); i++)
        {
            max_val = max(max_val, light[i]);
            if (max_val == i + 1) res++;
        }
        return res;
    }
};
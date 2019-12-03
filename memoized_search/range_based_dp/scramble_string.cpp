#include <string>

/* Explanation:
 *
 * 如果组成 s1 和 s2 的每种字符的数量不同, 可以直接判定为 false, 例如样例2的 "a" 和 "b". 以及两个字符串长度不相同也可以直接返回 false.

 * 这道题目的重点实际上是找到构造二叉树的方式. 二叉树的构造决定了 s1 的哪些部分可以交换位置来得到新的字符串. 下面提供了多个版本算法的代码, 这里只介绍动态规划的思路:

 * 设定状态: f[l1][r1][l2][r2] 表示是否可以由 s1 的[l1, r1]的子串攀爬得到 s2 的[l2, r2]的子串. 决策便是从哪里分割 s1, 所以我们枚举分割的点, 于是达到了子问题.

 * 不过需要注意的是, 由于二叉树的子节点可以被交换, 所以 s2 可能是被交换过的, 所以完整的状态转移方程是:

 * 枚举k, 表示从 s1的 [l1, r1] 的第k个字符后分割, 只要有其中一种分割可以得到 s2 即可, 因此是在枚举的 k 中取 或运算
 * f[l1][r1][l2][r2] = OR (f[l1][l1 + k - 1][l2][l2 + k - 1] && f[l1 + k][r1][l2 + k][r2]) // 该节点的两个子节点没有交换过
                       OR (f[l1][l1 + k - 1][r2 - k + 1][r2] && f[l1 + k][r1][l2][r2 - k]) // 该节点的两个子节点交换过
 * 边界状态即: f[l1][l1][l2][l2] = (s1[l1] == s2[l2])

 * 注意到 r1 - l1 == r2 - l2, 所以这个四维数组可以被优化掉一维.
 * */

class Solution {
public:
    bool isScramble(std::string s1, std::string s2) {
                if (s1 == s2)
            return true;

        int n = s1.size();

        // a preliminary step: 
        // check if the show-up times of each character are the same for both string 
        int value1 = 0, value2 = 0;
        for (int i = 0; i < n; ++i)
        {
            value1 += (s1[i] - 'a');
            value2 += (s2[i] - 'a');
        }
        if (value1 != value2)
            return false;

        // start processing
        for (int i = 1; i < n; i++)
        {
            // based on the formula in the explanation:
            if ( isScramble( s1.substr(0, i), s2.substr(0, i) ) &&
                 isScramble( s1.substr(i), s2.substr(i) ) )
                 return true;
            if ( isScramble( s1.substr(0, i), s2.substr(n - i) ) && 
                 isScramble( s1.substr(i), s2.substr(0, n - i) ) )
                 return true;
        }

        return false;
    }
};
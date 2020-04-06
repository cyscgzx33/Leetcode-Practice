# Detailed Explanation

## Longest Happy String
Check the [source code](longest_happy_string.cpp), and thanks for [votrubac's delicate answer](https://leetcode.com/problems/longest-happy-string/discuss/564277/C%2B%2BJava-a-greater-b-greater-c).
 
My explanation about the intuition of this approach.

First of all, it's just like playing a poker game with a greedy strategy. Suppose you're a single player of this game, the goal is to escape as many cards in your hand as possible, with a restriction rule that you can't escape 3 same cards in a row. Now let's start playing the poker game, every round, you have to organize those cards in your hand (three types: `'a'`, `'b'`, `'c'`), with an order of `a >= b >= c`.
```C++
    if (a < b) // this condition determines: a >= b
        return longestDiverseString(b, a, c, bb, aa, cc);
    if (b < c) // this condition determines: b >= c
        return longestDiverseString(c, b, a, cc, bb, aa);
    // with the two conditions above, we can confirm: a >= b >= c
```
After organizing the order of cards in your hand, you start escaping! There're theoretically 3 cases:
- Case 1: `a > 0, b = 0, c = 0`: now you only have the chance to escape `min(a, 2)` cards, otherwise you break the 3-card-in-a-row rule;
- Case 2: `a >= b >= 1, c whatever`: now you have to escape `min(a, 2)` number of `'a'`cards first. After that, check if `a >= b` is satisfied, then you can follow another `'b'` here. However, if `a < b` please don't escape `'b'`. The reason is that if you do so, in the next round `'b'` would be the one with the largest number (a simple proof: `b > a && b >=c`), then you'll get risk breaking the 3-card-in-a-row rule.
```C++
    // Case 1
    if (b == 0) 
        return aa.repeat(Math.min(2, a));
    // Case 2
    int use_a = Math.min(2, a), use_b = a - use_a >= b ? 1 : 0; 
    return aa.repeat(use_a) + bb.repeat(use_b) +
        generate(a - use_a, b - use_b, c, aa, bb, cc); 
```
The only point is, the explained approach above can only determine each round's best strategy, but not necessarily guaranteed to be the globally best strategy. That's why I feel like it's sort of greedy strategy. If someone is interested, please prove the correctness of this approach, I'll be very appreciated.
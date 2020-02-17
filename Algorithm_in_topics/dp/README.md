**Dynamic Programming**
---
* Very challenging but fascinating algorithm type
* Usually can be resolved through such a flow: **Brutal Force** -> **Memoized Search** -> (strictly) **Dynamic Programming**
* There is a ***standard template*** for a DP problem, i.e., if the following 4 questions are answered, one can almost achieve the dp algorithm coding:
    * What is the **definition** of the vector/array `dp`?
    * What are the **boundary conditions / initial conditions** of `dp`?
    * (*Usually the most important question*) What is the **state transition** function of dp, i.e., how to **divide a problem into sub-problem(s)**? 
    * What is the **order** should the vector/array `dp` be iterating in the main loop(s)?
* As an example of conducting the ***standard template*** above, let's take the `Stone Game` problem ([Lintcode link](https://www.lintcode.com/problem/stone-game/description), [Solution](range_based_dp/stone_game.cpp)) to go through the 4 questions:
    * **definition** of `dp[i][j]`: the cost of moving all the stones in the range [i, j], with boundary positions i & j included
    * **boundary conditions / initial conditions**: dp[i][i] = 0 (as no cost is needed to move a single stone), dp[i][j] = sum[i, j]
    * **state transition matrix**: ``` dp[i][j] = sum[i, j] + min{i<= k < j}(dp[i][k] + dp[k+1][j]) ```, important here, `k` is the *partition position* here so that the problem of `dp[i][j]` is divided into two sub-problems `dp[i][k]` & `dp[k+1][j]`, and the optimal `dp[i][j]` take the minimum choice among all the feasible partition positions of `k`
    * **order of iteration**: firstly with an outer loop `l` as the length (length := j - i + 1), following by starting position `i`, finally with partition position `k`

**Basic Sub-topics**
---
| # | Sub-topic | Classic Examples |
|---| --------- | ---------------- |
|1|[Memoized Search](memoized_search/)| [Russion doll envelopes](memoized_search/russian_doll_envelopes.cpp), [Word break II](memoized_search/word_break_ii.cpp)
|2|[Range based DP](range_based_dp/)| [Post office problem](range_based_dp/post_office_problem.cpp), [Stone Game](range_based_dp/stone_game.cpp), [Stone Game II](range_based_dp/stone_game_ii.cpp)
|3|[Game based DP](game_based_dp/)|
|4|[Backpack DP](backpack_questions/)|
|5|[Two sequence DP](two_sequence_dp/)| [Edit Distance](two_sequence_dp/edit_distance.cpp), [K Edit Distance](two_sequence_dp/k_edit_distance.cpp)
|6| [Other (uncategorized) DP](other_uncategorized_dp/)|
# Union Find

## Type 1: Nodes with Encoded IDs

### LintCode 1070. Accounts Merge

#### Description

Given a list accounts, each element accounts\[i\] is a list of strings, where the first element accounts\[i\]\[0\] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in **sorted order**. The accounts themselves can be returned in any order.

{% hint style="info" %}
The length of accounts will be in the range \[1, 1000\]. 

The length of accounts\[i\] will be in the range \[1, 10\]. 

The length of accounts\[i\]\[j\] will be in the range \[1, 30\].
{% endhint %}

#### Example

```text
Example 1:
	Input:
	[
		["John", "johnsmith@mail.com", "john00@mail.com"],
		["John", "johnnybravo@mail.com"],
		["John", "johnsmith@mail.com", "john_newyork@mail.com"],
		["Mary", "mary@mail.com"]
	]
	
	Output: 
	[
		["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],
		["John", "johnnybravo@mail.com"],
		["Mary", "mary@mail.com"]
	]

	Explanation: 
	The first and third John's are the same person as they have the common email "johnsmith@mail.com".
	The second John and Mary are different people as none of their email addresses are used by other accounts.

	You could return these lists in any order, for example the answer
	
	[
		['Mary', 'mary@mail.com'],
		['John', 'johnnybravo@mail.com'],
		['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']
	]
	is also acceptable.
```

**Logic:**

* Use **email address** as nodes in the union graph
  * However, the email itself is hard to deal with, as it is within **string type**
  * A proper way is to **encode** the email by assigning them into different **ID**, which can be achieved by using hash map: check the `email_dict` in the sample code

{% code title="accounts\_merge.cpp" %}
```cpp
class Solution {
private:
    vector<int> father;
public:
    int find(int x)
    {
        int j = x;
        while (father[j] != j)
        {
            j = father[j];
        }
        
        int fx = x;
        while (x != j)
        {
            fx = father[x];
            father[x] = j;
            x = fx;;
        }
        
        return j;
    }
    
    void connect(int a, int b)
    {
        int root_a = find(a);
        int root_b = find(b);
        
        if (root_a != root_b)
        {
            father[root_b] = root_a;
        }
    }
    
    /**
     * @param accounts: List[List[str]]
     * @return: return a List[List[str]]
     */
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        
        // n is the theoretical maximum size of father
        int n = accounts.size();
        father.assign(n, 0);
        for (int i = 0; i < n ;i++)
            father[i] = i;

        // construct the union graph    
        unordered_map<string, int> email_dict; // key: email, val: index
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string email = accounts[i][j];
                if (email_dict.count(email) == 0)
                {
                    email_dict[email] = i;
                }
                else
                {
                    int k = email_dict[email];
                    connect(k, i);
                }
            }
        }

        // merge accounts using union graph
        unordered_map<int, set<string>> merged_accounts; // key: int, val: emails
        for (int i = 0; i < n; i++)
        {
            int usr_id = find(i);
            if (merged_accounts.count(usr_id) == 0)
                merged_accounts[usr_id] = {};
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string email = accounts[i][j];
                merged_accounts[usr_id].insert(email);
            }
        }

        // collect results
        vector<vector<string>> res;
        for (auto it = merged_accounts.begin(); it != merged_accounts.end(); it++)
        {
            vector<string> row;
            string usr_name = accounts[it->first][0];
            row.push_back(usr_name);
            for (auto email : it->second)
                row.push_back(email);
            res.push_back(row);
        }

        return res;
    }
};
```
{% endcode %}

### LintCode 1396. Set Union

#### Description

There is a list composed by sets. If two sets have the same elements, merge them. In the end, there are several sets left.

{% hint style="info" %}
* The number of sets `n <=1000`.
* The number of elements for each set `m <= 100`.
* The element must be a non negative integer and not greater than `100000`.
{% endhint %}

#### Example

**Example 1:**

```text
Input :list = [[1,2,3],[3,9,7],[4,5,10]]
Output:2 .
Explanation:There are 2 sets of [1,2,3,9,7] and [4,5,10] left.
```

**Example 2:**

```text
Input:list = [[1],[1,2,3],[4],[8,7,4,5]]
Output :2
Explanation:There are 2 sets of [1,2,3] and [4,5,7,8] left.
```

#### Logic:

* Exactly same as **LintCode 1070. Accounts Merge**

#### Sample code:

{% code title="set\_union.cpp" %}
```cpp
class Solution {
private:
    vector<int> father;
    int find(int x)
    {
        int j = x;
        while (father[j] != j)
            j = father[j];
        
        int fx = x;
        while (x != j)
        {
            fx = father[x];
            father[x] = j;
            x = fx;
        }
        
        return j;
    }
    
    void connect(int a, int b)
    {
        int root_a = find(a);
        int root_b = find(b);

        if (root_b != root_a)
            father[root_b] = root_a;
    }

public:
    /**
     * @param sets: Initial set list
     * @return: The final number of sets
     */
    int setUnion(vector<vector<int>> &sets) {
        int n = sets.size(); // theoretical maximum size
        father.assign(n, 0);
        for (int i = 0; i < n; i++)
            father[i] = i;

        unordered_map<int, int> dict; // key: values in the sets, index
        for (int i = 0; i < n; i++)
        {
            for (auto s : sets[i])
            {
                if (dict.count(s) == 0)
                    dict[s] = i;
                else
                {
                    int exist_id = dict[s];
                    connect(exist_id, i);
                }
            }
        }

        unordered_set<int> islands;
        for (int i = 0; i < n; i++)
            islands.insert(find(i));

        return islands.size();
    }
};
```
{% endcode %}

### LeetCode 952. Largest Component Size by Common Factor

Given a non-empty array of unique positive integers `A`, consider the following graph:

* There are `A.length` nodes, labelled `A[0]` to `A[A.length - 1];`
* There is an edge between `A[i]` and `A[j]` if and only if `A[i]` and `A[j]` share a common factor greater than 1.

Return the size of the largest connected component in the graph.

**Example 1:**

```text
Input: [4,6,15,35]
Output: 4

```

**Example 2:**

```text
Input: [20,50,9,63]
Output: 2

```

**Example 3:**

```text
Input: [2,3,6,7,4,12,21,39]
Output: 8

```

**Note:**

1. `1 <= A.length <= 20000`
2. `1 <= A[i] <= 100000`

#### Logic:

* Find factors \(or prime factors\) of each element in `A`, connect them from back to front
* At each front element, add `dim` to calculate the `max_dim`
* For the dimension calculation, always find the father of it, instead of itself
* The sample code shows the non-prime-factor version, while the prime-factor version is almost the same

#### Sample Code:

```cpp
class Solution {
private:
    int father[100001];
    int dim[100001];
    int max_dim = 1;
    
    int find(int x) {
        int j = x, fx = x;
        while (j != father[j]) {
            j = father[j];
        }
        
        while (j != x) {
            fx = father[x];
            father[x] = j;
            x = fx;
        }
        
        return j;
    }
    
    void connect(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        
        if (root_a != root_b) {
            father[root_b] = root_a;
            dim[root_a] += dim[root_b];
            dim[root_b] = 0;
        }
    }
    
    vector<int> getFactors(int x) {
        vector<int> res;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                res.push_back(i);
                res.push_back(x/i);
            }
        }
        res.push_back(x);
        return res;
    }
public:
    int largestComponentSize(vector<int>& A) {
        for (int i = 0; i <= 100000; i++) {
            father[i] = i;
            dim[i] = 0;
        }
        
        for (auto a : A) {
            vector<int> factors = getFactors(a);
            for (int i = factors.size()-1; i > 0; i--) {
                connect(factors[i], factors[i-1]);
            }
            dim[find(factors[0])]++;
            max_dim = max(dim[find(factors[0])], max_dim);
        }
        
        return max_dim;
    }
};
```




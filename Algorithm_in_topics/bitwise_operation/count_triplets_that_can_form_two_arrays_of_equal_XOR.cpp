/* Method 1: using a map with vector O(N^2) */
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> pfsum_map; // key: xor_pfsum value, val: indices

        // construct a prefix sum vector for xor, f(0) = 0, f(k) {for any 0 < k <= n}  = 0 ^ arr[0] ^ arr[1] ^ ... ^ arr[k-1]
        vector<int> xor_pfsum(n + 1, 0);
        pfsum_map.insert( {xor_pfsum[0], {0}});
        for (int i = 0; i < n; i++)
        {
            xor_pfsum[i+1] = xor_pfsum[i] ^ arr[i];
            
            if (pfsum_map.count(xor_pfsum[i+1]) == 0)
                pfsum_map.insert( {xor_pfsum[i+1], {}} );
            pfsum_map[xor_pfsum[i+1]].push_back(i+1);
        }

        int res = 0;
        // loop the xor_pfsum to find matching pairs
        for (int k = 2; k <= n; k++)
        {
            int F_1_k = xor_pfsum[k];
            for (auto index : pfsum_map[F_1_k])
            {
                if (index < k - 1)
                    res += (k - index - 1);
            }
        }

        return res;
    }
};


/* Method 2: using map only with int, O(N) */

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        /* Explanation:
        
        a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
        b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]

        Assume a == b, thus
        a ^ a = b ^ a, thus
        0 = b ^ a, thus
        arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1] ^ arr[j] ^ arr[j + 1] ^ ... ^ arr[k] = 0
        prefix[k+1] = prefix[i]

        We only need to find out how many pair (i, k) of prefix value are equal.
        So we can calculate the prefix array first,
        then brute force count the pair.

        Because we once we determine the pair (i,k),
        j can be any number that i < j <= k,
        so we need to plus k - i - 1 to the result res.
        
        
        (further: might be very small issues of indexing system)
        Explanation for approach 4:

        you have an array : a[0], a[1].... a[n - 1]

        First things first:
        We need to understand small fact, if xor(a[0....i]) has appeared before at index j then it means xor(a[j+1.....i]) = 0
        Another fact, if xor(a[i....j]) = 0 so this subarray will add (j - i - 1) to the answer.

        Now say currently we are at index i and let xor([0...i]) = x.

        Now say x has occurred 3 times previously at indices (i1, i2, i3)

        our answer for i will be = (i - i1 - 1) + (i - i2 - 1) + (i - i3 - 1)

        if you simplify this further you get f * i - (i1 + i2 + i3) - f = (i - 1) * f - (i1 + i2 + i3)

        f = no. of times x has occurred previously.

        (i1 + i2 + i3) = sum of all the indices where x has occurred previously.

        */
        
        int n = arr.size();
        unordered_map<int, int> freq, total;
        freq.insert({0, 1});
        total.insert({0, 0});
        vector<int> pfsum(n+1, 0); // pfsum[i] = arr[0] ^ arr[1] ^ ... ^ arr[i-1]
        
        // a tip: try to seperate pfsum and final process,
        //        because the pfsum calculation has different indexing system
        for (int i = 0; i < n; i++)
            pfsum[i+1] = pfsum[i] ^ arr[i];

        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            res += freq[pfsum[i]] * (i - 1) - total[pfsum[i]]; 
            freq[pfsum[i]]++;
            total[pfsum[i]] += i;
        }
        
        return res;
    }
};
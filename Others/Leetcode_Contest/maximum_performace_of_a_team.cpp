#include <utility>      // pair
#include <vector>       // vector
#include <algorithm>    // sort()
#include <queue>        // priority_queue, greater()
#include <cmath>        // pow()

using namespace std;

/* Method 1: TLE (because of repeatedly initializing the min_heap) */
class Solution {
public:
    static bool compare(pair<int, int>& a, pair<int, int>& b)
    {
        return a.first < b.first;
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        // pairing the efficiency and speed
        vector<pair<int, int>> sp_eff(n);
        for (int i = 0; i < n; i++)
        {
            sp_eff[i].first = efficiency[i];
            sp_eff[i].second = speed[i];
        }
        // sort based on efficiency
        sort(sp_eff.begin(),sp_eff.end(), compare);

        // loop each minimum efficiency
        long res = 0;
        // * a fix: the min_heap loops from right to left
        priority_queue<long, vector<long>, greater<long> > min_heap;
        long heap_sum = 0;
        for (int i = 0; i < n ; i++)
        {
            // according to the picture on 3/15/2020: i is the anchor position!
            long cur_spd_i = sp_eff[i].second;
            long cur_eff_i = sp_eff[i].first;
            for (int j = i + 1; j < n && k > 1; j++)
            {
                long cur_spd_j = sp_eff[j].second;
                if (min_heap.size() < k - 1) // it's k - 1
                {
                    min_heap.push(cur_spd_j); // speed
                    heap_sum += cur_spd_j;
                }
                else
                {
                    if (cur_spd_j <= min_heap.top())
                        continue;
                    heap_sum -= min_heap.top();
                    min_heap.pop();
                    min_heap.push(cur_spd_j);
                    heap_sum += cur_spd_j;
                }
            }
            
            long cur_res = (heap_sum + cur_spd_i) * cur_eff_i; // speed * efficiency
            res = cur_res > res ? cur_res : res;
        }
        
        return res % long(pow(10, 9) + 7);
    }
};

/* Method 2: loop from right to left to avoid repeatedly initialization of min_heap */
class Solution {
public:
    static bool compare(pair<int, int>& a, pair<int, int>& b)
    {
        return a.first < b.first;
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        // pairing the efficiency and speed
        vector<pair<int, int>> sp_eff(n);
        for (int i = 0; i < n; i++)
        {
            sp_eff[i].first = efficiency[i];
            sp_eff[i].second = speed[i];
        }
        // sort based on efficiency
        sort(sp_eff.begin(),sp_eff.end(), compare);

        // loop each minimum efficiency
        long res = 0;
        // * a fix: the min_heap loops from right to left
        priority_queue<long, vector<long>, greater<long> > min_heap;
        long heap_sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            // according to the picture on 3/15/2020: i is the anchor position!
            long cur_eff_i = sp_eff[i].first;
            long cur_spd_i = sp_eff[i].second;
            if (min_heap.size() >= k)
            {
                heap_sum -= min_heap.top();
                min_heap.pop();
            }
            min_heap.push(cur_spd_i);
            heap_sum += cur_spd_i;
            long cur_res = heap_sum * cur_eff_i;
            res = cur_res > res ? cur_res : res;
        }

        return res % long(pow(10, 9) + 7);
    }
};
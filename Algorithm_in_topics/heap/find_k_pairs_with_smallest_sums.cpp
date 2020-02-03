class Comparator
{
public:
    bool operator() (const std::pair<int, std::pair<int, int>>& a, const std::pair<int, std::pair<int, int>>& b)
    {
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int sz1 = nums1.size();
        int sz2 = nums2.size();
    
        if (sz1 == 0 || sz2 == 0)
            return {};
        
        int m = 0, n = 0;
        int cnt = 1; // suppose k is 1-based
        std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>,  Comparator> pq;
        pq.push( { nums1[0] + nums2[0], {0, 0} } ); // pair info -- first: nums[i] + nums[j], second.first: i, second.second: j
        
        // note 1: there has to be a visit 2D vector
        std::vector<std::vector<int>> visit( sz1, std::vector<int>(sz2, 0) );
        visit[0][0] = 1;

        std::vector<std::vector<int>> res;
        while (cnt <= k && pq.size() > 0)
        {
            auto curr = pq.top();
            pq.pop();
            int val = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;

            std::cout << "val = " << val << ", [x, y] = [" << x << ", " << y << "]\n";

            res.push_back( { nums1[x], nums2[y] } );
            cnt++;
            if (x + 1 < sz1 && visit[x + 1][y] == 0)
            {
                pq.push( { nums1[x + 1] + nums2[y], {x + 1, y} } );
                visit[x + 1][y] = 1;
            }

                
            if (y + 1 < sz2 && visit[x][y + 1] == 0)
            {
                pq.push( { nums1[x] + nums2[y + 1], {x, y + 1} } );
                visit[x][y + 1] = 1;
            }
        }

        return res;
    }
};

/*
[1,1,2]
[1,2,3]
10
*/

/*
val = 2, [x, y] = [0, 0]
val = 2, [x, y] = [1, 0]
val = 3, [x, y] = [0, 1]
val = 3, [x, y] = [2, 0]
val = 3, [x, y] = [1, 1]
val = 3, [x, y] = [1, 1]
val = 4, [x, y] = [0, 2]
val = 4, [x, y] = [1, 2]
val = 4, [x, y] = [1, 2]
val = 4, [x, y] = [1, 2]
*/
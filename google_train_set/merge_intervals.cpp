class Solution {
public:
    static bool comparator(const std::vector<int>& a, const std::vector<int>& b)
    {
        return ( a[0] == b[0] ? a[1] < b[1] : a[0] < b[0] );
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if (intervals.size() == 0)
        	return {};

        std::sort(intervals.begin(), intervals.end(), comparator);

        std::vector<std::vector<int>> res;
        res.push_back( intervals[0] );
        for (int i = 1; i < intervals.size(); i++)
        {
        	int tl = res.back()[0], tr = res.back()[1]; // target left&right bounds
        	int sl = intervals[i][0], sr = intervals[i][1]; // source left&right bounds

        	if (sr <= tr)
        		continue;
        	else // sr > tr
        	{
        		if (sl <= tr)
        			res.back()[1] = sr;
        		else
        			res.push_back( intervals[i] );
        	}
        }

        return res;
    }
};
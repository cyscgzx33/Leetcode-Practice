class Solution {
public:
	static bool comparator(const std::vector<int>& a, const std::vector<int>& b)
	{
		return ( a[0] == b[0] ? a[1] < b[1] : a[0] < b[0] ); 
	}
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
        	return 0;

        std::sort(intervals.begin(), intervals.end(), comparator);
        std::vector<std::vector<int>> res;
        res.push_back( intervals[0] );

        for (int i = 1; i < intervals.size(); i++)
        {
        	int sl = intervals[i][0], sr = intervals[i][1];
        	bool found_room = false;
        	for (int j = 0; j < res.size(); j++)
        	{
        		int tr = res[j][1];
        		if (sl >= tr)
        		{
        			res[j][1] = sr;
        			found_room = true;
        			break;
        		}
        	}
        	if (found_room == false)
        		res.push_back( intervals[i] );
        }

        return res.size();
    }
};
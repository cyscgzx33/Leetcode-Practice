class Event
{
public:
	int time;
	int height;
	int flag; // +1 shows up, -1 vanishes

	Event(int t, int h, int f) : time(t), height(h), flag(f) {}
};

class Solution {
private:
	static bool comp(Event& a, Event& b)
	{
		if (a.time != b.time)
			return a.time < b.time;
		else
			return a.flag < b.flag; // as the question asks us to regard f(x+) as the res @ each critical pt x
	}
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
    	std::vector<Event> evts;
        for (auto& bd : buildings)
        {
        	evts.emplace_back(bd[0], bd[2], 1);
        	evts.emplace_back(bd[1], bd[2], -1);
        }
        std::sort(evts.begin(), evts.end(), comp);

        std::vector<std::vector<int>> res;
        std::multiset<int> lines;
        int cur_max = 0;

        for (auto& evt : evts)
        {
        	if (evt.flag == 1)
        		lines.insert(evt.height);
        	else
        		lines.erase( lines.lower_bound(evt.height) ); // NOT evt.height, otherwise it would delete everything equals to evt.height
        	if (lines.size() > 0)
        	{
        		if (*lines.rbegin() != cur_max)
        		{
        			cur_max = *lines.rbegin();
        			res.push_back( {evt.time, cur_max} );
        		}
        	}
        	else
        	{
        		cur_max = 0;
        		res.push_back( {evt.time, cur_max} );
        	}
        }
        return res;
    }
};
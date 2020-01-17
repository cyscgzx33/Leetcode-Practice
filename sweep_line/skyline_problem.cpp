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

        std::multiset<int> lines;
        for (auto& evt : evts)
        {
        	if (evt.flag == 1)
        		lines.insert(evt.);
        }
    }
};
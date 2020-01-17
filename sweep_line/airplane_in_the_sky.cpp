/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Event
{
public:
	int time;
	int flag; // +1 := take off, -1 := touch down

	Event(int t, int f) : time(t), flag(f) {}
};

class Solution {
private:
	static bool comp(Event& a, Event& b)
	{
		if (a.time != b.time)
			return a.time < b.time;
		else
			return a.flag < b.flag;
	}

public:
    /**
     * @param airplanes: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        
        std::Vector<Event> evts;
        for (auto& ap : airplanes)
        {
        	evts.emplace_back(ap.start, 1);
        	evts.emplace_back(ap.end, -1);
        }

        // sort the evts vector
        std::sort(evts.begin(), evts.end(), comp);

        int cnt = 0, max_cnt = 0;

        for (auto& evt : evts)
        {
        	if (evt.flag == 1)
        		cnt++;
        	else
        		cnt--;
        	max_cnt = max(cnt, max_cnt);
        }

        return max_cnt;
    }
};
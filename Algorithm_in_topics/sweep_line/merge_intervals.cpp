#include <vector>
#include <algorithm>

using namespace std;

class Event
{
  public:
    int time;
    int flag; // 1: start, -1: end
    Event(int t, int f) : time(t), flag(f) {}
};


class Solution {
    static bool compare(const Event& a, const Event& b)
    {
        return a.time == b.time ? a.flag > b.flag : a.time < b.time; // start first here, to concatenate the intervals
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<Event> events;
        
        for (auto& interval : intervals)
        {
            events.emplace_back(interval[0], 1);
            events.emplace_back(interval[1], -1);
        }
                
        sort(events.begin(), events.end(), compare);

        int cnt = 0; // simulate how many intervals are active
                     // very similar to: how many planes are in the sky
        vector<int> cur_interval = {0, 0};
        vector<vector<int>> merged_intervals;
        for (auto& event : events)
        {
            if (cnt == 0)
                cur_interval[0] = event.time;
            if (event.flag == 1)
                cnt++;
            else
                cnt--;
            if (cnt == 0)
            {
                cur_interval[1] = event.time;
                merged_intervals.push_back(cur_interval);
                // reset cur_interval
                cur_interval[0] = 0; 
                cur_interval[1] = 0;
            }
        }

        return merged_intervals;
    }
};
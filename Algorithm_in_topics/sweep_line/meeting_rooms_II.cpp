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
    int flag; // 1: start, -1:end
    
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
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        vector<Event> evts;
        for (auto it : intervals)
        {
            evts.emplace_back(it.start, 1);
            evts.emplace_back(it.end, -1);
        }
        sort(evts.begin(), evts.end(), comp);
        
        int max_rooms = 0, curr_rooms = 0;
        for (int i = 0; i < evts.size(); i++)
        {
            if (evts[i].flag == 1)
                curr_rooms++;
            else
                curr_rooms--;
            max_rooms = max(max_rooms, curr_rooms);
        }
        
        return max_rooms;
    }
};
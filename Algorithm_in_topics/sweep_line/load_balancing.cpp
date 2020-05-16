#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

class Event
{
  public:
    int time;
    int flag; // start = 1, end = -1;
    int req_id;   // request id
    Event(int t, int f, int i) : time(t), flag(f), req_id(i) {}
};

class Solution
{
  private:
    static bool compare(const Event& a, const Event& b)
    {
        if (a.time == b.time)
            return a.req_id == b.req_id ? a.flag > b.flag : a.req_id < b.req_id;
        else
            return a.time < b.time;
    }
  public:
    vector<int> loadBalancer(int k, vector<int>& arrival, vector<int>& load)
    {
        int n = arrival.size();

        // create events by requests before process them
        vector<Event> events;
        vector<bool> valid(n, true);
        for (int i = 0; i < n; i++)
        {
            int start = arrival[i];
            int end = arrival[i] + load[i] - 1; // finish time is -1
            events.emplace_back(start, 1, i);
            events.emplace_back(end, -1, i);
        }
        sort(events.begin(), events.end(), compare);

        // create available servers before process events
        set<int> avail_servers;
        for (int i = 0; i < k; i++)
            avail_servers.insert(i);

        // process events
        vector<int> srv_freq(k, 0);
        unordered_map<int, int> req2srv; // request id -> server id
        unordered_set<int> invalid_events;
        for (auto evt : events)
        {
            int flag = evt.flag;
            int req_id = evt.req_id;
            if (flag == 1)
            {
                if (avail_servers.size() == 0)
                { 
                    // no available server now, drop the req 
                    invalid_events.insert(req_id);
                    continue;
                }
                int srv_id = *(avail_servers.begin());
                avail_servers.erase(avail_servers.begin());
                srv_freq[srv_id]++;
                req2srv[req_id] = srv_id;

                // print out every count
                cout << "start time = " << evt.time << ", server id = " << srv_id << ", freq = " << srv_freq[srv_id] << endl;

            }
            else // flag == 0
            {
                if (invalid_events.count(req_id) > 0)
                    continue; // already invalid/dropped, haven't assigned any server to this req
                int srv_id = req2srv[req_id];
                avail_servers.insert(srv_id);

                // print out every count
                cout << "end time = " << evt.time << ", server id = " << srv_id << ", freq = " << srv_freq[srv_id] << endl;
            }
        }

        // get final results
        int max_val = -1;
        for (int i = 0; i < k; i++)
            max_val = max(srv_freq[i], max_val);
        
        vector<int> res = {};
        for (int i = 0; i < k; i++)
        {
            if (srv_freq[i] == max_val)
                res.push_back(i);
        }

        // print out srv_freq
        cout << "freq = ";
        for (auto f : srv_freq)
            cout << f << ", ";
        cout << endl;

        // print out results
        cout << "res = "; 
        for (auto r : res)
            cout << r << ", ";
        cout << endl;

        return res;
    }
};

int main()
{
    Solution sln;
    int k = 4; // 3
    // vector<int> arrivals = {1, 2, 3, 4, 5};
    // vector<int> load     = {6, 3, 4, 4, 4};
    // vector<int> arrivals = {1, 2, 3, 5, 6, 8, 10};
    // vector<int> load     = {4, 4, 4, 5, 5, 5, 5};
    vector<int> arrivals = {1, 4, 5, 5, 6, 6, 7, 8, 10};
    vector<int> load     = {2, 4, 3, 2, 1, 1, 8, 4, 6};
    // vector<int> arrivals = {1,  2, 3, 4, 6, 6};
    // vector<int> load     = {10, 1, 2, 1, 1, 1};

    sln.loadBalancer(k, arrivals, load);

    return 0;
}
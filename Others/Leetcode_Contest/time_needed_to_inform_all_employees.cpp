/**
 * 1376. Time Needed to Inform All Employees
A company has n employees with a unique ID for each employee from 0 to n - 1. The head of the company has is the one with headID.

Each employee has one direct manager given in the manager array where manager[i] is the direct manager of the i-th employee, manager[headID] = -1. Also it's guaranteed that the subordination relationships have a tree structure.

The head of the company wants to inform all the employees of the company of an urgent piece of news. He will inform his direct subordinates and they will inform their subordinates and so on until all employees know about the urgent news.

The i-th employee needs informTime[i] minutes to inform all of his direct subordinates (i.e After informTime[i] minutes, all his direct subordinates can start spreading the news).

Return the number of minutes needed to inform all the employees about the urgent news.
*/


class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, unordered_set<int>> up2sub; // key: upperlevel - boss (id), value: subordinates - employee (index in manager vector) 
        if (n == 1)
            return 0;
        for (int i = 0; i < n; i++)
        {
            if (up2sub.count(manager[i]) == 0)
                up2sub[manager[i]] = {i}; // eg. manager[i=0] = -1, i = 0, => up2sub[-1] = {0}; manager[i=1] = 0, i = 1, -> up2sub[0] = {1} 
            else
                up2sub[manager[i]].insert(i);
        }
        
        queue<int> q;
        q.push(headID);
        vector<int> total_time(n, 0); // starting from id?
        while (q.size() > 0)
        {
            int sz = q.size();
            // add all the suborinates of all the current level upper
            for (int i = 0; i < sz; i++)
            {
                // one of current level uppers
                auto cur_up = q.front();
                q.pop();
                for (auto sub : up2sub[cur_up])
                {
                    total_time[sub] = total_time[cur_up] + informTime[cur_up];
                    q.push(sub);
                }
            }
        }
        
        int res = 0;
        for (auto tt : total_time)
            res = max(tt, res);
        
        return res;
        
    }
};
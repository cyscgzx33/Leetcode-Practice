/**
 * Definition for a Connection.
 * class Connection {
 * public:
 *   string city1, city2;
 *   int cost;
 *   Connection(string& city1, string& city2, int cost) {
 *       this->city1 = city1;
 *       this->city2 = city2;
 *       this->cost = cost;
 * }
 */

class Solution {
private:
    static bool comp(Connection& a, Connection& b)
    {
        if (a.cost != b.cost)
            return a.cost < b.cost;
        else if (a.city1 != b.city1)
            return a.city1 < b.city1;
        else
            return a.city2 < b.city2;
    }

    std::vector<int> father;

    int find(int x)
    {
        int j = x, fx = 0;
        while (0 != father[j])
            j = father[j];

        while (x != j)
        {
            fx = father[x];
            father[x] = j;
            x = fx;
        }

        return j;
    }

public:
    /**
     * @param connections given a list of connections include two cities and cost
     * @return a list of connections from results
     */
    vector<Connection> lowestCost(vector<Connection>& connections) {
        std::sort(connections.begin(), connections.end(), comp);
        std::unordered_map<std::string, int> map;
        int idx = 0; // 0 is the initial value of father[j]
        for (auto& cnct : connections)
        {
            if (map.count(cnct.city1) == 0)
                map[cnct.city1] = ++idx;
            if (map.count(cnct.city2) == 0)
                map[cnct.city2] = ++idx;
        }

        father.resize(idx + 1, 0); // why +1 here? Because idx belongs to [1, n]
                                   // another approach: set father[x] = -1 as Initial Values
                                   // safest approach: father.resize(connections.size(), 0 || 1)
        std::vector<Connection> res;
        for (auto& cnct : connections)
        {
            int idx1 = map[cnct.city1];
            int idx2 = map[cnct.city2];

            int root1 = find(idx1);
            int root2 = find(idx2);
            if (root1 != root2)
            {
                father[root2] = root1;
                res.push_back(cnct);
            }
        }

        if (res.size() != idx - 1) // if N nodes exist, then there're only (N-1) edges
            return {};
        return res;
    }
};

/* another method for indexing */
class Solution {
private:
    static bool comp(Connection& a, Connection& b)
    {
        if (a.cost != b.cost)
            return a.cost < b.cost;
        else if (a.city1 != b.city1)
            return a.city1 < b.city1;
        else
            return a.city2 < b.city2;
    }

    std::vector<int> father;

    int find(int x)
    {
        int j = x, fx = 0;
        while (-1 != father[j])
            j = father[j];

        while (x != j)
        {
            fx = father[x];
            father[x] = j;
            x = fx;
        }

        return j;
    }

    void connect(int a, int b)
    {
        int root_a = find(a);
        int root_b = find(b);
        if (root_a != root_b)
            father[root_b] = root_a;
    }

public:
    /**
     * @param connections given a list of connections include two cities and cost
     * @return a list of connections from results
     */
    vector<Connection> lowestCost(vector<Connection>& connections) {
        // Write your code here
        std::sort(connections.begin(), connections.end(), comp);
        std::unordered_map<std::string, int> map;
        int idx = -1; // -1 is the initial value of father[j]
        for (auto& cnct : connections)
        {
            if (map.count(cnct.city1) == 0)
                map[cnct.city1] = ++idx;
            if (map.count(cnct.city2) == 0)
                map[cnct.city2] = ++idx;
        }

        father.resize(connections.size(), -1); // why +1 here? because idx belongs to [1, n]
        std::vector<Connection> res;
        for (auto& cnct : connections)
        {
            int idx1 = map[cnct.city1];
            int idx2 = map[cnct.city2];

            int root1 = find(idx1);
            int root2 = find(idx2);
            if (root1 != root2)
            {
                father[root2] = root1;
                res.push_back(cnct);
            }
        }

        if (res.size() != idx)
            return {};
        return res;
    }
};
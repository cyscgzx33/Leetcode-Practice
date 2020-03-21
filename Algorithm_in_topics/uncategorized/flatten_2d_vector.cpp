#include <vector>

using namespace std;

class Vector2D {
    vector<vector<int>>::iterator begin, end;
    int pos;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        // Initialize your data structure here
        begin = vec2d.begin();
        end = vec2d.end();
        pos = 0;
    }

    int next() {
        // Write your code here
        return (*begin)[pos++];
    }

    bool hasNext() {
        // Write your code here
        while (begin != end && (*begin).size() == pos)
        {
            pos = 0;
            begin++;
        }
        
        return begin != end;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
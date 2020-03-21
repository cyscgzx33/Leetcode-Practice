
// very similar to the logic of flaten_2d_vector.cpp

class ZigzagIterator {
    vector<int>::iterator begin1, begin2, end1, end2;
    bool process1;
public:
    /*
    * @param v1: A 1d vector
    * @param v2: A 1d vector
    */ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        begin1 = v1.begin();
        end1 = v1.end();
        begin2 = v2.begin();
        end2 = v2.end();
        process1 = true;
    }

    /*
     * @return: An integer
     */
    int next() {
        // write your code here
        if (begin1 != end1 && begin2 != end2)
        {
            if (process1)
            {
                process1 = false;
                return *begin1++;
            }
            else
            {
                process1 = true;
                return *begin2++;
            }
        }
        else if (begin1 != end1)
            return *begin1++;
        else
            return *begin2++;
    }

    /*
     * @return: True if has next
     */
    bool hasNext() {
        // write your code here
        return begin1 != end1 || begin2 != end2;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator solution(v1, v2);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */
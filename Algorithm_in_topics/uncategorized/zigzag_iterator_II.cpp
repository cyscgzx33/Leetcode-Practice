class ZigzagIterator2 {
    vector<vector<int>::iterator> begins, ends;
    int n; // size of given vector
    int itor; // index iterator
public:
    /*
    * @param vecs: a list of 1d vectors
    */
    ZigzagIterator2(vector<vector<int>>& vecs) {
        n = vecs.size();
        for (int i = 0; i < n; i++)
        {
            begins.push_back(vecs[i].begin());
            ends.push_back(vecs[i].end());
        }
        itor = -1;
    }

    /*
     * @return: An integer
     */
    int next() {
        for (int i = 0; i < n; i++) // technically, most execute n times
        {
            itor = (itor + 1) % n;
            if (begins[itor] != ends[itor])
                return *begins[itor]++;
        }
    }

    /*
     * @return: True if has next
     */
    bool hasNext() {
        // write your code here
        for (int i = 0; i < n; i++)
        {
            if (begins[i] != ends[i])
                return true;
        }
        return false;
    }
};

/**
 * Your ZigzagIterator2 object will be instantiated and called as such:
 * ZigzagIterator2 solution(vecs);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */
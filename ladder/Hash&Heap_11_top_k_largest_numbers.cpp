class Solution {
public:
    struct Comparator {
        bool operator() (const int left, const int right) {
            return left > right;
        }
    };

    /*
    * @param k: An integer
    */Solution(int k) : size_(0), k_(k) {}

    /*
     * @param num: Number to be added
     * @return: nothing
     */
    void add(int num) {
        // write your code here
    }

    /*
     * @return: Top k element
     */
    vector<int> topk() {
        // write your code here
    }
private:
    int k_;
    int size_;
    std::priority_queue<int, std::vector<int>, Comparator> pq_;
};
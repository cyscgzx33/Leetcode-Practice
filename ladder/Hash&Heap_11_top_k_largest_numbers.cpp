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
        pq_.push(num);
        size_++;
        if (size_ > k_) pq_.pop();  
    }

    /*
     * @return: Top k element
     */
    vector<int> topk() {
        // write your code here
        std::vector<int> topk;
        int n = pq_.size();
        for (int i = 0; i < k_ && i < n; i++) {
            topk.push_back( pq_.top() );
            pq_.pop();
        }

        for (int i = 0; i < n; i++) {
            pq_.push( topk[i] );
        }

        std::sort( topk.begin(), topk.end(), Comparator );
        return topk;
    }
private:
    int k_;
    int size_;
    std::priority_queue<int, std::vector<int>, Comparator> pq_;
};
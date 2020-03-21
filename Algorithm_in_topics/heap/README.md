**Heap**
---
* Very common in topics related to **Kth** or **K elements**, such as *Kth largest*, *Kth smallest*, *top K ...*, *sliding window*, and etc.
* Some template about how to customize C++ STL `std::priority_queue` with customized type `Node` and its corresponding comparator `Compare`:
    ```c++
    class Node
    {
    public:
        int val;
        int row;
        int col;
        Node(int v, int r, int c) : val(v), row(r), col(c) {}
    };

    class Compare
    {
    public:
        bool operator() (Node& a, Node& b)
        {
            return a.val > b.val;
        }
    };

    int main(int argc, char** argv)
    {
        // ...

        // how to customize a heap (priority_queue) with customized type and its corresponding comparator
        std::priority_queue<Node, std::vector<Node>, Compare> pq;

        // ...
    }
    ```
* C++ provides some default comparator such as `greater<T>`

**Basic Sub-topics**
---
| # | Sub-topic | Classic Examples |
|---| --------- | ---------------- |
|1|Using `priority_queue`| [Kth largest element II](kth_largest_element_ii.cpp), [Kth smallest number in sorted matrix](Kth_Smallest_Number_in_Sorted_Matrix.cpp)
|2|Using `multiset`| [Sliding window median](sliding_window_median.cpp)
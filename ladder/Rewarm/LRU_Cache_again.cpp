#include <list>

class LRUCache {
  public:
    struct LRUNode 
    {
        int key;
        int val;

        LRUNode(int k, int v) : key(k), val(v) {}
    };

    /*
    * @param capacity: An integer
    */LRUCache(int capacity) : capacity_(capacity) {}

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) 
    {
        if (key_to_listIter_.count(key) == 0)
            return -1;
        moveToFront(key);
        return values_.front().val;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) 
    {
        if (key_to_listIter_.count(key) > 0)
        {
            key_to_listIter_[key]->val = value;
            moveToFront(key);
        }
        else
        {   
            values_.emplace_front(key, value);
            key_to_listIter_[key] = values_.begin();
            if ( values_.size() > capacity_ )
            {
                key_to_listIter_.erase( values_.back().key );
                values_.pop_back();
            }
        }
    }

  private:
    int capacity_;
    std::unordered_map<int, std::list<LRUNode>::iterator> key_to_listIter_;
    std::list<LRUNode> values_;

    void moveToFront(int key)
    {
        values_.splice( values_.begin(), values_, key_to_listIter_[key] );
        key_to_listIter_[key] = values_.begin();
    }
};

// LRUCache(2)
// set(2, 1)
// set(1, 1)
// get(2)
// set(4, 1)
// get(1)
// get(2)

// Output
// [-1,-1,-1]
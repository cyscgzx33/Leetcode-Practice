#include <list>

class LRUCache {
  public:
    struct LRUNode {
        int key;
        int value;

        LRUNode(int k, int v) : key(k), value(v) {}
    };

    /*
    * @param capacity: An integer
    */LRUCache(int capacity) : capacity_(capacity) {}

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        if (key_to_listIter_.count(key) == 0) return -1;
        moveToForward(key);
        return values_.front().value;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        if (key_to_listIter_.count(key) == 0)
        {   
            values_.emplace_front(key, value);
            key_to_listIter_[key] = values_.begin();
            if (values_.size() > capacity_)
            {
                key_to_listIter_.erase(values_.back().key); // not erase key!!!!!!!
                values_.pop_back();
            }
        }
        else
        {   
            key_to_listIter_[key]->value = value;
            moveToForward(key);
        }
    }
  private:
    int capacity_;
    std::list<LRUNode> values_;
    std::unordered_map<int, std::list<LRUNode>::iterator> key_to_listIter_;
    void moveToForward(int key)
    {   
        // move the iterator containing [key] to .begin()
        values_.splice( values_.begin(), values_, key_to_listIter_[key] );
        // remember to update the map information as well
        key_to_listIter_[key] = values_.begin();
    }
};

/* 
 * [Input]
 * LRUCache(2)
 * set(2, 1)
 * set(1, 1)
 * get(2)
 * set(4, 1)
 * get(1)
 * get(2)
 *
 * [Output]
 * [1,1,1]
 *
 * [Expected]
 * [1,-1,1]
 */
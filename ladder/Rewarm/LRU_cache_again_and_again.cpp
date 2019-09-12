#include <list>

class LRUCache {
  public:
    struct LRUNode
    {
      public:
        int key;
        int val;

        LRUNode(int k, int v) : key(k), val(v) {}
    };

    /*
    * @param capacity: An integer
    */
    LRUCache(int capacity) : capacity_(capacity) {}

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) 
    {
        if (key_to_listIter_.count(key) == 0)
            return -1;
        else
        {
            moveForward(key);
            return values_.front().val;
        }
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void put(int key, int value) 
    {
        if (key_to_listIter_.count(key) == 0)
        {   
            values_.emplace_front(key, value);
            key_to_listIter_[key] = values_.begin();

            if (values_.size() > capacity_)
            {
                key_to_listIter_.erase(values_.back().key);
                values_.pop_back();
            }
        }
        else
        {
            moveForward(key);
            values_.front().val = value;
        }
    }

  private:
    int capacity_;
    std::list<LRUNode> values_;
    std::unordered_map<int, std::list<LRUNode>::iterator> key_to_listIter_;

    void moveForward(int key)
    {
        values_.splice( values_.begin(), values_, key_to_listIter_[key] );
        key_to_listIter_[key] = values_.begin();
    }
};
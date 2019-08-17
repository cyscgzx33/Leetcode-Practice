class LRUCache {
public:
    struct LRUNode {
      public:
        int value;
        int key;

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
        if (key_to_node_.count(key) == 0) return -1;
        moveFront(key);
        return values_.front().value;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        if (key_to_node_.count(key) == 0) {
            values_.emplace_front(key, value);
            key_to_node_[key] = values_.begin();
            if (values_.size() > capacity_) {
                key_to_node_.erase(values_.back().key);
                values_.pop_back();
            }
        } else {
            key_to_node_[key]->value = value;
            moveFront(key);
        }
    }

private:
    int capacity_;
    std::list<LRUNode> values_;
    std::unordered_map<int, list<LRUNode>::iterator> key_to_node_;

    void moveFront(int key) {
        values_.splice( values_.begin(), values_, key_to_node_[key] ); // change position
        key_to_node_[key] = values_.begin();
    }
};
class LRUCache {
public:

	class LRUNode
	{
	  public:
	  	int key;
	  	int val;
	  	LRUNode(int k, int v) : key(k), val(v) {}
	};

    LRUCache(int capacity) : capacity_(capacity) {}
    
    int get(int key) {
        if (key_to_listIter_.count(key) == 0)
        	return -1;

        auto tar_iter = key_to_listIter_[key];
        int tar = (*tar_iter).val;

        lru_nodes_.splice(lru_nodes_.end(), lru_nodes_, tar_iter);
        key_to_listIter_[key] = --lru_nodes_.end(); // move from end() to end()--

        return tar;
    }
    
    void put(int key, int value) {
    	if (key_to_listIter_.count(key) > 0)
    	{
    		auto tar_iter = key_to_listIter_[key];
    		(*tar_iter).val = value;
                        
    		lru_nodes_.splice(lru_nodes_.end(), lru_nodes_, tar_iter);
    		key_to_listIter_[key] = --lru_nodes_.end(); // move from end() to end()--
    	}
    	else
    	{
	        lru_nodes_.emplace_back( key, value );

	        if (lru_nodes_.size() > capacity_)
			{
				key_to_listIter_.erase(lru_nodes_.front().key);
				lru_nodes_.pop_front();
			}
	        key_to_listIter_[key] = --lru_nodes_.end(); // move from end() to end()--
    	}
    }
private:
	int capacity_;
	std::list<LRUNode> lru_nodes_;
	std::unordered_map<int, std::list<LRUNode>::iterator> key_to_listIter_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {}
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        // write your code here
        bool is_existent = num_index_map.count(val) > 0;
        if (!is_existent) num_index_map[val] = std::vector<int> {};
        num_index_map[val].push_back( num_index.size() );
        num_index.push_back(val);

        return !is_existent;
        
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        // write your code here
        if (num_index_map.count(val) == 0) return false;

        int cur_index = num_index_map[val].back();
        int last_index = num_index.size() - 1;
        int target = num_index[last_index];

        num_index[cur_index] = num_index[last_index];
        num_index.pop_back();
        int last_pos = num_index_map[target].size() - 1;
        num_index_map[target][last_pos] = cur_index;

        num_index_map[val].pop_back();

        if (num_index_map[val].size() == 0) num_index_map.erase(val);
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        // write your code here
        return num_index[ rand() % num_index.size() ];
    }

private:
    std::unordered_map< int, std::vector<int> > num_index_map;
    std::vector<int> num_index;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
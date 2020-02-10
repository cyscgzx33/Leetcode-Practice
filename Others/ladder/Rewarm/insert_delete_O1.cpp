class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) 
    {
        bool is_exist = val_2_idx_.count(val) == 0;

        if (!is_exist)
            return is_exist;

        val_2_idx_[val] = values_.size();
        values_.push_back(val);
        return is_exist;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) 
    {
        if (val_2_idx_.count(val) == 0)
            return false;
        int val_idx = val_2_idx_[val];
        int last_val = values_.back();
        values_[val_idx] = last_val;
        val_2_idx_[last_val] = val_idx;
        val_2_idx_.erase(val);
        values_.pop_back();

        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() 
    {
        return values_[ rand() % values_.size() ];
    }

private:
    std::vector<int> values_;
    std::unordered_map<int, int> val_2_idx_;
};

["RandomizedSet","insert","remove","insert","getRandom","remove","insert","getRandom"]
[[],             [1],     [2],     [2],     [],         [1],     [2],     []]
Output
[null,           true,    false,   true,    2,          true,    true,    2]
Expected
[null,           true,    false,   true,    2,          true,    false,   2]
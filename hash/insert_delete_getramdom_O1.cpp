class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {}
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) 
    {
        if (val_to_idx_.count(val) == 0)
        {
            value_pairs_.push_back( {val, 0} );
            val_to_idx_.insert( { val, std::vector<int>{value_pairs_.size() - 1} } );
            return true;
        }
        else
        {
            value_pairs_.push_back( { val, val_to_idx_[val].size() } );
            val_to_idx_[val].push_back(value_pairs_.size() - 1);
            return false;
        }
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) 
    {   
        if (val_to_idx_.count(val) == 0)
            return false;

        // for example: value_pairs = [1, 2, 1, 3, 2, 3]
        //              value_pairs = [0, 0, 1, 0, 1, 1]
        //              val_to_idx  = {1   , 2,    3   }
        //                             |\    |\    |\
        //                             0,2   1,4   3,5
        //              val(tar)    = 1

        /* 1. get idx of the target val */
        int tar_idx = val_to_idx_[val].back();

        /* 2. get the back() pair of the value_pairs */
        auto last_pair = value_pairs_.back();

        /* 3. copy value_pairs info of last one to target */
        value_pairs_[tar_idx] = last_pair;

        /* 4. process the corresponding map info of last pair */
        val_to_idx_[last_pair.first][last_pair.second] = tar_idx;

        /* 5. remove the last pair */
        value_pairs_.pop_back();

        /* 6. remove map's val's back element */
        val_to_idx_[val].pop_back();
        if (val_to_idx_[val].size() == 0)
            val_to_idx_.erase(val);

        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() 
    {
        return value_pairs_[ rand() % value_pairs_.size() ].first;
    }
private:
    std::vector<std::pair<int, int>> value_pairs_; // { val, val_to_idx_[val] }
    std::unordered_map< int, std::vector<int> > val_to_idx_;
};
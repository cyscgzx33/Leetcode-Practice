/*
 We will keep a list to store all our elements. 
In order to make finding the index of elements we want to remove O(1)O(1), 
we will use a HashMap or dictionary to map values to all indices that have 
those values. To make this work each value will be mapped to a set of indices. 
The tricky part is properly updating the HashMap as we modify the list.

insert: Append the element to the list and add the index to HashMap[element].
remove: This is the tricky part. We find the index of the element using the HashMap. 
We use the trick discussed in the intuition to remove the element from the list 
in O(1)O(1). Since the last element in the list gets moved around, 
we have to update its value in the HashMap. 
We also have to get rid of the index of the element we removed from the HashMap.
getRandom: Sample a random element from the list.
*/

public class RandomizedCollection {
    ArrayList<Integer> lst;
    HashMap<Integer, Set<Integer>> idx;
    java.util.Random rand = new java.util.Random();
    /** Initialize your data structure here. */

    public RandomizedCollection() {
        lst = new ArrayList<Integer>();
	      idx = new HashMap<Integer, Set<Integer>>();
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    public boolean insert(int val) {
        if (!idx.containsKey(val)) idx.put(val, new LinkedHashSet<Integer>());
        idx.get(val).add(lst.size());
        lst.add(val);
        return idx.get(val).size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    public boolean remove(int val) {
        if (!idx.containsKey(val) || idx.get(val).size() == 0) return false;
	      int remove_idx = idx.get(val).iterator().next();
        idx.get(val).remove(remove_idx);
        int last = lst.get(lst.size() - 1);
        lst.set(remove_idx, last);
        idx.get(last).add(remove_idx);
        idx.get(last).remove(lst.size() - 1);

	      lst.remove(lst.size() - 1);
        return true;
    }

    /** Get a random element from the collection. */
    public int getRandom() {
        return lst.get(rand.nextInt(lst.size()));
    }
}

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val) != m.end()) return false;
        nums.emplace_back(val);
        m[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        int last = nums.back();
        m[last] = m[val];
        nums[m[val]] = last;
        nums.pop_back();
        m.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;
    unordered_map<int, int> m;
};

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {}
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto result = m.find(val) == m.end();
        
        m[val].push_back(nums.size());
        nums.push_back(pair<int, int>(val, m[val].size() - 1));
        
        return result;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto result = m.find(val) != m.end();
        if(result)
        {
            auto last = nums.back();
            m[last.first][last.second] = m[val].back();
            nums[m[val].back()] = last;
            m[val].pop_back();
            if(m[val].empty()) m.erase(val);
            nums.pop_back();
        }
        return result;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
private:
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> m;
};

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {}
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) 
    {
    	bool not_exist = val_indices_map_.count(val) == 0;
    	if (not_exist) // need to construct a vector
    		val_indices_map_.insert( { val, std::vector<int>{} } );
		val_indices_map_[val].push_back( val_idx_pairs_.size() );
		val_idx_pairs_.push_back( {val, val_indices_map_[val].size() - 1 } );

		// std::cout << "inserted : " << val << std::endl;

		return not_exist;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) 
    {
    	if (val_indices_map_.count(val) == 0)
    		return false;

    	// 1: find last pair
    	auto last_pair = val_idx_pairs_.back();
    	// 2: find target val idx
    	int tar_val_idx = val_indices_map_[val].back();
    	// std::cout << "tar_val_idx = " << tar_val_idx << std::endl;
    	// 3: copy the last pair to the target pair
    	val_idx_pairs_[tar_val_idx] = last_pair;
    	// 4: modify the last pair idx info @ hashmap
    	// std::cout << "last_pair.first = " << last_pair.first << "last_pair.second = " << last_pair.second << std::endl;
    	val_indices_map_[last_pair.first][last_pair.second] = tar_val_idx;
    	// 5: erase the last pair @ vec
    	val_idx_pairs_.pop_back();
    	// 6: erase the target val idx info @ hashmap
    	val_indices_map_[val].pop_back();
    	// 7: (tentative) if the map[val] vec is empty, erase it
    	if (val_indices_map_[val].size() == 0)
    		val_indices_map_.erase(val);

    	// std::cout << "removed : " << val << std::endl;

    	return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() 
    {
    	return val_idx_pairs_[ rand() % val_idx_pairs_.size() ].first;
    }
private:
	std::vector<std::pair<int, int>> val_idx_pairs_; // first: val, second: last ind of val_indices_map_[val]
	std::unordered_map<int, std::vector<int>> val_indices_map_;
};
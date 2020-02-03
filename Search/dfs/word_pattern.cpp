class Solution {
public:
    bool wordPattern(string pattern, string str) {        
        // process the str into a vector of str
        std::size_t curr, prev = 0;
        std::vector<std::string> str_vec;
        curr = str.find(' ');
        while (curr != std::string::npos)
        {
            str_vec.push_back( str.substr(prev, curr - prev) );
            prev = curr + 1;
            curr = str.find(' ', prev);
        }
        str_vec.push_back( str.substr(prev, curr - prev) );
        
        // major logic
        std::unordered_map<char, std::string> mapping;
        std::unordered_set<std::string> visit;
        if ( pattern.size() != str_vec.size() )
            return false;
        for (int i = 0; i < pattern.size(); i++)
        {
            char cur_ptn = pattern[i];
            if (mapping.count(cur_ptn) > 0)
            {
                if ( mapping[cur_ptn] != str_vec[i] )
                    return false;
            }
            else // cur_ptn is not chosen before
            {
                if (visit.count( str_vec[i] ) > 0) // however, the str_vec[i] is chosen before
                    return false;
                mapping[cur_ptn] = str_vec[i];
                visit.insert( str_vec[i] );
            }
        }
        
        return true;
    }
};
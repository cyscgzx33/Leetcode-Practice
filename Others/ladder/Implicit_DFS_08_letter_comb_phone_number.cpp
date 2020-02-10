class Solution {
public:
    void dfs(std::string& digits,
             std::unordered_map< char, std::vector<char> >& dict,
             int start_index,
             std::string& result,
             std::vector<std::string>& results,
             std::unordered_set<std::string>& word_dict)
    {   
        // check if the current result is in the word_dict
        if ( word_dict.count(result) == 0 ) return;

        if ( start_index == digits.size() ) {
            results.push_back(result);
            return;
        }
        char digit = digits[start_index];
        for (auto letter : dict[digit]) {
            result += letter;
            dfs(digits, dict, start_index + 1, result, results);
            result.pop_back();
        }
    }
    
    /**
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
    vector<string> letterCombinations(string &digits, unordered_set<string> word_dict) {
        // write your code here
        if (digits.size() == 0) return {};
        
        /* FOLLOW-UP: find wors only in the givin word_dict */
        std::unordered_set<std::string> prefix;
        
        // construct prefix: "abs" => ["", "a", "ab", "abc"]
        prefix.insert("");
        for (auto& elem : word_dict) {
            for (int i = 0; i < elem.size(); i++) {
                prefix.insert( elem.subsrt(0, i + 1) );
            }
        }

        std::unordered_map< char, std::vector<char> > dict;
        dict.insert( { { '2', {'a', 'b', 'c'} },
                       { '3', {'d', 'e', 'f'} },
                       { '4', {'g', 'h', 'i'} },
                       { '5', {'j', 'k', 'l'} },
                       { '6', {'m', 'n', 'o'} },
                       { '7', {'p', 'q', 'r', 's'} },
                       { '8', {'t', 'u', 'v'} },
                       { '9', {'w', 'x', 'y', 'z'} }
                     } );
        std::string result;
        std::vector<std::string> results;
        
        dfs(digits, dict, 0, result, results);
        return results;
        
    }
};
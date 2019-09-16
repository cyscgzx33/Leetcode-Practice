class Solution {
public:
    string decodeString(string s) {
        std::string tmp_str = "";
        std::stack<int> s_sum;
        std::stack<std::string> s_str;
        int cnt = 0; // count the length of the digits

        for (int i = 0; i < s.size(); i++)
        {
            if ( isdigit( s[i] ) )
                cnt = 10 * cnt + s[i] - '0';
            else if (s[i] == '[')
            {
                s_sum.push(cnt);
                s_str.push(tmp_str);
                cnt = 0;
                tmp_str.clear();
            }
            else if (s[i] == ']')
            {
                int k = s_sum.top();
                s_sum.pop();
                for (int j = 0; j < k; j++)
                    s_str.top() += tmp_str;
                tmp_str = s_str.top();
                s_str.pop();
            }
            else
                tmp_str += s[i];
        }

        return tmp_str; // no need to check if s_str is empty(), as it must be empty
    }
};
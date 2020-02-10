class Solution {
public:
    /**
     * @param envelopes a number of envelopes with widths and heights
     * @return the maximum number of envelopes
     */
    int maxEnvelopes(vector<pair<int, int>>& envelopes) 
    {
      std::sort(envelopes.begin(), envelopes.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first == b.first ? a.second > b.second : a.first < b.first;
      });
      std::vector<int> dp;

      for (auto& envelope : envelopes)
      {
        auto it = std::lower_bound(dp.begin(), dp.end(), envelope.second);
        if ( it == dp.end() )
          dp.push_back(envelope.second);
        else
          *it = envelope.second;
      }

      return dp.size();
    }
};
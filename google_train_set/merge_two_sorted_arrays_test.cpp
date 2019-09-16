#include <vector>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        std::cout << "3rd = " << findKthLargest(nums1, 0, nums2, 0, 3) << std::endl;
        // std::cout << "2nd = " << findKthLargest(nums1, 0, nums2, 0, 2) << std::endl;        
        // if ( (size1 + size2) % 2 == 0 )
        //     return double( findKthLargest(nums1, 0, nums2, 0, (size1 + size2) / 2 + 1) +  findKthLargest(nums1, 0, nums2, 0, (size1 + size2) / 2) ) / 2;
        // else
        //     return findKthLargest(nums1, 0, nums2, 0, (size1 + size2) / 2 + 1);
        
        return 0.0;

    }
    
    int findKthLargest(std::vector<int>& nums1,
                       int start1,
                       std::vector<int>& nums2,
                       int start2,
                       int k)
    {
        // scenario I: nums1 or nums2 are empty
        if ( start1 >= nums1.size() )
            return nums2[k - 1];
        if ( start2 >= nums2.size() )
            return nums1[k - 1];
        
        // Scenario II: k == 1
        if (k == 1)
            return min( nums1[start1], nums2[start2] );
        
        // Scenario III: nums1 or nums2 have smaller size than k/2
        if ( start1 + k / 2 - 1 >= nums1.size() )
        {
            std::cout << "sce III, if 1" << std::endl;
            return findKthLargest(nums1, start1, nums2, start2 + k/2, k - k/2);
        }
        if ( start2 + k / 2 - 1 >= nums2.size() )
            return findKthLargest(nums1, start1 + k/2, nums2, start2, k - k/2);
        
        // Scenario IV
        if ( nums1[start1 + k/2 -1] <= nums2[start2 + k/2 -1] )
            return findKthLargest(nums1, start1 + k/2, nums2, start2, k - k/2);
        else
        {   
            std::cout << "sce IV, if 2" << std::endl;
            return findKthLargest(nums1, start1, nums2, start2 + k/2, k - k/2);
        }
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);
        
        double ret = Solution().findMedianSortedArrays(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
class Solution {
public:
    /**
     * @param A: a integer array A,
     * @return: Return true if and only if after such a move
     */
    bool splitArraySameAverage(vector<int> &A) {
        // write your code here
        
        std::sort( A.begin(), A.end() );
        
        int len_A = A.size(), len_B = 0;
        
        int sum_A = 0;
        for (auto& num : A)
        {
            sum_A += num;
            std::cout << num << ", ";
        }
        std::cout << std::endl;

        double avg_A = double(sum_A) / len_A;
        double sum_B = 0, avg_B = 0;
        int right = std::lower_bound(A.begin(), A.end(), avg_A) - A.begin();
        int left = right - 1;
        std::vector<bool> used(len_A, false);

        while ()
        {
        	int next_target = avg_A * len_B - cur_choice;
        	int next_idx = std::lower_bound(A.begin(), A.end(), avg_A) - A.begin();
        	if ( !used[next_idx] )
        	{

        	}
        }

        while (left >= 0 && right < len_A)
        {   
            if (avg_B < avg_A)
            {
                sum_B += A[right];
                right++;
            }
            else if (avg_B == avg_A)
            {
                if (len_B < len_A)
                {
                    return true;
                }
            }
            else
            {
                sum_B += A[left];
                left--;
            }
            
            len_B++;
            avg_B = double(sum_B) / len_B;
        }
        
        if (avg_B == avg_A)
        {
            if (len_B < len_A)
                return true;
        }
        return false;
    }
};
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {

        // try to create a "D_int" vector that is basically the "same" as D, but contains int as elements
        vector<int> D_int;
        for(auto d:D) {
            int i = d[0] - '0';
            D_int.push_back(i);
        }
        // and, of course, sort it for next steps 
        sort(D_int.begin(), D_int.end());
        
        // try to obtain the length of N and D, for convenience of next steps
        string N_str;
        N_str = to_string(N);

        int bits_N = N_str.length();
        int D_num = D.size();

        // try to construct 3 vectors:
        // potential_largest means the sum of geometry sequence
        // qualifyBitNum indicates the nums of subset that is less than current bit
        // equalBitNum indicates the nums of the subset that is equal to current bit 
        vector<int> potential_largest(bits_N, 0);
        vector<int> qualifyBitNum(bits_N, 0);
        vector<int> equalBitNum(bits_N, 0);

        // now let's obtain the three vectors above
        int N_copy = N;
        for (int j = 0; j < bits_N; j++) {
            potential_largest[j] = D_num == 1 ? (j + 1) : D_num * (1 - pow(D_num, j+1)) / (1 - D_num);
            int curBit = N_copy % 10;
            N_copy = N_copy / 10;
            auto it = lower_bound(D_int.begin(), D_int.end(), curBit);
            qualifyBitNum[j] = it - D_int.begin();
            if (*it == curBit) {
                equalBitNum[j]++;
            }          
        }
        
        // for one bit input, just return the qualified bit number of it 
        if (bits_N == 1) return qualifyBitNum[bits_N-1] + equalBitNum[bits_N-1];

        // "bit" indicates the current highest bit index
        int bit = bits_N - 1;

        // "res" indicates the possible numbers with less bits than the input
        int res = potential_largest[bit - 1];
        // "additionalRes" indicates the possible numbers with same bits as the input
        int additionalRes = 0;

        // now let's deal with "additionalRes"

        while (bit >= 0) {

            additionalRes += pow(D_num, bit - 1 + 1) * qualifyBitNum[bit];
            if (equalBitNum[bit] == 1) {
                bit--;
                if (bit == -1) additionalRes += 1; // indicating that the algorithm reaches the last bit
            } else {
                break;
            }
        }
        
        return res + additionalRes;
        
    }
};
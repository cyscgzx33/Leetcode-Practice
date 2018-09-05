class Solution {
public:
	string orderlyQueue(string S, int K) {

		// case 0:
		// if K > 1, it can be mathematically proved that a final result equals to the sorted string can always be achieved
		if (K > 1) {
			sort(S.begin(), S.end());
			return S;
		}

		// case 1:
		// if K == 1, through mathematical provement, the achievable smallest result is ...
		if (K == 1) {
			string S_min = S;
			for (int i = 0; i < S.length(); i++) {
				// find the first indexed char
				string S_first_index (S, 0, 1); // string s1 (s0, size_t pos, size_t len)

				// find the rest of the string
				string S_rest = S;
				S_rest.erase(0, 1);

				// append the new string
				string S_new = S_rest;
				S_new = S_rest + S_first_index;

				// compare the S and S_new
				S_min = S_new < S_min ? S_new : S_min;

				// replace the S by S_new
				S = S_new;
			}

			return S_min;
		}

	}
};
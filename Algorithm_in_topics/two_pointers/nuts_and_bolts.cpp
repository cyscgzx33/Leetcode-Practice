/**
 * class Comparator {
 *     public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/

class Solution {
private:
	void quickSort(vector<string>& nuts,
				   vector<string>& bolts,
				   Comparator comp,
				   int start, int end)
	{
		if (start >= end)
			return;

		// step I: find the pivot position in nuts, such that nuts[pivot] == bolts[start]
		int pivot = start, cnt_smaller = 0;
		for (int i = start; i <= end; i++)
		{
			if (comp.cmp(nuts[i], bolts[start]) == -1)
				cnt_smaller++;
			if (comp.cmp(nuts[i], bolts[start]) == 0)
				pivot = i;
		}
		cnt_smaller += start; // Note: important to take care of!!!
		swap(nuts[cnt_smaller], nuts[pivot]);
		pivot = cnt_smaller;

		cout << "start = " << start
			 << ", end = " << end
			 << ", pivot = " << pivot << endl;

		// step II: quicksort for nuts
        int l = pivot - 1, r = pivot + 1;
        while (l >= start && r <= end)
        {
        	while (l >= start && comp.cmp(nuts[l], bolts[start]) == -1)
        		l--;
        	while (r <= end && comp.cmp(nuts[r], bolts[start]) == 1)
        		r++;
        	if (l >= start && r <= end)
        		swap(nuts[l--], nuts[r++]);
        }
        cout << "pivot = " << pivot;
		cout << ", nuts[pivot] = " << nuts[pivot] << "\n";

		// step III: quicksort for bolts
		swap(bolts[start], bolts[pivot]);
		l = pivot - 1; r = pivot + 1;
		while (l >= start && r <= end)
		{
			while (l >= start && comp.cmp(nuts[pivot], bolts[l]) == 1)
				l--;
			while (r <= end && comp.cmp(nuts[pivot], bolts[r]) == -1)
				r++;
			if (l >= start && r <= end)
				swap(bolts[l--], bolts[r++]);
		}

		quickSort(nuts, bolts, comp, start, pivot - 1);
		quickSort(nuts, bolts, comp, pivot + 1, end);
	}

public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        // write your code here
        quickSort(nuts, bolts, compare, 0, nuts.size() - 1);
        
        for (int i = 0; i < nuts.size(); i++)
        {
            cout << compare.cmp(nuts[i], bolts[i]) << ", ";
        }
        
    }
};
class Solution {
public:
	int searchUpperBound(std::vector<std::vector<char>>& image,
						 int x, int y)
	{
		int row = image.size(), col = image[0].size();
		int start = 0, end = x;

		while (start + 1 < end)
		{
			int mid = start + (end - start) / 2;
			int idx = 0;
			while ( idx < col && image[mid][idx] == '0' )
				idx++;
			if (idx < col) // at row mid, there exists 1
				end = mid;
			else
				start = mid;
		}

		int idx = 0;
		while ( idx < col && image[start][idx] == '0' )
			idx++;
		if (idx < col)
			return start;
		else
			return end;
	}

	int searchLowerBound(std::vector<std::vector<char>>& image,
						 int x, int y)
	{
		int row = image.size(), col = image[0].size();
		int start = x, end = row - 1;

		while (start + 1 < end)
		{
			int mid = start + (end - start) / 2;
			int idx = 0;
			while ( idx < col && image[mid][idx] == '0' )
				idx++;
			if (idx < col) // at row mid, there exists 1
				start = mid;
			else
				end = mid;
		}

		int idx = 0;
		while ( idx < col && image[end][idx] == '0' )
			idx++;
		if (idx < col)
			return end;
		else
			return start;
	}

	int searchLeftBound(std::vector<std::vector<char>>& image,
						 int x, int y)
	{
		int row = image.size(), col = image[0].size();
		int start = 0, end = y;

		while (start + 1 < end)
		{
			int mid = start + (end - start) / 2;
			int idx = 0;
			while ( idx < row && image[idx][mid] == '0' )
				idx++;
			if (idx < row) // at row mid, there exists 1
				end = mid;
			else
				start = mid;
		}

		int idx = 0;
		while ( idx < row && image[idx][start] == '0' )
			idx++;
		if (idx < row)
			return start;
		else
			return end;
	}

	int searchRightBound(std::vector<std::vector<char>>& image,
						 int x, int y)
	{
		int row = image.size(), col = image[0].size();
		int start = y, end = col - 1;

		while (start + 1 < end)
		{
			int mid = start + (end - start) / 2;
			int idx = 0;
			while ( idx < row && image[idx][mid] == '0' )
				idx++;
			if (idx < row) // at row mid, there exists 1
				start = mid;
			else
				end = mid;
		}

		int idx = 0;
		while ( idx < row && image[idx][end] == '0' )
			idx++;
		if (idx < row)
			return end;
		else
			return start;
	}

    /**
     * @param image: a binary matrix with '0' and '1'
     * @param x: the location of one of the black pixels
     * @param y: the location of one of the black pixels
     * @return: an integer
     */
    int minArea(vector<vector<char>> &image, int x, int y) {
        // write your code here
        int row = image.size();
        int col = image[0].size();

        int upper_bound = searchUpperBound(image, x, y);
        int lower_bound = searchLowerBound(image, x, y);
        int left_bound  = searchLeftBound(image, x, y);
        int right_bound = searchRightBound(image, x, y);

        return (right_bound - left_bound + 1) * (upper_bound - lower_bound + 1);
    }
};
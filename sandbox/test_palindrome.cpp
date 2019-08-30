#include <string>
#include <iostream>
#include <vetcor>

std::vector<std::string> countPalindrome(std::string& str)
{
	int n = str.size();
	int i = 0;
	while (i < 2 * n - 1)
	{	int left = i / 2, right = i / 2;
		if (i % 2 ==  1) right++;
		while ( left >= 0 && right < n && str[left] == str[right] )
		{
			left--;
			right++;
		}

	}
}

int main()
{
	std::string test_1 = "asdasjfkasjdaslkewrjrkfgjsjakhdajskfhaasdjaskwalekjkasdjaksjfsdjas";
	std::string test_2 = "abcbajksdaadksdwqkalklajfksjdkewlkj";
	std::vetcor<std::string> res_1 = countPalindrome(test_1);
	std::vector<std::string> res_2 = countPalindrome(test_2);

	return 0;
}
#include <iostream>
#include <stack>

std::string decodeString(std::string& str)
{
	if (str.size() == 0)
		return "";

	std::stack<char> stk;

	int idx = 0;
	while ( idx < str.size() )
	{
		while ( idx < str.size() && str[idx] != ']' )
		{
			stk.push( str[idx] );
			idx++;
		}

		if ( idx >= str.size() )
			break;

		// currently, str[idx] == ']'
		std::string tmp = "";
		while ( stk.top() != '[' )
		{
			tmp += stk.top();
			stk.pop();
		}

		// currently, stk.top() == '['
		// remove the '['
		stk.pop(); 
		// obtain the times and remove from the stk
		int times = stk.top() - '0'; 
		stk.pop();
		std::string duplicate = "";
		for (int i = 0; i < times; i++)
			duplicate += tmp;
		// put the tmp back to stk again
		for (int i = duplicate.size() - 1; i >= 0; i--)
			stk.push( duplicate[i] );

		// process of "[]" finished, move to next idx
		idx++;
	}

	std::string res = "";
	while (stk.size() > 0)
	{
		res = stk.top() + res;
		stk.pop();
	}

	return res;
}
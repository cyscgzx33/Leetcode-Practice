#include <iostream>
#include <string>

int main()
{
	std::string test_str_1 = "HelloHelloHelloWorld!";
	int first_index = test_str_1.rfind("Hello", 0);
	int last_index = test_str_1.rfind("Hello");
	int middle_index = test_str_1.rfind("Hello", 1);

	std::cout << "first_index = " << first_index << std::endl;
	std::cout << "last_index = " << last_index << std::endl;
	std::cout << "middle_index = " << middle_index << std::endl;
 
	return 0;
}
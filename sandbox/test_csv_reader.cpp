#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main()
{
	std::string roadmap_file_name = "/home/honda/git/UdacityMPC/mpc_to_line/roadmap.csv";
	std::ifstream roadmap_data( roadmap_file_name.c_str() );
	std::vector<std::vector<double>> wps;

	if ( roadmap_data.is_open() )
	{
	  std::string line;
	  while ( std::getline( roadmap_data, line ) )
	  {
	  	std::istringstream line_stream(line);
	  	std::string num;
	  	std::vector<double> wp;
	  	while ( std::getline(line_stream, num, ',') )
	  		wp.push_back( std::stod(num) );
	  	wps.push_back(wp);
	  }
	}
	else
		std::cout << "error of opening file" << std::endl;

	// print out results
	for (auto wp_line : wps)
	{
		int i = 0;
		std::cout << "Line #" << i << ": ";
		for (auto wp_num : wp_line)
			std::cout << wp_num << ", ";
		i++;
		std::cout << std::endl;
	}

	return 0;
}
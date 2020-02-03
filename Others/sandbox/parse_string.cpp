#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>


template <class Container>
void splitString(const std::string& str,
	             Container& cont,
	             char delim = ',')
{
	std::size_t curr, prev = 0;
	curr = str.find(delim);
	while (curr != std::string::npos)
	{
		cont.push_back( str.substr(prev, curr - prev) );
		prev = curr + 1;
		curr = str.find(delim, prev);
	}
	cont.push_back( str.substr(prev, curr - prev) );
}

template <class Container>
void parseString(Container& cont)
{
	// cont[6] : longitudinal offset distance [m]
	float long_offset_dist  = std::stof( cont[6] );
	// cont[7] : lateral offset distance [m]
	float lat_offset_dist   = std::stof( cont[7] );
	// cont[8] : relative speed [m/s]
	float rltv_spd_mps      = std::stof( cont[8] );
	// cont[9] : absolute speed [m/s]
	float abs_spd_mps       = std::stof( cont[9] );
	// cont[10]: absolute accel [m/s^2]
	float abs_accel_mpss    = std::stof( cont[10] );
	// cont[11]: relative heading angle [deg]
	float rltv_head_ang_deg = std::stof( cont[11] );
	// cont[12]: right turn signal
	int right_turn_sig      = std::stoi( cont[12] );
	// cont[13]: left turn signal
	int left_turn_sig       = std::stoi( cont[13] );

	std::cout << "long_offset_dist = " << long_offset_dist << '\n'
			  << "lat_offset_dist = " << lat_offset_dist << '\n'
			  << "left_turn_sig = "  << left_turn_sig << '\n'
			  << "rltv_spd_mps = " << rltv_spd_mps << '\n'
			  << "abs_spd_mps = "  << abs_spd_mps << '\n'
			  << "rltv_head_ang_deg = " << rltv_head_ang_deg << '\n'
			  << "right_turn_sig = " << right_turn_sig << '\n'
			  << "left_turn_sig = "  << left_turn_sig
			  << "\n";
}

template <class Container>
void performTest(const std::string& str,
	             Container& cont,
	             char delim = ',')
{
	splitString(str, cont, delim);
	std::cout << "cont.size() = " << cont.size() << '\n';
	for (auto elem : cont)
		std::cout << elem << ", ";
	std::cout << std::endl;

	parseString(cont);
}

int main(int argc, char** argv)
{

	// std::string t_str_1 = "abs,crv,mkz,suv,vda";
	// std::vector<std::string> t_cont_1;
	// performTest(t_str_1, t_cont_1, ',');

	std::string t_str_2 = "1571416275839,RX,234,258813,110.450048,13,-2.635309,7.177040,-0.445542,9.620000,0.390000,0.287500,0,0";
	std::vector<std::string> t_cont_2;
	performTest(t_str_2, t_cont_2, ',');

	return 0;
}
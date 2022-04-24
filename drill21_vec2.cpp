#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>

class Less_than {
	double v;
public:
	Less_than(double vv) : v{vv}{}
	bool operator()(const double val) {return val < v;}
};

template <typename C>
void print(const C& c, char sep = '\n'){
	std::cout << "Container elements:\n";
	
	for(const auto elem : c){
		std::cout << elem << sep;
	}
	std::cout << std::endl;
}

int main()
try {

	const std::string iname {"input_floats.txt"};
	std::ifstream ifs {iname};
	if (!ifs) throw std::runtime_error("Could not read file: " + iname);
	
	std::vector<double> vd;
	for(double d; ifs >> d; ){
		vd.push_back(d);
	}
	
	print(vd);
	
	std::vector<int> vi(vd.size());
	/*for(auto i : vd){
		vi.push_back(i);
	}*/
	std::copy(vd.begin(), vd.end(), vi.begin());
	print(vi);
	
	for(int i = 0; i < vd.size(); i++){
		std::cout << vd[i] << '\t' << vi[i] << std::endl;
	}
	
	//std::cout.precision(10);
	
	double vd_sum = 0;
	for(int i = 0; i < vd.size(); i++){
		vd_sum += vd[i];
	}
	std::cout << "A vd vektor értékeinek összege: " << vd_sum << std::endl;
	
	double vi_sum = 0;
	for(int i = 0; i < vi.size(); i++){
		vi_sum += vi[i];
	}
	std::cout << "A vi vekor értékeinek összege: " << vi_sum << std::endl;
	
	double diff = vd_sum - vi_sum;
	std::cout << "A két vektor különbsége: " << diff << std::endl << std::endl;
	
	std::reverse(vd.begin(), vd.end());
	print(vd);
	
	double vd_mean = vd_sum / vd.size();
	std::cout << "A két vektor átlaga: " << vd_mean << std::endl << std::endl;
	
	std::vector<double> vd2(vd.size());
	/*for(int i = 0; i < vd.size(); i++){ --ez működik, csak a nullákat is benne hagyja
		if(vd[i] < vd_mean){
			vd2.push_back(vd[i]);
		}
	}*/
	auto it = std::copy_if(vd.begin(), vd.end(), vd2.begin(), Less_than(vd_mean));
	vd2.resize(std::distance(vd2.begin(), it));
	print(vd2);
	
	std::sort(vd.begin(), vd.end());
	print(vd);

} catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
} catch(...) {
	std::cout << "Unknown exception\n";
	return 2;
}

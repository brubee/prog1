#include <iostream>
#include <stdexcept>
#include <map>
#include <string>
#include <numeric>

template <typename K, typename V>
void print(const std::map<K, V>& m){
	for(auto i : m){ // = (std::pair<K, V> i : m)
		std::cout << i.first << '\t' << i.second << std::endl;
	}
}

void read_map(std::map<std::string, int>& m){
	std::string s;
	int i = 0;
	while(m.size() < 10){
		std::cin >> s >> i;
		// m[s] = i; ez akkor jobb, ha felül akarjuk írni az értéket
		m.insert(std::make_pair(s, i)); // ez akkor jobb, ha nem akarjuk felülírni
	}
}

int main()
try {

	std::map<std::string, int> msi;
	msi["a"] = 2;
	msi["b"] = 3;
	msi["abc"] = 4;
	msi["cd"] = 5;
	msi["qwert"] = 2;
	msi["po"] = 32;
	msi["xy"] = 4;
	msi["zs"] = 91;
	msi["ac"] = 79;
	msi["ax"] = 81;
	
	print(msi);
	
	msi.erase("a");
	
	std::cout << "\nEgy elem törlése után:\n";
	print(msi);
	
	msi.erase(msi.begin(), msi.end());
	std::cout << "\nTeljes törlés után:\n";
	print(msi);
	
	std::cout << "\nAdj meg 10 kulcs-érték párt!\n";
	read_map(msi);
	std::cout << std::endl;
	print(msi);
	
	int sum = 0;
	for(std::pair<std::string, int> a : msi){
		sum += a.second;
	}
	std::cout << "A megadott értékek összege: " << sum << std::endl;
	
	std::map<int, std::string> mis;
	for(std::pair<std::string, int> a : msi){
		mis[a.second] = a.first;
		//mis.insert(std::make_pair(a.second, a.first));
	}
	
	std::cout << "\nmis map:\n";
	print(mis);

} catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
} catch(...) {
	std::cout << "Unknown exception\n";
	return 2;
}

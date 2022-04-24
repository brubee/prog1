#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <string>

struct Item {
	std::string name;
	int iid;
	double value;
};

void print_v(const std::vector<Item>& v){
	for(auto& i : v){
		std::cout << i.name << '\t' << i.iid << '\t' << i.value << std::endl;
	}
}

void print_l(const std::list<Item> l){
	for(auto& i : l){
		std::cout << i.name << '\t' << i.iid << '\t' << i.value << std::endl;
	}
}

struct sort_name {
	bool operator()(const Item& a, const Item& b) const {
		return a.name < b.name;
	}
};

struct sort_iid {
	bool operator()(const Item& a, const Item& b) const {
		return a.iid < b.iid;
	}
};

struct sort_value {
	bool operator()(const Item& a, const Item& b) const {
		return b.value < a.value;
	}
};

int main()
try {

	//vector
	const std::string iname {"item_list.txt"};
	std::ifstream ifs {iname};
	if(!ifs) throw std::runtime_error("Could not read file: " + iname);
	
	std::vector<Item> vi(10);
	for(auto& i : vi){
		ifs >> i.name >> i.iid >> i.value;
	}
	ifs.close();
	std::cout << "The vector:\n";
	print_v(vi);
	std::cout << std::endl;
	
	//list
	std::list<Item> li(vi.size());
	std::copy(vi.begin(), vi.end(), li.begin());
	std::cout << "The list:\n";
	print_l(li);
	
	
	//sorting vector
	std::cout << std::endl;
	std::cout << "Sorting vector by name:\n";
	std::sort(vi.begin(), vi.end(), sort_name());
	print_v(vi);
	
	std::cout << std::endl;
	std::cout << "Sorting vector by iid:\n";
	std::sort(vi.begin(), vi.end(), sort_iid());
	print_v(vi);
	
	std::cout << std::endl;
	std::cout << "Sorting vector by value:\n";
	std::sort(vi.begin(), vi.end(), sort_value());
	print_v(vi);
	
	//sorting list
	std::cout << std::endl;
	std::cout << "Sorting list by name:\n";
	li.sort([](const Item& a, const Item& b) {return a.name < b.name;});
	print_l(li);
	
	std::cout << std::endl;
	std::cout << "Sorting list by iid:\n";
	li.sort([](const Item& a, const Item& b) {return a.iid < b.iid;});
	print_l(li);
	
	std::cout << std::endl;
	std::cout << "Sorting list by value:\n";
	li.sort([](const Item& a, const Item& b) {return b.value < a.value;});
	print_l(li);
	
	
	//removing items from vector
	std::cout << std::endl;
	std::cout << "Inserting item: horse shoe, 99, 12.34\n";
	std::cout << "Inserting item: Canon S400, 9988, 499.95\n";
	vi.push_back(Item{"horse shoe", 99, 12.34});
	vi.push_back(Item{"Canon S400", 9988, 499.95});
	print_v(vi);
	
	std::cout << std::endl;
	std::cout << "Erasing names 'coat' and 'laptop' from vector:\n";
	vi.erase(find_if(vi.begin(), vi.end(), [] (Item i) {return i.name == "coat";}));
	vi.erase(find_if(vi.begin(), vi.end(), [] (Item i) {return i.name == "laptop";}));
	print_v(vi);
	
	std::cout << std::endl;
	std::cout << "Erasing iids '5' and '9' from vector:\n";
	vi.erase(find_if(vi.begin(), vi.end(), [] (Item i) {return i.iid == 5;}));
	vi.erase(find_if(vi.begin(), vi.end(), [] (Item i) {return i.iid == 9;}));
	print_v(vi);
	
	//removing items from list
	std::cout << std::endl;
	std::cout << "Erasing names 'coat' and 'laptop' from list:\n";
	li.erase(find_if(li.begin(), li.end(), [] (Item i) {return i.name == "coat";}));
	li.erase(find_if(li.begin(), li.end(), [] (Item i) {return i.name == "laptop";}));
	print_l(li);
	
	std::cout << std::endl;
	std::cout << "Erasing iids '5' and '9' from list:\n";
	li.erase(find_if(li.begin(), li.end(), [] (Item i) {return i.iid == 5;}));
	li.erase(find_if(li.begin(), li.end(), [] (Item i) {return i.iid == 9;}));
	print_l(li);

} catch(std::exception& e) {
	std::cout << "Exception: " << e.what() << std::endl;
	return 1;
} catch(...) {
	std::cout << "Unknown exception\n";
	return 2;
}

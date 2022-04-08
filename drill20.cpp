#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <list>
#include <array>
#include <string>

template <typename C>
void print_contents(const C& c){
	for(auto& a : c){
		std::cout << a << " ";
	}
	std::cout << std::endl;
}

template <typename C>
void inc(C& c, int n){
	for(auto& a : c){
		a += n;
	}
}

template <typename Iter1, typename Iter2>
// requires Input_operator<Iter1>() && Output_operator<Iter2()>
Iter2 copyy(Iter1 f1, Iter1 e1, Iter2 f2){
	for(Iter1 p = f1; p != e1; ++p){
		*f2++ = *p;
	}
	return f2;
}

int main()
try {

	/*
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	vector<int> v;
	for(int i = 0; i < 10; i++){
		v.push_back(a[i]);
	}
	for(int j = 0; j < 10; j++){
		std::cout << a[j] << '\t' << v[j] << std::endl;
	}
	*/
	
	constexpr int size = 10;
	
	int arr [size];
	for(int i = 0; i < size; i++){
		arr[i] = i;
	}
	
	std::array<int, size> ai;
	std::copy(arr, arr + size, ai.begin());
	
	std::vector<int> vi(size);
	std::copy(arr, arr + size, vi.begin());
	
	std::list<int> li(size);
	std::copy(arr, arr + size, li.begin());
	
	std::cout << "Array: \n";
	print_contents(ai);
	std::cout << "Vector: \n";
	print_contents(vi);
	std::cout << "List: \n";
	print_contents(li);
	
	std::array<int, size> ai2 = ai;
	std::vector<int> vi2 = vi;
	std::list<int> li2 = li;
	
	std::cout << "Array: \n";
	print_contents(ai2);
	std::cout << "Vector: \n";
	print_contents(vi2);
	std::cout << "List: \n";
	print_contents(li2);
	
	copyy(ai2.begin(), ai2.end(), vi2.begin());
	copyy(li2.begin(), li2.end(), ai2.begin());
	std::cout << "Copy\n";
	print_contents(ai2);
	print_contents(vi2);
	print_contents(li2);
	
	std::vector<int>::iterator vit;
	vit = std::find(vi2.begin(), vi2.end(), 3);
	if(vit != vi2.end()){
		std::cout << "Fount at: " << std::distance(vi2.begin(), vit) << std::endl;
	}
	else {
		std::cout << "Not found\n";
	}


} catch(std::exception& e) {
	std::cout << e.what() << std::endl;
	return 1;
} catch(...) {
	std::cout << "Unknown exception\n";
	return 2;
}

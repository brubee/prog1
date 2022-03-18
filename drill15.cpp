#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
	Person(){};
	//Person(string n, int a) : n{n}, a{a}{ 
	Person(string f, string l, int a) : f{f}, l{l}, a{a}{
		if (a < 0 || a >= 150){
			throw runtime_error("Invalid age");
		}

		string n = f + n;

		for (char c : n)
			switch(c) {
				case ';':
				case ':':
				case '\":
				case '\'':
				case '[':
				case ']':
				case '*':
				case '&':
				case '^':
				case '%':
				case '$':
				case '#':
				case '@':
				case '!':
					throw runtime_error("Invalid name");
					break;
				default:
					break;
			}
	};
	//string name() const{return n;}
	string first_name() const{return f;}
	string last_name() const{return l;}
	int age() const{return a;}
private:
	//string n;
	string f;
	string l;
	int a;
};

ostream& operator<< (ostream& os, const Person& p) {
	return os << p.first_name() << " " << p.last_name() << " " << p.age();
};

istream& operator>> (istream& is, Person& p) {
	//string n;
	string f;
	string l;
	int a;

	//is >> n >> a;
	is >> f >> l >> a;
	//p = Person(n, a);
	p = Person(f, l, a);

	return is;
};

int main() {

	Person p;
	//p.n = "Goofy";
	//p.a = 63;
	p = Person("Goofy", "Uhh", 63);

	cout << p.first_name() << " " << p.last_name() << " " << p.age() << endl;

	Person p2;
	Person p3;

	cin >> p2 >> p3;
	cout << p2 << "\n" << p3 << endl;

	vector<Person> vec;

	for(Person p; cin >> p; ){
		if(p.first_name() == "end") break;
		vec.push_back(p);
	}

	for(Person p: vec){ // ez egy for each ciklus, btw
		cout << p << endl;
	}

}

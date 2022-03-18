// g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`

#include "Simple_window.h"
#include "Graph.h"

double one(double x) {return 1;}
double slope(double x) {return x/2;}
double square(double x) {return x*x;}
double sloping_cos(double x) {return slope(x) + cos(x);}

int main() {

	try {
		using namespace Graph_lib;
	
		Point t1 {100, 100};
		Point origo {300, 300};
	
		Simple_window win {t1, 600, 600, "Canvas"};
	
		Axis x {Axis::x, Point{100, 300}, 400, 20, "1==20 pixels"};
		Axis y {Axis::y, Point{300, 500}, 400, 20, "1==20 pixels"};
	
		x.set_color(Color::red);
		y.set_color(Color::red);
		win.attach(x);
		win.attach(y);
		
		Function s(one, -10, 11, origo, 400, 20, 20);
		Function sl(slope, -10, 11, origo, 400);
		Function sq(square, -10, 11, origo, 400);
		
		win.attach(s);
		win.attach(sl);
		
		Text t(Point{560, 150}, "x/2");
		win.attach(t);
		
		win.attach(sq);
		
		Function c(cos, -10, 11, origo, 400, 20, 20);
		c.set_color(Color::blue);
		win.attach(c);
		
		Function sl_c(sloping_cos, -10, 11, origo, 400, 20, 20);
		win.attach(sl_c);
	
		win.wait_for_button();
	
	} catch(exception& e) {
		std::cerr << "exception: " << e.what() << endl;
		return 1;
	} catch(...) {
		std::cerr << "error\n";
		return 2;
	}
}

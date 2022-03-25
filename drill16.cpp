// g++ drill16.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill16 `fltk-config --ldflags --use-images`

#include "pop_up_window.h"
#include "Graph.h"
#include "GUI.h"

int main() {

	using namespace Graph_lib;
	
	try {
		pop_up_window win(Point{100, 100}, 600, 400, "lines");
		return gui_main();
		
	} catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	} catch (...) {
		cerr << "Some exception\n";
		return 2;
	}

}

/* sajnos el kell ismernem, hogy ez a drill nem fut, de azt nem tudom miért
   valamiért a main nem látja a pop_up_window.h fájlt, vagy ha látja is, akkor privátként kezeli, és ezért nem fordul le a program */

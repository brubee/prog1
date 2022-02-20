/*
	g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

#include "./Simple_window.h"
#include "./Graph.h"

#include <string>
#include <iostream>

int main() {

	try{
	
		using namespace Graph_lib;
	
		Point t1 {100, 100};
	
		Simple_window win(t1, 600, 400, "My window");
		win.wait_for_button();
		
		Axis xa(Axis::x, Point{20, 300}, 250, 10, "x axis");
		win.attach(xa);
		win.set_label("x axis");
		win.wait_for_button();
		
		Axis ya(Axis::y, Point{20, 300}, 280, 10, "y axis");
		ya.set_color(Color::cyan);
		ya.label.set_color(Color::dark_red);
		win.attach(ya);
		
		win.set_label("y axis");
		win.wait_for_button();
		
		Function sine {sin, 0, 100, Point{10, 150}, 1000, 50, 50};
		win.attach(sine);
		win.set_label("Sine");
		win.wait_for_button();
		
		Polygon poly;
		poly.add(Point{300, 200});
		poly.add(Point{350, 100});
		poly.add(Point{400, 200});
		
		poly.set_color(Color::red);
		poly.set_style(Line_style::dash);
		win.attach(poly);
		
		win.set_label("Triangle");
		win.wait_for_button();
		
		Rectangle r {Point{200, 200}, 100, 50};
		win.attach(r);
		
		Closed_polyline poly_rect;
		poly_rect.add(Point{100, 50});
		poly_rect.add(Point{200, 50});
		poly_rect.add(Point{200, 100});
		poly_rect.add(Point{100, 100});
		poly_rect.add(Point{25, 50});
		win.attach(poly_rect);
		
		win.set_label("Rectangle");
		win.wait_for_button();
		
		r.set_fill_color(Color::yellow);
		poly.set_style(Line_style(Line_style::dash, 4));
		poly_rect.set_style(Line_style(Line_style::dash, 2));
		poly_rect.set_fill_color(Color::green);
		
		win.set_label("Color");
		win.wait_for_button();
		
		Text t {Point{150, 150}, "Hello, graphical world!"};
		t.set_font(Font::times_bold);
		t.set_font_size(20);
		win.attach(t);
		
		win.set_label("Color");
		win.wait_for_button();
		
		Image ii {Point{100, 100}, "badge.jpg"};
		win.attach(ii);
		win.wait_for_button();
	
	} catch(exception& e) {
		cerr << "exception " << e.what() << endl;
		return 1;
	} catch(...) {
		cerr << "error\n";
		return 2;
	}
}

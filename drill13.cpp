#include "Simple_window.h"
#include "Graph.h"

#include <iostream>
#include <string>

using namespace Graph_lib;

int main() {
	try {
	
		Point t1 {300, 500};
		Simple_window win {t1, 1000, 800, "My window"};
		win.wait_for_button();
		
		Lines grid;
		int x_size = 800;
		int y_size = 800;
		
		for(int i = 100; i <= x_size; i+=100)
		{
			grid.add(Point(i,0), Point(i,y_size));
			grid.add(Point(0,i), Point(y_size,i));
		}
		win.attach(grid);
		win.wait_for_button();
		
		Vector_ref<Rectangle> vr;
		for(int i = 0; i < 8; i++)
		{
			vr.push_back(new Rectangle {Point(i*100, i*100), 101, 101});
			vr[vr.size()-1].set_fill_color(Color::red);
			win.attach(vr[vr.size()-1]);
		}
		win.wait_for_button();
		
		Image img1(Point(200,0), "badge.jpg");
		img1.set_mask(Point(200,0), 200, 200);
		win.attach(img1);
		
		Image img2(Point(500,200), "badge.jpg");
		img2.set_mask(Point(200,0), 200, 200);
		win.attach(img2);
		
		Image img3(Point(100,500), "badge.jpg");
		img3.set_mask(Point(200,0), 200, 200);
		win.attach(img3);
		
		win.wait_for_button();
		
		Image small(Point(0,0), "badge.jpg");
		small.set_mask(Point(200,0), 100, 100);
		win.attach(small);
		
		int pX = 0;
		int pY = 0;
		int rX = 0;
		int rY = 0;
		
		while (true)
		{
			rX = (rand()%7+1)*100;
			rY = (rand()%7+1)*100;
			win.wait_for_button();
			small.move(rX - pX, rY - pY);
			pX = rX;
			pY = rY;
		}
		
		win.wait_for_button();
		
	} catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	} catch (...) {
		cerr << "error" << endl;
		return 2;
	}
}

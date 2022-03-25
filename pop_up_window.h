#include "GUI.h"

using namespace Graph_lib;

class pop_up_window : Graph_lib::Window {
	pop_up_window(Point xy, int w, int h, const string& title);
	
	Open_polyline lines;
	
	bool wait_for_button();
	
private:
	Button next_button;
	Button quit_button;
	Button menu_button;
	Button red_menu_button;
	Button blue_menu_button;
	Button black_menu_button;
	Button thick_menu_button;
	Button thick2_menu_button;
	Button thick3_menu_button;
	Button thick4_menu_button;
	Menu colors;
	Menu thickness;
	
	In_box next_x;
	In_box next_y;
	
	Out_box xy_out;
	
	void next();
	void quit();
	
	void hide_menu();
	void hide_thick_menu();
	void red_pressed();
	void blue_pressed();
	void black_pressed();
	void thick2();
	void thick3();
	void thick4();

};

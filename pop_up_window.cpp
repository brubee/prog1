#include "pop_up_window.h"

pop_up_window::pop_up_window(Point xy, int w, int h, const string& title) :
	Window(xy, w, h, title),
	next_button{Point{x_max()-300, 0}, 150, 40, "Next point",
	[](Address, Address pw) {reference_to<pop_up_window>(pw).next(); }},
	
	quit_button{Point{x_max()-150, 0}, 150, 40, "Quit",
	[](Address, Address pw) {reference_to<pop_up_window>(pw).quit(); }},
	
	menu_button{Point{x_max()-150, 70}, 150, 40, "Colors",
	[](Address, Address pw) {reference_to<pop_up_window>(pw).hide_menu(); }},
	
	thick_menu_button{Point{x_max()-300, 70}, 150, 40, "Thickness",
	[](Address, Address pw) {reference_to<pop_up_window>(pw).hide_thick_menu(); }},
	
	
	
	next_x{Point{300, 0}, 50, 40, "next_x:"},
	next_y{Point{450, 0}, 50, 40, "next_y:"},
	
	xy_out{Point{100, 0}, 100, 40, "current x.y:"},
	
	colors{Point{x_max()-150, 70}, 150, 40, Menu::vertical, "Colors"},
	
	thickness{Point{x_max()-300, 70}, 150, 40, Menu::vertical, "Thickness"},
	
	
	
	red_menu_button{Point{x_max()-150, 120}, 150, 40, "Red",
	[](Address, Address pw) {reference_to<pop_up_window>(pw).red_pressed();}},
	
	blue_menu_button{Point{x_max()-150, 165}, 150, 40, "Blue",
	[](Address, Address pw) {reference_to<pop_up_window>(pw).blue_pressed();}},
	
	black_menu_button{Point{x_max()-150, 210}, 150, 40, "Black",
	[](Address, Address pw) {reference_to<pop_up_window>(pw).black_pressed();}},
	
	
	
	thick2_menu_button{Point{x_max()-300, 120}, 150, 40, "Thickness 2",
	[](Address, Address pw) {reference_to<pop_up_window>(pw).thick2();}},
	
	thick3_menu_button{Point{x_max()-300, 165}, 150, 40, "Thickness 3",
	[](Address, Address pw) {reference_to<pop_up_window>(pw).thick3();}},
	
	thick4_menu_button{Point{x_max()-300, 210}, 150, 40, "Thickness 4",
	[](Address, Address pw) {reference_to<pop_up_window>(pw).thick4();}}
	
{

	attach(next_button);
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	attach(lines);
	
	attach(menu_button);
	attach(thick_menu_button);
	
	colors.attach(red_menu_button);
	colors.attach(blue_menu_button);
	colors.attach(black_menu_button);
	
	thickness.attach(thick2_menu_button);
	thickness.attach(thick3_menu_button);
	thickness.attach(thick4_menu_button);
	
	attach(thickness);
	thickness.hide();
	
	attach(colors);
	colors.hide();

}

void pop_up_window::next() {
	int x = next_x.get_int();
	int y = next_y.get_int();
	
	lines.add(Point{x,y});
	
	ostringstream ss;
	ss << '(' << x << ", " << y << ')';
	
	xy_out.put(ss.str());
	
	redraw();
}

void pop_up_window::quit() {
	hide();
}

void pop_up_window::hide_menu() {
	menu_button.hide();
	colors.show();
}

void pop_up_window::hide_thick_menu() {
	thick_menu_button.hide();
	thickness.show();
}

void pop_up_window::red_pressed() {
	lines.set_color(Color::red);
	colors.hide();
	menu_button.show();
}

void pop_up_window::blue_pressed() {
	lines.set_color(Color::blue);
	colors.hide();
	menu_button.show();
}

void pop_up_window::black_pressed() {
	lines.set_color(Color::black);
	colors.hide();
	menu_button.show();
}

void pop_up_window::thick2() {
	lines.set_style(Line_style(Line_style::solid, 2));
	thickness.hide();
	thick_menu_button.show();
}

void pop_up_window::thick3() {
	lines.set_style(Line_style(Line_style::solid, 4));
	thickness.hide();
	thick_menu_button.show();
}

void pop_up_window::thick4() {
	lines.set_style(Line_style(Line_style::solid, 8));
	thickness.hide();
	thick_menu_button.show();
}

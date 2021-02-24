//sudo apt-get install libfltk1.1-dev
//g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`

//g++ GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp ex01.cpp `fltk-config --ldflags --use-images7 -o a.out

//Alt Gr + 7   `


#include "GUI/Simple_window.h"
#include "GUI/Graph.h"

int main()
{
	using namespace Graph_lib;

	Point tl {100, 100};
	Simple_window win {tl, 800, 600, "Canvas"};
	win.wait_for_button();
	

	Axis xa(Axis::x, Point(20,300), 300, 10, "x axis");
	win.attach(xa);
	win.set_label("Canvas #2");
	win.wait_for_button();
	
	Axis ya(Axis::y, Point(170,450),300,10,"y axis");
	ya.set_color(Color::black);
	ya.label.set_color(Color::dark_red);
	win.attach(ya);
	win.set_label("Canvas #3");
	win.wait_for_button();

	Function sine(sin,0,100,Point(20,150),1000,200,200);
	sine.set_color(Color::dark_magenta);
	win.attach(sine);
	win.set_label("Canvas #4");
	win.wait_for_button();

	Polygon poly;
	poly.add(Point(300,200));
	poly.add(Point(350,100));
	poly.add(Point(700,200));
	
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	win.set_label("Canvas #5");
	win.wait_for_button();

	Rectangle r(Point(220,200),200,50);
	r.set_fill_color(Color::dark_blue);
	poly.set_style(Line_style(Line_style::dash,8));
	win.set_label("Canvas #6");
	win.attach(r);
	
	Closed_polyline poly_rect;
	poly_rect.add(Point(100,50));
	poly_rect.add(Point(200,50));
	poly_rect.add(Point(200,100));
	poly_rect.add(Point(100,100));

	poly_rect.add(Point(60,75));
	win.attach(poly_rect);	

	win.set_label("Canvas #7");
	win.wait_for_button();

	Text t(Point(150,150), "Hello, graphical world! ");
	t.set_font(Font::times_bold);
	t.set_font_size(20);
	win.attach(t);
	win.set_label("Canvas #8");
	win.wait_for_button();

	Image ii(Point(100,50),"apple.jpg");
	win.attach(ii);
	win.set_label("Canvas #9");
	win.wait_for_button();

	ii.move(110,200);
	win.set_label("Canvas #10");
	win.wait_for_button();

	Circle c(Point(70,200),200);
	//Ellipse e(Point(100,200),75,25);
	//e.set_color(Color::dark_red);
	Mark m(Point(100,200),'O');

	ostringstream oss;
	oss << "screen size: " << x_max() << y_max()
	<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes(Point(100,20),oss.str());

	win.attach(c);
	//win.attach(e);
	win.attach(m);
	win.attach(sizes);	

	win.set_label("Canvas #11");
	win.wait_for_button();

	Image snow(Point(225,225), "snow.jpeg");
	snow.set_mask(Point(40,40),200,150);
	win.attach(snow);

	win.set_label("Canvas #12");
	win.wait_for_button();


	
}


	// g++ GraphicDrill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o a.out `fltk-config --ldflags --use-images`

#include "Simple_window.h"
#include "Graph.h"

double one(double x) {return 1; }


double slope(double x) {return x/2; }


double square(double x) {return x*x; }


double sloping_cos(double x) {return cos(x) + slope(x); }


int main()
try{

	int xmax = 600;
	int ymax = 600;
	Point tl(600,50);
	Simple_window win{tl, xmax, ymax, "Function graphs"};


	int x_origin = xmax/2;
	int y_origin = ymax/2;
	Point origin(x_origin,y_origin);

	

	
	

	int xlength = xmax - 200;
	int ylength = ymax - 200;
	
	int scale_x = 20;
	int scale_y = 20;

	Axis x(Axis::x, Point(100,y_origin), xlength, xlength/scale_x,"1 == 20 pixels");
	x.set_color(Color::red);
	win.attach(x);

	Axis y(Axis::y, Point(x_origin,500), ylength, ylength/scale_y, "1 == 20 pixels");
	y.set_color(Color::red);
	win.attach(y);

	win.wait_for_button();


	int r_min = -10;
	int r_max = 11;
	int n_point = 400;

	Function one_func(one, r_min, r_max, origin, n_point, scale_x, scale_y);
	win.attach(one_func);
	win.wait_for_button();

	Function slope_func(slope, r_min, r_max, origin, n_point, scale_x, scale_y);
	win.attach(slope_func);
	win.wait_for_button();

	Text slopeText(Point{170,350},"x/2");
	win.attach(slopeText);
	win.wait_for_button();

	Function square_func(square, r_min, r_max, origin, n_point, scale_x, scale_y);
	win.attach(square_func);
	win.wait_for_button();
	
	Function cosine_func(cos, r_min, r_max, origin, n_point, scale_x, scale_y);
	cosine_func.set_color(Color::blue);
	win.attach(cosine_func);
	win.wait_for_button();
	
	Function slopeCos_func(sloping_cos, r_min, r_max, origin, n_point, scale_x, scale_y);
	win.attach(slopeCos_func);
	win.wait_for_button();

}catch(exception& e){
	cerr << e.what() << endl;
	return 1;
}catch(...){ 
	cerr << "Error" << endl;
	return 2;
}

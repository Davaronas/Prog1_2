#include "GUI/Simple_window.h"
#include "GUI/Graph.h"

// g++ GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp main.cpp `fltk-config --ldflags --use-images` -o a.out

int main()
{
	using namespace Graph_lib;

	Point p_origin {50,50};
	Simple_window win {p_origin,800,1000, "Drill 4"};
	win.wait_for_button();

	int x_size = win.x_max();
	int y_size = win.y_max();

	int x_grid = 100;
	int y_grid = 100;

	Lines grid;
	for(int x = x_grid; x < x_size; x += x_grid)
	grid.add(Point(x,0), Point(x,y_size));

	for(int y = y_grid; y < y_size; y += y_grid)
	grid.add(Point(0,y), Point(x_size,y));

	win.attach(grid);
	win.wait_for_button();
	


	int r_top_left_points [8];
	int r_size = 100;
	Vector_ref<Rectangle> r;	

	for(int i = 0; i < 8; i++)
	{
		r_top_left_points[i] = i * 100;
	}

	for(int j = 0; j < 8; j++)
	{
		r.push_back(new Rectangle (Point 
		{r_top_left_points[j],
		r_top_left_points[j]},
		r_size,r_size));
		r[r.size()-1].set_fill_color(Color::red);
		win.attach(r[r.size()-1]);
	}

	


	win.wait_for_button();

	Image i1 (Point {0,200},"200x200.jpeg");
	win.attach(i1);

	Image i2 (Point {500,100},"200x200.jpeg");
	win.attach(i2);

	Image i3 (Point {100,500},"200x200.jpeg");
	win.attach(i3);

	win.wait_for_button();

	Image i4 (Point{0,0},"100x100.jpg");
	win.attach(i4);
	
	win.wait_for_button();
	
	int current_x = 0;

	while(true)
	{
		if(current_x == 7)
		{
			i4.move(-700,100);
			current_x = 0;
		}
		else 
		{
			i4.move(100,0);
			current_x++;
		}

		
		win.wait_for_button();
	}


	return 0;
}

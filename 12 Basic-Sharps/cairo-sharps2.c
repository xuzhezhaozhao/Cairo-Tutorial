#include <cairo.h>
#include <math.h>

int main(void)
{
	int points[11][2] = { 
	  		{ 0, 85 }, 
	  		{ 75, 75 }, 
	  		{ 100, 10 }, 
	  		{ 125, 75 }, 
	 	 	{ 200, 85 },
	  		{ 150, 125 }, 
	  		{ 160, 190 },
	  		{ 100, 150 }, 
	  		{ 40, 190 },
	  		{ 50, 125 },
	  		{ 0, 85 } 
	};

	int i;
	int width, height;
	width = 800;
	height = 800;

	cairo_surface_t *surface;
	cairo_t *cr;
	surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
	cr = cairo_create(surface);

	cairo_set_source_rgb(cr, 0.6, 0.6, 0.6);
	cairo_set_line_width(cr, 1);

	for (i = 0; i < 10; i++) {
	    cairo_line_to(cr, points[i][0], points[i][1]);
	}

	cairo_close_path(cr);
	cairo_stroke_preserve(cr);
	cairo_fill(cr);

	cairo_move_to(cr, 240, 40);
	cairo_line_to(cr, 240, 160);
	cairo_line_to(cr, 350, 160);
	cairo_close_path(cr);

	cairo_stroke_preserve(cr);
	cairo_fill(cr);

	cairo_move_to(cr, 380, 40);
	cairo_line_to(cr, 380, 160);
	cairo_line_to(cr, 450, 160);
	cairo_curve_to(cr, 440, 155, 380, 145, 380, 40);

	cairo_stroke_preserve(cr);
	cairo_fill(cr);  

	cairo_surface_write_to_png(surface, "sharps2.png");

	cairo_destroy(cr);
	cairo_surface_destroy(surface);
	
	return 0;
}

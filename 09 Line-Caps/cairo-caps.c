#include <cairo.h>
#include <math.h>

int main(void)
{
	int width, height;
	width = 400;
	height = 400;

	cairo_surface_t *surface;
	cairo_t *cr;
	surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
	cr = cairo_create(surface);

	cairo_set_line_width(cr, 10);

	cairo_set_line_cap(cr, CAIRO_LINE_CAP_BUTT); 
	cairo_move_to(cr, 30, 50); 
	cairo_line_to(cr, 150, 50);
	cairo_stroke(cr);

	cairo_set_line_cap(cr, CAIRO_LINE_CAP_ROUND); 
	cairo_move_to(cr, 30, 90); 
	cairo_line_to(cr, 150, 90);
	cairo_stroke(cr);

	cairo_set_line_cap(cr, CAIRO_LINE_CAP_SQUARE); 
	cairo_move_to(cr, 30, 130); 
	cairo_line_to(cr, 150, 130);
	cairo_stroke(cr);

	cairo_set_line_width(cr, 1.5);

	cairo_move_to(cr, 30, 40);  
	cairo_line_to(cr, 30, 140);
	cairo_stroke(cr);

	cairo_move_to(cr, 150, 40);  
	cairo_line_to(cr, 150, 140);
	cairo_stroke(cr);

	cairo_move_to(cr, 155, 40);  
	cairo_line_to(cr, 155, 140);
	cairo_stroke(cr);


	cairo_surface_write_to_png(surface, "caps.png");

	cairo_destroy(cr);
	cairo_surface_destroy(surface);
	
	return 0;
}

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

	cairo_set_source_rgb(cr, 0.1, 0, 0);

	cairo_rectangle(cr, 30, 30, 100, 100);
	cairo_set_line_width(cr, 14);
	cairo_set_line_join(cr, CAIRO_LINE_JOIN_MITER); 
	cairo_stroke(cr);

	cairo_rectangle(cr, 160, 30, 100, 100);
	cairo_set_line_width(cr, 14);
	cairo_set_line_join(cr, CAIRO_LINE_JOIN_BEVEL); 
	cairo_stroke(cr);

	cairo_rectangle(cr, 100, 160, 100, 100);
	cairo_set_line_width(cr, 14);
	cairo_set_line_join(cr, CAIRO_LINE_JOIN_ROUND); 
	cairo_stroke(cr);    

	cairo_surface_write_to_png(surface, "joins.png");

	cairo_destroy(cr);
	cairo_surface_destroy(surface);
	
	return 0;
}

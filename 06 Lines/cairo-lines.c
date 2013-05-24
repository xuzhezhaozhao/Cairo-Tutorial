#include <cairo.h>

int main(void)
{
	cairo_surface_t *surface;
	cairo_t *cr;
	surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 640, 480);
	cr = cairo_create(surface);

	cairo_set_line_width(cr, 1);
	cairo_move_to(cr, 0, 100);
	cairo_line_to(cr, 640, 100);
	cairo_stroke(cr);
	cairo_surface_write_to_png(surface, "lines.png");

	cairo_destroy(cr);
	cairo_surface_destroy(surface);
	
	return 0;
}

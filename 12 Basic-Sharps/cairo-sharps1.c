#include <cairo.h>
#include <math.h>

int main(void)
{
	int width, height;
	width = 800;
	height = 800;

	cairo_surface_t *surface;
	cairo_t *cr;
	surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
	cr = cairo_create(surface);

	cairo_set_source_rgb(cr, 0.6, 0.6, 0.6);
	cairo_set_line_width(cr, 1);

	cairo_rectangle(cr, 20, 20, 120, 80);
	cairo_rectangle(cr, 180, 20, 80, 80);
	cairo_stroke_preserve(cr);
	cairo_fill(cr);

	cairo_arc(cr, 330, 60, 40, 0, 2*M_PI);
	cairo_stroke_preserve(cr);
	cairo_fill(cr);

	cairo_arc(cr, 90, 160, 40, M_PI/4, M_PI);
	cairo_close_path(cr);
	cairo_stroke_preserve(cr);
	cairo_fill(cr);

	cairo_translate(cr, 220, 180);
	cairo_scale(cr, 1, 0.7);
	cairo_arc(cr, 0, 0, 50, 0, 2*M_PI);
	cairo_stroke_preserve(cr);
	cairo_fill(cr);


	cairo_surface_write_to_png(surface, "sharps1.png");

	cairo_destroy(cr);
	cairo_surface_destroy(surface);
	
	return 0;
}

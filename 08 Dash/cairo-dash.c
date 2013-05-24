#include <cairo.h>
#include <math.h>

int main(void)
{
	int width, height;
	width = 640;
	height = 480;

	const double dashed1[] = {5.0, 20.0, 10.0};
	int len1 = sizeof(dashed1) / sizeof(dashed1[0]);

	const double dashed2[] = {20.0, 5.0};
	int len2 = sizeof(dashed2) / sizeof(dashed2[0]);

	const double dashed3[] = {10.0};
	int len3 = sizeof(dashed3) / sizeof(dashed3[0]);

	cairo_surface_t *surface;
	cairo_t *cr;
	surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
	cr = cairo_create(surface);

	cairo_set_line_width(cr, 1);
	cairo_set_source_rgb(cr, 0, 0, 0);

	cairo_set_dash(cr, dashed1,len1, 0);
	cairo_move_to(cr, 100, 100);
	cairo_line_to(cr, 500, 100);
	cairo_stroke(cr);

	cairo_set_dash(cr, dashed2, len2, 0);
	cairo_move_to(cr, 100, 200);
	cairo_line_to(cr, 500, 200);
	cairo_stroke(cr);

	cairo_set_dash(cr, dashed3, len3, 0);
	cairo_move_to(cr, 100, 300);
	cairo_line_to(cr, 500, 300);
	cairo_stroke(cr);

	cairo_surface_write_to_png(surface, "dash.png");

	cairo_destroy(cr);
	cairo_surface_destroy(surface);
	
	return 0;
}

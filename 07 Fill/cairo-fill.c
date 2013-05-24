#include <cairo.h>
#include <math.h>

int main(void)
{
	int width, height;
	width = 640;
	height = 480;
	cairo_surface_t *surface;
	cairo_t *cr;
	surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
	cr = cairo_create(surface);

	cairo_set_line_width(cr, 10);
	cairo_set_source_rgb(cr, 0.8, 0.2, 0);

	/* 将坐标原点移至中心 */
	cairo_translate(cr, width / 2, height / 2);

	cairo_arc(cr, 0, 0, 50, 0, 2 * M_PI);
	cairo_stroke_preserve(cr);

	cairo_set_source_rgb(cr, 0.3, 0.4, 0.6);
	cairo_fill(cr);

	cairo_surface_write_to_png(surface, "circle.png");

	cairo_destroy(cr);
	cairo_surface_destroy(surface);
	
	return 0;
}

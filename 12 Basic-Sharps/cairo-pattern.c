#include <cairo.h>
#include <math.h>

cairo_surface_t *surface1;
cairo_surface_t *surface2;
cairo_surface_t *surface3;
cairo_surface_t *surface4;

static void create_surfaces() {
	surface1 = cairo_image_surface_create_from_png("blueweb.png");
	surface2 = cairo_image_surface_create_from_png("maple.png");
	surface3 = cairo_image_surface_create_from_png("crack.png");
	surface4 = cairo_image_surface_create_from_png("chocolate.png");
}

static void destroy_surfaces() {
	cairo_surface_destroy(surface1);
	cairo_surface_destroy(surface2);
	cairo_surface_destroy(surface3);
	cairo_surface_destroy(surface4);
}

int main(void)
{
	int width, height;
	cairo_surface_t *surface;
	cairo_t *cr;

	width = 800;
	height = 800;
	surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
	cr = cairo_create(surface);

	create_surfaces();

	cairo_pattern_t *pattern1;
	cairo_pattern_t *pattern2;
	cairo_pattern_t *pattern3;
	cairo_pattern_t *pattern4;

	pattern1 = cairo_pattern_create_for_surface(surface1);
	pattern2 = cairo_pattern_create_for_surface(surface2);
	pattern3 = cairo_pattern_create_for_surface(surface3);
	pattern4 = cairo_pattern_create_for_surface(surface4);

	cairo_set_source(cr, pattern1);
	cairo_pattern_set_extend(cairo_get_source(cr), CAIRO_EXTEND_REPEAT);
	cairo_rectangle(cr, 20, 20, 100, 100);
	cairo_fill(cr);

	cairo_set_source(cr, pattern2); 
	cairo_pattern_set_extend(cairo_get_source(cr), CAIRO_EXTEND_REPEAT); 
	cairo_rectangle(cr, 150, 20, 100, 100);
	cairo_fill(cr);

	cairo_set_source(cr, pattern3);
	cairo_pattern_set_extend(cairo_get_source(cr), CAIRO_EXTEND_REPEAT);
	cairo_rectangle(cr, 20, 140, 100, 100);
	cairo_fill(cr);

	cairo_set_source(cr, pattern4);
	cairo_pattern_set_extend(cairo_get_source(cr), CAIRO_EXTEND_REPEAT);
	cairo_rectangle(cr, 150, 140, 100, 100);
	cairo_fill(cr);


	cairo_surface_write_to_png(surface, "pattern.png");

	cairo_pattern_destroy(pattern1);
	cairo_pattern_destroy(pattern2);
	cairo_pattern_destroy(pattern3);
	cairo_pattern_destroy(pattern4);      

	cairo_destroy(cr);
	destroy_surfaces();
	
	return 0;
}

#include <cairo.h>
#include <math.h>

void draw_gradient1(cairo_t *);
void draw_gradient2(cairo_t *);

int main(void)
{
	int width, height;
	width = 350;
	height = 350;

	cairo_surface_t *surface;
	cairo_t *cr;
	surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
	cr = cairo_create(surface); 

	draw_gradient1(cr);
	draw_gradient2(cr);

	cairo_surface_write_to_png(surface, "radial-gradients.png");

	cairo_destroy(cr);
	cairo_surface_destroy(surface);
	
	return 0;
}


void draw_gradient1(cairo_t *cr)
{
	cairo_pattern_t *r1; 
	  
	cairo_set_source_rgba(cr, 0, 0, 0, 1);
	cairo_set_line_width(cr, 12);  
	cairo_translate(cr, 60, 60);
	
	r1 = cairo_pattern_create_radial(30, 30, 10, 30, 30, 90);
	
	cairo_pattern_add_color_stop_rgb(r1, 0, 1, 1, 1);
	cairo_pattern_add_color_stop_rgb(r1, 1, 0, 0, 0);
	cairo_set_source(cr, r1);
	cairo_arc(cr, 0, 0, 40, 0, M_PI * 2);
	cairo_fill(cr);
	       
	cairo_pattern_destroy(r1);
}

void draw_gradient2(cairo_t *cr)
{
	cairo_pattern_t *r2; 
	
	cairo_translate(cr, 120, 0);
	
	r2 = cairo_pattern_create_radial(0, 0, 10, 0, 0, 40);  
	cairo_pattern_add_color_stop_rgb(r2, 0, 1, 1, 0);
	cairo_pattern_add_color_stop_rgb(r2, 0.8, 0, 0, 0);
	cairo_set_source(cr, r2);
	cairo_arc(cr, 0, 0, 40, 0, M_PI * 2);
	cairo_fill(cr);     
}

#include <cairo.h>
#include <math.h>

void draw_gradient1(cairo_t *);
void draw_gradient2(cairo_t *);
void draw_gradient3(cairo_t *);

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
	draw_gradient3(cr);

	cairo_surface_write_to_png(surface, "linear-gradients.png");

	cairo_destroy(cr);
	cairo_surface_destroy(surface);
	
	return 0;
}

void draw_gradient1(cairo_t *cr)
{
	cairo_pattern_t *pat1;  
	pat1 = cairo_pattern_create_linear(0.0, 0.0,  350.0, 350.0);

	double j;
	int count = 1;
	for ( j = 0.1; j < 1; j += 0.1 ) {
	    if (( count % 2 ))  {
	        cairo_pattern_add_color_stop_rgb(pat1, j, 0, 0, 0);
	    } else { 
	        cairo_pattern_add_color_stop_rgb(pat1, j, 1, 0, 0);
	    }
	 count++;
	}

	cairo_rectangle(cr, 20, 20, 300, 100);
	cairo_set_source(cr, pat1);
	cairo_fill(cr);  
	
	cairo_pattern_destroy(pat1);
}

void draw_gradient2(cairo_t *cr)
{
	cairo_pattern_t *pat2;
	pat2 = cairo_pattern_create_linear(0.0, 0.0,  350.0, 0.0);

	double i;
	int count = 1;
	for ( i = 0.05; i < 0.95; i += 0.025 ) {
	    if (( count % 2 )) {
	        cairo_pattern_add_color_stop_rgb(pat2, i, 0, 0, 0);
	    } else { 
	        cairo_pattern_add_color_stop_rgb(pat2, i, 0, 0, 1);
	    }
	 count++;
	}

	cairo_rectangle(cr, 20, 140, 300, 100);
	cairo_set_source(cr, pat2);
	cairo_fill(cr);  
	
	cairo_pattern_destroy(pat2);
}

void draw_gradient3(cairo_t *cr)
{
	cairo_pattern_t *pat3;
	pat3 = cairo_pattern_create_linear(20.0, 260.0, 20.0, 360.0);

	cairo_pattern_add_color_stop_rgb(pat3, 0.1, 0, 0, 0);
	cairo_pattern_add_color_stop_rgb(pat3, 0.5, 1, 1, 0);
	cairo_pattern_add_color_stop_rgb(pat3, 0.9, 0, 0, 0);

	cairo_rectangle(cr, 20, 260, 300, 100);
	cairo_set_source(cr, pat3);
	cairo_fill(cr);  
	
	cairo_pattern_destroy(pat3);
}

#include <cairo.h>
#include <math.h>

int main(void)
{
	int i;
	int width, height;
	width = 600;
	height = 100;

	cairo_surface_t *surface;
	cairo_t *cr;
	surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
	cr = cairo_create(surface); 

	for ( i = 1; i <= 10; i++) {
      		cairo_set_source_rgba(cr, 0, 0, 1, i*0.1);
	    	cairo_rectangle(cr, 50*i, 40, 40, 40);
     		cairo_fill(cr);  
 	}      

	cairo_surface_write_to_png(surface, "transparancy.png");

	cairo_destroy(cr);
	cairo_surface_destroy(surface);
	
	return 0;
}

#include <cairo.h>
#include <math.h>

int main(void)
{
	int width, height, x, y;
	width = 600;
	height = 100;
	x = width / 2;
	y = height / 2;

	cairo_surface_t *surface;
	cairo_text_extents_t extents;
	cairo_t *cr;
	surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
	cr = cairo_create(surface); 

	cairo_set_source_rgb(cr, 0, 0, 0); 
	cairo_paint(cr);   

	cairo_select_font_face(cr, "Courier",
	    CAIRO_FONT_SLANT_NORMAL,
	    CAIRO_FONT_WEIGHT_BOLD);
 
	cairo_set_font_size(cr, 30);
	cairo_set_source_rgb(cr, 0, 1, 1); 

	cairo_text_extents(cr, "ZetCode", &extents);
	cairo_move_to(cr, x - extents.width/2, y);
	cairo_text_path(cr, "ZetCode");
	cairo_clip(cr);

	cairo_paint_with_alpha(cr, 0.5);

	cairo_surface_write_to_png(surface, "puff.png");

	cairo_destroy(cr);
	cairo_surface_destroy(surface);
	
	return 0;
}

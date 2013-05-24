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

	cairo_set_source_rgb(cr, 0.1, 0, 0);

	/* 不旋转 */
	cairo_rectangle(cr, 500, 50, 200, 200);
	cairo_set_line_width(cr, 14);
	cairo_set_line_join(cr, CAIRO_LINE_JOIN_BEVEL); 
	cairo_stroke(cr);

	cairo_set_font_size(cr, 30.0);
	cairo_move_to(cr, 510, 100);
	cairo_show_text(cr, "NO Rotate");
	
	/* 将坐标軕旋转60度 */
	cairo_rotate(cr, M_PI / 3);
	cairo_rectangle(cr, 500, 50, 200, 200);
	cairo_set_line_width(cr, 14);
	cairo_set_line_join(cr, CAIRO_LINE_JOIN_ROUND); 
	cairo_stroke(cr);    

	cairo_set_font_size(cr, 30.0);
	cairo_move_to(cr, 510, 100);
	cairo_show_text(cr, "Rotate 60");

	/* 将坐标軕旋转-60度, 回到正常情况 */
	cairo_rotate(cr, -(M_PI / 3));
	cairo_rectangle(cr, 500, 400, 200, 200);
	cairo_set_line_width(cr, 14);
	cairo_set_line_join(cr, CAIRO_LINE_JOIN_ROUND); 
	cairo_stroke(cr);    

	cairo_set_font_size(cr, 30.0);
	cairo_move_to(cr, 510, 450);
	cairo_show_text(cr, "Rotate -60");


	cairo_surface_write_to_png(surface, "rotate.png");

	cairo_destroy(cr);
	cairo_surface_destroy(surface);
	
	return 0;
}

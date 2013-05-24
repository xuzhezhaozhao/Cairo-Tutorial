+ [cairo_surface_t][1] 	 
+ [cairo_t][2] 
+ [cairo_image_surface_create][3] 
+ [cairo_create][4]
+ [cairo_set_source_rgb][5] 
+ [cairo_select_font_face][6]  
+ [cairo_set_font_size][7] 
+ [cairo_move_to][8]
+ [cairo_show_text][9] 
+ [cairo_surface_write_to_png][10] 
+ [cairo_destroy][11]

[1]: http://cairographics.org/manual/cairo-cairo-surface-t.html#cairo-surface-t "cairo_surface_t"
[2]: http://cairographics.org/manual/cairo-cairo-t.html "cairo_t"
[3]: http://cairographics.org/manual/cairo-Image-Surfaces.html#cairo-image-surface-create "cairo_image_surface_create"
[4]: http://cairographics.org/manual/cairo-cairo-t.html#cairo-create "cairo_create"
[5]: http://cairographics.org/manual/cairo-cairo-t.html#cairo-set-source-rgb "cairo_set_source_rgb"
[6]: http://cairographics.org/manual/cairo-text.html#cairo-select-font-face
[7]: http://cairographics.org/manual/cairo-text.html#cairo-set-font-size
[8]: http://cairographics.org/manual/cairo-Paths.html#cairo-move-to
[9]: http://cairographics.org/manual/cairo-text.html#cairo-show-text
[10]: http://cairographics.org/manual/cairo-PNG-Support.html#cairo-surface-write-to-png
[11]: http://cairographics.org/manual/cairo-cairo-t.html#cairo-destroy

This example is a small console application, that will create a PNG image.

	#include <cairo.h>

In this header file, we will find declarations of our functions and constants.

	cairo_surface_t *surface;
	cairo_t *cr;

Here we declare a surface and a Cairo context.

	surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 390, 60);
	cr = cairo_create(surface);

We create a surface and a Cairo context. The surface is an 390x60 px image.

	cairo_set_source_rgb(cr, 0, 0, 0);

We will draw in black ink.

	cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL,
	    CAIRO_FONT_WEIGHT_NORMAL);
	cairo_set_font_size(cr, 40.0);

We choose a font type and set its size.

	cairo_move_to(cr, 10.0, 50.0);
	cairo_show_text(cr, "Disziplin ist Macht.");

We move to a (10.0, 50.0) position within the image and draw the text.

	cairo_surface_write_to_png(surface, "image.png");

This function call creates the PNG image.

	cairo_destroy(cr);
	cairo_surface_destroy(surface);

In the end, we clean the resources.

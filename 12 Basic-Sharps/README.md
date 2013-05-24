+ [cairo_scale][1]
+ [cairo_curve_to][2]
+ [cairo_pattern_t][3]
+ [cairo_image_surface_create_from_png][4]
+ [cairo_pattern_create_for_surface][5]
+ [cairo_set_source][6]
+ [cairo_get_source][7]
+ [cairo_pattern_set_extend][8]
+ [cairo_extend_t][9]

[1]: http://cairographics.org/manual/cairo-Transformations.html#cairo-scale
[2]: http://cairographics.org/manual/cairo-Paths.html#cairo-curve-to
[3]: http://cairographics.org/manual/cairo-cairo-pattern-t.html#cairo-pattern-t
[4]: http://cairographics.org/manual/cairo-PNG-Support.html#cairo-image-surface-create-from-png
[5]: http://cairographics.org/manual/cairo-cairo-pattern-t.html#cairo-pattern-create-for-surface
[6]: http://cairographics.org/manual/cairo-cairo-t.html#cairo-set-source
[7]: http://cairographics.org/manual/cairo-cairo-t.html#cairo-get-source
[8]: http://cairographics.org/manual/cairo-cairo-pattern-t.html#cairo-pattern-set-extend
[9]: http://cairographics.org/manual/cairo-cairo-pattern-t.html#cairo-extend-t

##Basic Sharps

###Sharps1

In this example, we will create a rectangle, a square, a circle, an arc and an ellipse.

	cairo_rectangle(cr, 20, 20, 120, 80);
	cairo_rectangle(cr, 180, 20, 80, 80);

The cairo_rectangle() is used to create both squares and rectangles. A square is
just a specific type of a rectangle.

	cairo_arc(cr, 330, 60, 40, 0, 2*M_PI);

This line creates a circle.

	cairo_scale(cr, 1, 0.7);
	cairo_arc(cr, 0, 0, 50, 0, 2*M_PI);

We use the cairo_scale() function call to create an ellipse.

![Basic Shapes](http://zetcode.com/img/gfx/cairoc/basicshapes.png)

Figure: Basic shapes


###sharps2

Other shapes can be created using a combination of basic primitives.

In this example, we create a star object a triangle and a modified triangle. 
These objects are created using lines and one curve.

	for (i = 0; i < 10; i++ ) {
    		cairo_line_to(cr, points[i][0], points[i][1]);
	}

	cairo_close_path(cr);

The star is drawn by joining all the points that are in the points array. The
star is finished by calling the cairo_close_path() function, which joins the
last two points of a star.

	cairo_move_to(cr, 380, 40);
	cairo_line_to(cr, 380, 160);
	cairo_line_to(cr, 450, 160);
	cairo_curve_to(cr, 440, 155, 380, 145, 380, 40);
	
The modified triangle is a simple combination of two lines and one curve.

![Other shapes](http://zetcode.com/img/gfx/cairoc/othershapes.png "Other shapes")

Figure: Other shapes


###Fills

Fills fill the interiors of shapes. Fills can be solid colours, patters or
gradients.

####Solid colours

A colour is an object representing a combination of Red, Green, and Blue (RGB)
intensity values. Cairo valid RGB values are in the range 0 to 1.

####Patterns

Patterns are complex graphical objects that can fill the shapes.


In this example we draw four rectangles again. This time, we fill them with some
patterns. We use four pattern images from the Gimp image manipulation program.
We must retain the original size of those patterns, because we are going to tile
them.

We create image surfaces outside the on_draw_event() function. It would not be
efficient to read from harddisk each time, the window needs to be redrawn.

	pattern1 = cairo_pattern_create_for_surface(surface1);

We create a pattern from the surface by calling the 
`cairo_pattern_create_for_surface()` function.

	cairo_set_source(cr, pattern1);
	cairo_pattern_set_extend(cairo_get_source(cr), CAIRO_EXTEND_REPEAT);
	cairo_rectangle(cr, 20, 20, 100, 100);
	cairo_fill(cr);

Here we draw our first rectangle. The `cairo_set_source()` tells the Cairo context
to use a pattern as a source for drawing. The image patterns may not fit exactly
the shape. We set the mode to CAIRO_EXTEND_REPEAT, which causes the pattern to be
tiled by repeating. The `cairo_rectangle()` creates a rectangular path. Finally,
`cairo_fill()` fills the path with the source.

This chapter covered Cairo shapes and fills.

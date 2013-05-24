+ [cairo_rectangle][1]

[1]: http://cairographics.org/manual/cairo-Paths.html#cairo-rectangle

##Line joins

The lines can be joined using three different join styles.

+ **CAIRO_LINE_JOIN_MITER**
+ **CAIRO_LINE_JOIN_BEVEL**
+ **CAIRO_LINE_JOIN_ROUND**

![joins](http://zetcode.com/img/gfx/cairoc/joins.jpg)

Figure: Bevel, Round, Miter line joins

In this example, we draw three thick rectangles with various line joins.

	cairo_rectangle(cr, 30, 30, 100, 100);
	cairo_set_line_width(cr, 14);
	cairo_set_line_join(cr, CAIRO_LINE_JOIN_MITER); 
	cairo_stroke(cr);

In this code example, we draw a rectangle with *CAIRO_LINE_JOIN_MITER* join style.
The lines are 14 px wide.

![Line joins](http://zetcode.com/img/gfx/cairoc/linejoins.png)

+ [cairo_translate][1]
+ [cairo_arc][2]
+ [cairo_stroke_preserver][3]
+ [cairo_fill][4]

[1]: http://cairographics.org/manual/cairo-Transformations.html#cairo-translate
[2]: http://cairographics.org/manual/cairo-Paths.html#cairo-arc
[3]: http://cairographics.org/manual/cairo-cairo-t.html#cairo-stroke-preserve
[4]: http://cairographics.org/manual/cairo-cairo-t.html#cairo-fill

The stroke operation draws the outlines of shapes and the fill operation fills
the insides of shapes.

	cairo_translate(cr, width/2, height/2);
	cairo_arc(cr, 0, 0, 50, 0, 2 * M_PI);
	cairo_stroke_preserve(cr);

With the cairo_translate() method, we move the drawing origin to the center of
the window. We want our circle to be centered. The arc() method adds a new 
circular path to the cairo drawing context. Finally, the stroke_preserve()
method draws the outline of the circle. Unlike the stroke() method, it also 
preserves the shape for later drawing.

	cairo_set_source_rgb(cr, 0.3, 0.4, 0.6); 
	cairo_fill(cr);


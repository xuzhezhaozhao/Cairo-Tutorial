+ [cairo_set_dash][1]

[1]: http://cairographics.org/manual/cairo-cairo-t.html#cairo-set-dash

##Pen dashes

Each line can be drawn with a different pen dash. It defines the style of the
line. The dash is used by the `cairo_stroke()` function call. The dash pattern 
is specified by the `cairo_set_dash()` function. The pattern is set by the dash 
array, which is an array of positive floating point values. They set the on and
off parts of the dash pattern. We also specify the length of the array and the
offset value. If the length is 0, the dashing is disabled. If it is 1, a 
symmetric pattern is asumed with alternating on and off portions of the size 
specified by the single value in dashes.

In this example, we will draw three lines with different dash patterns.

	static const double dashed1[] = {5.0, 20.0, 10.0};

We have a pattern of three numbers. We have 5 points drawn, 20 not drawn and 10
drawn. Then 5 points not drawn, 20 points drawn and 10 not drawn. This pattern
takes turns until the end of the line.

	static int len1  = sizeof(dashed1) / sizeof(dashed1[0]);

We get the size of the array.

	cairo_set_dash(cr, dashed1, len1, 0);

We set the dash.

	static const double dashed3[] = {10.0};
	...
	cairo_set_dash(cr, dashed3, len3, 0);

	cairo_move_to(cr, 100, 300);  
	cairo_line_to(cr, 500, 300);
	cairo_stroke(cr);  

These lines create a line with a pen dash of a symmetric pattern of alternating
single on and off points.

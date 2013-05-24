+ [cairo_set_line_cap][1]
+ [cairo_line_cap_t][2]

[1]: http://cairographics.org/manual/cairo-cairo-t.html#cairo-set-line-cap
[2]: http://cairographics.org/manual/cairo-cairo-t.html#cairo-line-cap-t

##Line caps

The line caps are endpoints of lines.

+ *CAIRO_LINE_CAP_SQUARE*
+ *CAIRO_LINE_CAP_ROUND*
+ *CAIRO_LINE_CAP_BUTT*

There are three different line cap styles in Cairo.

![Caps](http://zetcode.com/img/gfx/cairoc/linecaps.png)

A line with a CAIRO_LINE_CAP_SQUARE cap will have a different size, than a line
with a CAIRO_LINE_CAP_BUTT cap. If a line is width px wide, the line with a
CAIRO_LINE_CAP_SQUARE cap will be exactly width px greater in size. width/2 px
at the beginning and width/2 px at the end.


The example draws three lines with three different caps. It will also
graphically demonstrate the differences is size of the lines.

	cairo_set_line_width(cr, 10);

Our lines will be 10 px wide.

	cairo_set_line_cap(cr, CAIRO_LINE_CAP_ROUND); 
	cairo_move_to(cr, 30, 90); 
	cairo_line_to(cr, 150, 90);
	cairo_stroke(cr);

Here we draw a horizontal line with a CAIRO_LINE_CAP_ROUND cap.

	cairo_set_line_width(cr, 1.5);

	cairo_move_to(cr, 30, 40);  
	cairo_line_to(cr, 30, 140);
	cairo_stroke(cr);

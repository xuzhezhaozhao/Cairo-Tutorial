+ [cairo_pattern_create_linear][1]
+ [cairo_pattern_add_color_stop_rgb][2]
+ [cairo_pattern_create_radial][3]

[1]: http://cairographics.org/manual/cairo-cairo-pattern-t.html#cairo-pattern-create-linear
[2]: http://cairographics.org/manual/cairo-cairo-pattern-t.html#cairo-pattern-add-color-stop-rgb
[3]: http://cairographics.org/manual/cairo-cairo-pattern-t.html#cairo-pattern-create-radial

##Gradients

In this part of the Cairo graphics tutorial, we will cover gradients. We will
mention linear and radial gradients.
 
In computer graphics, gradient is a smooth blending of shades from light to dark
or from one colour to another. In 2D drawing programs and paint programs,
gradients are used to create colourful backgrounds and special effects as well
as to simulate lights and shadows. \(answers.com\)


###Linear gradients

Linear gradients are blendings of colours or shades of colours along a line.
They are created with the `cairo_pattern_create_linear()` function.


The example draws three rectangles filled with linear gradients.

	pat3 = cairo_pattern_create_linear(20.0, 260.0, 20.0, 360.0);

Here we create a linear gradient pattern. The parameters specify the line, along
which we draw the gradient. In our case it is a vertical line.

	cairo_pattern_add_color_stop_rgb(pat3, 0.1, 0, 0, 0);
	cairo_pattern_add_color_stop_rgb(pat3, 0.5, 1, 1, 0);
	cairo_pattern_add_color_stop_rgb(pat3, 0.9, 0, 0, 0);

We define colour stops to produce our gradient pattern. In this case, the
gradient is a blending of black and yellow colours. By adding two black and one
yellow stops, we create a horizontal gradient pattern. What these stops actually
mean? In our case, we begin with black colour, which will stop at 1/10 of the
size. Then we begin to gradually paint in yellow, which will culminate at the
centre of the shape. The yellow colour stops at 9/10 of the size, where we begin
painting in black again, until the end.

![Linear gradients](http://zetcode.com/img/gfx/cairoc/lineargradients.png)

Figure: Linear gradients


###Radial gradients

Radial gradients are blendings of colours or shades of colours between two
circles. The `cairo_pattern_create_radial()` function s is used to create 
radial gradients in Cairo.

In the example, we draw two radial gradients.

	r1 = cairo_pattern_create_radial(30, 30, 10, 30, 30, 90);
	cairo_pattern_add_color_stop_rgba(r1, 0, 1, 1, 1, 1);
	cairo_pattern_add_color_stop_rgba(r1, 1, 0.6, 0.6, 0.6, 1);
	cairo_set_source(cr, r1);
	cairo_arc(cr, 0, 0, 40, 0, M_PI * 2);
	cairo_fill(cr);

We draw a circle and fill its inside with a radial gradient. The radial gradient
is defined by two circles. The `cairo_pattern_add_color_stop_rgba()` function
defines the colours. We can experiment with the position of the circles or the
length of their radius. In the first gradient example, we have created an object
which resembles a 3D shape.

	r2 = cairo_pattern_create_radial(0, 0, 10, 0, 0, 40);  
	cairo_pattern_add_color_stop_rgb(r2, 0, 1, 1, 0);
	cairo_pattern_add_color_stop_rgb(r2, 0.8, 0, 0, 0);
	cairo_set_source(cr, r2);
	cairo_arc(cr, 0, 0, 40, 0, M_PI * 2);
	cairo_fill(cr); 

In this example, the circles that define the radial gradient and the custom
drawn circle have a common center point.

![Radial gradients](http://zetcode.com/img/gfx/pycairo/radialgradients.png)

Figure: Radial gradients

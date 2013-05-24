+ [cairo_select_font_face][0]
+ [cairo_set_source_rgba][1]
+ [cairo_text_extents_t][2]
+ [cairo_paint][3]
+ [cairo_paint_with_alpha][4]
+ [cairo_text_extents][5]
+ [cairo_text_path][6]
+ [cairo_clip][7]

[0]: http://cairographics.org/manual/cairo-text.html#cairo-select-font-face
[1]: http://cairographics.org/manual/cairo-cairo-t.html#cairo-set-source-rgba
[2]: http://cairographics.org/manual/cairo-cairo-scaled-font-t.html#cairo-text-extents-t
[3]: http://cairographics.org/manual/cairo-cairo-t.html#cairo-paint
[4]: http://cairographics.org/manual/cairo-cairo-t.html#cairo-paint-with-alpha
[5]: http://cairographics.org/manual/cairo-text.html#cairo-text-extents
[6]: http://cairographics.org/manual/cairo-Paths.html#cairo-text-path
[7]: http://cairographics.org/manual/cairo-cairo-t.html#cairo-clip

##Transparency

In this part of the Cairo C API tutorial, we will talk about transparency. We
will provide some basic definitions and two interesting transparency effects.

Transparency is the quality of being able to see through a material. The easiest
way to understand transparency is to imagine a piece of glass or water.
Technically, the rays of light can go through the glass and this way we can see
objects behind the glass.

In computer graphics, we can achieve transparency effects using alpha 
compositing. Alpha compositing is the process of combining an image with a 
background to create the appearance of partial transparency. The composition 
process uses an alpha channel. Alpha channel is an 8-bit layer in a graphics 
file format that is used for expressing translucency (transparency). The extra
eight bits per pixel serves as a mask and represents 256 levels of translucency. 


The `cairo_set_source_rgba()` has an optional alpha parameter to provide
transparency. This code creates ten rectangles with alpha values from 0.1 ... 1.

![Transparency](http://zetcode.com/img/gfx/cairoc/rectangles.png)

Figure: Transparency

###Puff effect

In the following example, we create a puff effect. The example will display a
growing centered text that will gradually fade out from some point. This is a
very common effect which we can often see in flash animations. The
`cairo_paint_with_alpha()` method is crucial to create the effect.

	cairo_set_source_rgb(cr, 0.5, 0, 0); 
	cairo_paint(cr); 

The background of the window is filled with some dark red colour.

	cairo_select_font_face(cr, "Courier",
    	CAIRO_FONT_SLANT_NORMAL,
    	CAIRO_FONT_WEIGHT_BOLD);

The text is going to be in Courier bold font.

	cairo_text_extents(cr, "ZetCode", &extents);
	cairo_move_to(cr, x - extents.width/2, y);

We get the text metrics. We will use only the text width. We move to a position where
the text will be centered on the window.

	cairo_text_path(cr, "ZetCode");
	cairo_clip(cr);

	cairo_paint_with_alpha(cr, glob.alpha);

We get the path of the text with the `cairo_text_path()` method. We restrict the
painting to the current path using the `cairo_clip()` method. The 
`cairo_paint_with_alpha()` method paints the current source everywhere within
the current clip region using a mask of the alpha value.

![puff effect](http://zetcode.com/img/gfx/cairoc/puff.png)

Figure: Puff effect

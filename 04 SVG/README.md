+ [cairo_svg_surface_create][1]

[1]: http://cairographics.org/manual/cairo-SVG-Surfaces.html#cairo-svg-surface-create

We can use Firefox, Opera or Inkscape programs to open the svgfile.svg file.

	surface = cairo_svg_surface_create("svgfile.svg", 390, 60);

To create a SVG file in Cairo, we must create a svg surface using the
`cairo_svg_surface_create()` function call.

	cr = cairo_create(surface);

A Cairo context is created from a SVG surface.

The Rest of the code is identical to the previous examples

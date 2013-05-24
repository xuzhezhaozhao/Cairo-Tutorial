+ [cairo_pdf_surface_create][1]
+ [cairo_show_page][2]

[1]: http://cairographics.org/manual/cairo-PDF-Surfaces.html#cairo-pdf-surface-create
[2]: http://cairographics.org/manual/cairo-cairo-t.html#cairo-show-page

We must open the pdf file in a pdf viewer. Linux users can use KPDF or Evince
viewers.

	surface = cairo_pdf_surface_create("pdffile.pdf", 504, 648);

To render a pdf file, we must create a pdf surface using the 
`cairo_pdf_surface_create()` function call. The size of the pdf file is 
specified in points, which is a standard in typesetting.

	cairo_show_page(cr);

The `cairo_show_page()` finishes rendering of the pdf file.

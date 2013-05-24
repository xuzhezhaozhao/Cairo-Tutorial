##示例程序

Makefile的写法有参考价值!

FAQ: <http://cairographics.org/FAQ/#minimal_C_program>


##Cairo definitions

In this part of the Cairo graphics tutorial, we will provide some useful 
definitions for the Cairo graphics library. This will help us better understand
the Cairo drawing model.

###Context

To do some drawing in Cairo, we must first create a Cairo context. The Cairo 
context holds all of the graphics state parameters that describe how drawing 
is to be done. This includes information such as line width, colour, the surface
to draw to, and many other things. This allows the actual drawing functions to 
take fewer arguments to simplify the interface. The gdk_cairo_create() function
call creates a cairo context for drawing on a GDK window. A GDK window is one of
the supported Cairo backends.

	cairo_t *cr;
	cr = gdk_cairo_create(gtk_widget_get_window(widget));

These two lines create a cairo context. In this example, the context is tied to
a GdkWindow. A cairo_t structure contains the current state of the rendering 
device, including coordinates of yet to be drawn shapes. Technically speaking, 
the cairo_t objects are called the Cairo contexts.

All drawing with Cairo is always done to a cairo_t object. A Cairo context is 
tied to a specific surface. A PDF, SVG, PNG, GdkWindow etc.

The GDK does not wrap the Cairo API. It allows to create a Cairo context, which
can be used to draw on GDK windows.

###Path

A path is made up of one or more lines. These lines are connected by two or more
anchor points. Paths can be made up of straight lines and curves. There are two
kinds of paths. Open and closed paths. In a closed path, starting and ending
points meet. In an open path, starting and ending point do not meet.

In Cairo, we start with an empty path. First we define a path and then we make
them visible by stroking and filling them. One important note. After each cairo
_stroke() or cairo_fill() function calls, the path is emptied. We have to define
a new path.

A path is made of subpaths.

###Source

The source is the paint we use in drawing. We can compare the source to a pen or
ink, that we will use to draw the outlines and fill the shapes. There are four
kinds of basic sources. Colors, gradients, patterns and images.

###Surface

A surface is a destination that we are drawing to. We can render documents using
the PDF or PostScript surfaces, directly draw to a platform via the Xlib and 
Win32 surfaces.

The documentation mentions the following surfaces:

	typedef enum _cairo_surface_type {
	  CAIRO_SURFACE_TYPE_IMAGE,
	  CAIRO_SURFACE_TYPE_PDF,
	  CAIRO_SURFACE_TYPE_PS,
 	 CAIRO_SURFACE_TYPE_XLIB,
  	CAIRO_SURFACE_TYPE_XCB,
 	 CAIRO_SURFACE_TYPE_GLITZ,
  	CAIRO_SURFACE_TYPE_QUARTZ,
  	CAIRO_SURFACE_TYPE_WIN32,
  	CAIRO_SURFACE_TYPE_BEOS,
  	CAIRO_SURFACE_TYPE_DIRECTFB,
  	CAIRO_SURFACE_TYPE_SVG,
  	CAIRO_SURFACE_TYPE_OS2
	} cairo_surface_type_t;

###Mask

Before the source is applied to the surface, it is filtered first. The mask is
used as a filter. The mask determines, where the sourse is applied and where not.
Opaque parts of the mask allow to copy the source. Transparent parts do not let
to copy the source to the surface.

###Pattern

A cairo pattern represents a source when drawing onto a surface. In cairo, a 
pattern is something that you can read from, that is used as the source or mask
of a drawing operation. Patterns in cairo can be solid, surface-based or 
gradients patterns.

In this chapter of the Cairo tutorial, we have given some basic definitions.

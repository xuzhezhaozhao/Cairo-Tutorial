

The example pops up a centered GTK window, on which we draw the "Disziplin ist Macht" text.

	#include <cairo.h>
	#include <gtk/gtk.h>

We include the necessary Cairo and GTK headers.

	static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, 
    	gpointer user_data)
	{      
  	cr = gdk_cairo_create(gtk_widget_get_window(widget));
  	do_drawing(cr);
  	cairo_destroy(cr);

  	return FALSE;
	}
	
In the `on_draw_event()` function, we create a Cairo context. It is a graphics
object on which we perform the drawing operations. Actual drawing is delegated 
to the `do_drawing()` function. After the drawing, the cairo context is destroyed.

	static void do_drawing(cairo_t *cr)
	{
	  	cairo_set_source_rgb(cr, 0, 0, 0);
  		cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL,
      		CAIRO_FONT_WEIGHT_NORMAL);
  		cairo_set_font_size(cr, 40.0);
	
  		cairo_move_to(cr, 10.0, 50.0);
  		cairo_show_text(cr, "Disziplin ist Macht.");    
	}

The drawing is done in the do_drawing() function.

	darea = gtk_drawing_area_new();
	gtk_container_add(GTK_CONTAINER(window), darea);

We create a GtkDrawingArea widget and add it to the container window. It is 
used for custom drawing.

	g_signal_connect(G_OBJECT(darea), "draw", 
   	 G_CALLBACK(on_draw_event), NULL); 

When the GtkDrawingArea widget needs to be redrawn, it emits the draw signal. We
connect that signal to the on_draw_event() callback.

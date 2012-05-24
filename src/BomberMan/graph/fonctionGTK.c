# include <stdio.h>
# include <stdlib.h>
# include <cairo.h>
# include <gtk/gtk.h>
#include "fonctionGTK.h"
#include "../jeu/structures.h"

GtkWidget * CreationFenetre( int argc, char ** argv )
{
    GtkWidget * window;
    /* Passe les arguments à GTK, pour qu'il extrait ceux qui le concernent. */
    gtk_init( &argc, &argv );
    /* Crée une fenêtre. */
    window = gtk_window_new( GTK_WINDOW_TOPLEVEL );
    /* La rend visible. */
    
    // mes box  
	GtkWidget * hbox1 = gtk_hbox_new( FALSE, 30 );
	GtkWidget * hbox2 = gtk_hbox_new( FALSE, 30 );
	GtkWidget * hbox3 = gtk_vbox_new( FALSE, 30 );
	GtkWidget * hbox31 = gtk_hbox_new( FALSE, 30 );
	GtkWidget * hbox32 = gtk_hbox_new( FALSE, 30 );
	GtkWidget * hbox33 = gtk_hbox_new( FALSE, 30 );
	GtkWidget * vbox1 = gtk_vbox_new( FALSE, 30 );
    
	// bouton quit
	GtkWidget * button_quit;
	button_quit = gtk_button_new_with_label( "Quitter" );
	// Connecte la réaction gtk_main_quit à l'événement "clic" sur ce bouton.
	g_signal_connect( button_quit, "clicked",G_CALLBACK( gtk_main_quit ), NULL );
    
	// bouton INIT
	GtkWidget * button_init;
	button_init = gtk_button_new_with_label( "Initialisation" );
	//TO DO : connecter le bouton à un événement
   
	// Bouton droite
	GtkWidget * right = gtk_button_new_with_label( ">" );
  
	//Bouton gauche
	GtkWidget * left = gtk_button_new_with_label( "<" );
  
	//bouton haut
	GtkWidget * up = gtk_button_new_with_label( "^" );
  
	//bouton bas
	GtkWidget * down = gtk_button_new_with_label( "v" );
  
	// drawing area( cairo )
	GtkWidget * drawing_area = gtk_drawing_area_new( );
	// largeur=150 pixels, hauteur = 100 pixels. #######################################################
	gtk_widget_set_size_request( drawing_area, 340, 340 );
  
	// Rajoute les composants dans les conteneurs 
	gtk_container_add( GTK_CONTAINER( hbox1 ), button_quit );
  
	gtk_container_add( GTK_CONTAINER( hbox1 ), button_init );
	gtk_container_add( GTK_CONTAINER( hbox3 ), hbox31 );
	gtk_container_add( GTK_CONTAINER( hbox3 ), hbox32 );
	gtk_container_add( GTK_CONTAINER( hbox3 ), hbox33 );
	gtk_container_add( GTK_CONTAINER( hbox31 ), up );
	gtk_container_add( GTK_CONTAINER( hbox32 ), left );
	gtk_container_add( GTK_CONTAINER( hbox32 ), right );
	gtk_container_add( GTK_CONTAINER( hbox33 ), down );
	gtk_container_add( GTK_CONTAINER( hbox2 ), drawing_area );
 
	gtk_container_add( GTK_CONTAINER( vbox1 ), hbox2 );
	gtk_container_add( GTK_CONTAINER( vbox1 ), hbox1 );
	gtk_container_add( GTK_CONTAINER( vbox1 ), hbox3 );

	gtk_container_add( GTK_CONTAINER( window ), vbox1 );
	// Rend visible les elements.
	gtk_widget_show( window );
	gtk_widget_show( button_quit );
	gtk_widget_show( button_init );
	gtk_widget_show( left );
	gtk_widget_show( right );
	gtk_widget_show( up );
	gtk_widget_show( down );
	gtk_widget_show( hbox3 );
	gtk_widget_show( hbox31 );
	gtk_widget_show( hbox32 );
	gtk_widget_show( hbox33 );
	gtk_widget_show( hbox1 );
	gtk_widget_show( vbox1 );
	gtk_widget_show( hbox2 );
	gtk_widget_show( drawing_area );

    /* Rentre dans la boucle d'événements. */
    /* Tapez Ctrl-C pour sortir du programme ! */
     
    return drawing_area;
}

gboolean on_expose_event( GtkWidget * widget, GdkEventExpose * event, gpointer data )
{
	Jeu k;
	int i, j;
	k = fichierStructMap( k );
	for ( i=0;i<10;i++ )
	{
		for ( j=0;j<10;j++ )
		{
			//printf( "typeCase[%d][%d]:%s\n", i, j, k.carte.cases[i][j].typeCase );
			cairo_surface_t * image;
			cairo_t * cr;
			image = cairo_image_surface_create_from_png( k.carte.cases[i][j].typeCase );
			cr = gdk_cairo_create( widget->window );
			cairo_set_source_surface( cr, image, i*34, j*34 );
			cairo_paint( cr );
			cairo_destroy( cr );
			cairo_surface_destroy( image );
		}
	}
	return TRUE;
}

gboolean realize_evt_reaction( GtkWidget * widget, gpointer data )
 { 
	 // force un événement "expose" juste derrière.
	gtk_widget_queue_draw( widget ); 
	return TRUE;
 }

int AfficheImage( GtkWidget	* window, int argc, char ** argv )
{
	g_signal_connect( G_OBJECT( window ), "realize", G_CALLBACK( realize_evt_reaction ), NULL );
	g_signal_connect( G_OBJECT( window ), "expose_event", G_CALLBACK( on_expose_event ), NULL );
	gtk_widget_set_app_paintable( window, TRUE );
	gtk_widget_show_all( window );
	return 0;
}

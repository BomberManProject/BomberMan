# include <stdio.h>
# include <stdlib.h>
# include <cairo.h>
# include <gtk/gtk.h>
#include "BomberMan/graph/fonctionGTK.h"
#include "BomberMan/graph/fonctionGTK.c"

int main(int argc, char ** argv)
{
	GtkWidget *window;
	//gtk_init(&argc, &argv);
	window=CreationFenetre(argc,argv);
	
	AfficheImage(window,argc,argv);
	 gtk_main ();
	return 0;
	
}


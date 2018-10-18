#include <stdlib.h>
#include <math.h>
#include <gtk/gtk.h>
#include "tetris.h"

typedef struct {
  Grille g;
  Piece tab[ NB_PIECES ];
  int piece; // la piece "en cours" que l'on cherche à placer.
  int col; // la colonne actuelle pour la pièce que l'on cherche à caser.
  int score; // le score
  int delay; // le delay
} Jeu;

gboolean Gauche( GtkWidget *widget, gpointer data )
{
  // Recupère la valeur passée en paramètre.
  int val1 = * ( (int*) data ); 
  printf( "Gauche, val=%d\n", val1 ); // affichera 17
  return TRUE; // Tout s'est bien passé
}

gboolean Bas( GtkWidget *widget, gpointer data )
{
  // Recupère la valeur passée en paramètre.
  int val1 = * ( (int*) data ); 
  printf( "Bas, val=%d\n", val1 ); // affichera 17
  return TRUE; // Tout s'est bien passé
}

gboolean Droite( GtkWidget *widget, gpointer data )
{
  // Recupère la valeur passée en paramètre.
  int val1 = * ( (int*) data ); 
  printf( "Droite, val=%d\n", val1 ); // affichera 17
  return TRUE; // Tout s'est bien passé
}

gboolean New_B( GtkWidget *widget, gpointer data )
{
  // Recupère la valeur passée en paramètre.
  int val1 = * ( (int*) data ); 
  printf( "New, val=%d\n", val1 ); // affichera 17
  return TRUE; // Tout s'est bien passé
}

GtkWidget* create_arrow_button( GtkArrowType  arrow_type ) {
	GtkWidget* button = gtk_button_new ();
	GtkWidget* arrow = gtk_arrow_new (arrow_type, GTK_SHADOW_OUT);
	gtk_container_add (GTK_CONTAINER (button), arrow);
	gtk_widget_show_all( button );


	return button;
}

void dessineCarre(cairo_t* cr, int ligne, int colonne, char c) {
	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_rectangle(cr, ligne, colonne, 30, 30);
	cairo_fill_preserve(cr);
	cairo_set_line_width(cr, 3);
	cairo_stroke(cr);
}

void dessinerGrille(cairo_t* cr, Grille g) {
	
}

gboolean realize_evt_reaction( GtkWidget *widget, gpointer data ){
	gtk_widget_queue_draw( widget ); 
	return TRUE;
}

gboolean expose_evt_reaction( GtkWidget *widget, GdkEventExpose *event, gpointer data ){
	cairo_t* cr = gdk_cairo_create (widget->window);
	cairo_set_source_rgb (cr, 1, 1, 1); // choisit le blanc.
	cairo_paint( cr ); // remplit tout dans la couleur choisie.
	cairo_set_source_rgb (cr, 0, 1, 0);
	cairo_rectangle (cr, 50, 50, 100, 100 ); // x, y, largeur, hauteur
	cairo_fill_preserve( cr ); // remplit la forme actuelle (un rectangle)
	// => "_preserve" garde la forme (le rectangle) pour la suite
 	cairo_set_line_width(cr, 3);
	cairo_set_source_rgb (cr, 0, 0.5, 0);
	cairo_stroke( cr ); // trace la forme actuelle (le même rectangle)
	// => pas de "_preserve" donc la forme (le rectangle) est oublié.
	// On a fini, on peut détruire la structure.
	dessineCarre(cr, 0, 0, 0);
	cairo_destroy (cr);
	return TRUE;
 }

void creerIHM(Jeu* ptrJeu) {

	GtkWidget *window;
    
    /* Crée une fenêtre. */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    GtkWidget* button_new = gtk_button_new_with_label("New");
    GtkWidget* button_quit = gtk_button_new_with_label("Quit");

    GtkWidget* label_score = gtk_label_new("Score");
    GtkWidget* label_score_value = gtk_label_new("0");
    GtkWidget* label_delay = gtk_label_new("Delay");
    GtkWidget* label_delay_value = gtk_label_new("TMP");

    GtkWidget* drawing_area= gtk_drawing_area_new();
    gtk_widget_set_size_request(drawing_area, 300, 400);

	GtkWidget* arrow_left = create_arrow_button(GTK_ARROW_LEFT);
	GtkWidget* arrow_down = create_arrow_button(GTK_ARROW_DOWN);
	GtkWidget* arrow_right = create_arrow_button(GTK_ARROW_RIGHT);

    GtkWidget* hbox0 = gtk_hbox_new(FALSE, 10);
    GtkWidget* hbox1 = gtk_hbox_new(FALSE, 10);
    GtkWidget* hbox2 = gtk_hbox_new(FALSE, 10);
    GtkWidget* hbox3 = gtk_hbox_new(FALSE, 10);
    GtkWidget* hbox4 = gtk_hbox_new(FALSE, 10);
    GtkWidget* hbox5 = gtk_hbox_new(FALSE, 10);
    GtkWidget* hbox6 = gtk_hbox_new(FALSE, 10);
    GtkWidget* vbox1 = gtk_vbox_new(FALSE, 10);
    GtkWidget* vbox2 = gtk_vbox_new(FALSE, 10);
    GtkWidget* vbox_new = gtk_vbox_new(FALSE, 10);
    GtkWidget* vbox_quit = gtk_vbox_new(FALSE, 10);
    GtkWidget* vbox_score = gtk_vbox_new(FALSE, 10);
    GtkWidget* vbox_score_value = gtk_vbox_new(FALSE, 10);
    GtkWidget* vbox_delay = gtk_vbox_new(FALSE, 10);
    GtkWidget* vbox_delay_value = gtk_vbox_new(FALSE, 10);
    GtkWidget* vbox_arrow_left = gtk_vbox_new(FALSE, 10);
    GtkWidget* vbox_arrow_down = gtk_vbox_new(FALSE, 10);
    GtkWidget* vbox_arrow_right = gtk_vbox_new(FALSE, 10); 

    gtk_container_add(GTK_CONTAINER(window), hbox0);
    gtk_container_add(GTK_CONTAINER(hbox0), vbox1);
    gtk_container_add(GTK_CONTAINER(hbox0), vbox2);
    gtk_container_add(GTK_CONTAINER(vbox1), hbox1);
    gtk_container_add(GTK_CONTAINER(vbox1), hbox2);
    gtk_container_add(GTK_CONTAINER(vbox2), hbox3);
    gtk_container_add(GTK_CONTAINER(vbox2), hbox4);
    gtk_container_add(GTK_CONTAINER(vbox2), hbox5);
    gtk_container_add(GTK_CONTAINER(vbox2), hbox6);
    gtk_container_add(GTK_CONTAINER(hbox1), drawing_area);
    gtk_container_add(GTK_CONTAINER(hbox3), vbox_new);
    gtk_container_add(GTK_CONTAINER(hbox3), vbox_quit);
    gtk_container_add(GTK_CONTAINER(hbox4), vbox_score);
    gtk_container_add(GTK_CONTAINER(hbox4), vbox_score_value);
    gtk_container_add(GTK_CONTAINER(hbox5), vbox_delay);
    gtk_container_add(GTK_CONTAINER(hbox5), vbox_delay_value);

    gtk_container_add(GTK_CONTAINER(vbox_new), button_new);
    gtk_container_add(GTK_CONTAINER(vbox_quit), button_quit);
    gtk_container_add(GTK_CONTAINER(vbox_score), label_score);
    gtk_container_add(GTK_CONTAINER(vbox_score_value), label_score_value);
    gtk_container_add(GTK_CONTAINER(vbox_delay), label_delay);
    gtk_container_add(GTK_CONTAINER(vbox_delay_value), label_delay_value);

    gtk_container_add(GTK_CONTAINER(hbox2), vbox_arrow_left);
    gtk_container_add(GTK_CONTAINER(hbox2), vbox_arrow_down);
    gtk_container_add(GTK_CONTAINER(hbox2), vbox_arrow_right);

    gtk_container_add(GTK_CONTAINER(vbox_arrow_left), arrow_left);
    gtk_container_add(GTK_CONTAINER(vbox_arrow_down), arrow_down);
    gtk_container_add(GTK_CONTAINER(vbox_arrow_right), arrow_right);

    gtk_widget_show_all(window);

    int val0=1;

    g_signal_connect(button_quit, "clicked", G_CALLBACK(gtk_main_quit), NULL);
 	g_signal_connect(arrow_left, "clicked", G_CALLBACK(Gauche),&val0);
 	g_signal_connect(arrow_down, "clicked", G_CALLBACK(Bas),&val0);
 	g_signal_connect(arrow_right, "clicked", G_CALLBACK(Droite),&val0);
    g_signal_connect(button_new, "clicked", G_CALLBACK(New_B),&val0);
    g_signal_connect(G_OBJECT(drawing_area), "realize", G_CALLBACK(realize_evt_reaction), ptrJeu);
    g_signal_connect(G_OBJECT(drawing_area), "expose_event", G_CALLBACK(expose_evt_reaction), ptrJeu);
}

int main( int   argc, char *argv[] )
{
	gtk_init (&argc, &argv);
	Jeu jeu;
	initialiseGrille(jeu.g);
	creerIHM(&jeu);
    gtk_main ();
    return 0;
}
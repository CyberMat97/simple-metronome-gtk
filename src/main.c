#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <gtk/gtk.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "audio.h"

/*create a pointer to your Glade objects*/
GtkWidget *window;
GtkWidget *btn_play;
GtkWidget *sbtn_speed;
GtkWidget *Grid;
GtkWidget *lbl_text;
GtkBuilder *builder;

static Mix_Chunk *BEEP;

int main(int argc, char *argv[])
{
    /*initialize gtk and SDL*/
    BEEP = load_sound(BEEP_SINUSOID);
    gtk_init(&argc, &argv);
    startSDL();

    builder = gtk_builder_new_from_file("glade/window_main.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);

    Grid = GTK_WIDGET(gtk_builder_get_object(builder, "Grid"));
    btn_play = GTK_WIDGET(gtk_builder_get_object(builder, "btn_play"));
    sbtn_speed = GTK_WIDGET(gtk_builder_get_object(builder, "sbtn_speed"));
    lbl_text = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_text"));


    gtk_widget_show(window);
    gtk_main();

    closeSDL();
    exit(EXIT_SUCCESS);
}

void on_window_main_destroy()
{
    gtk_main_quit();
}

void on_btn_play_clicked()
{
    play_sound(BEEP);
    /*sample*/
    g_print("Ciao");
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <gtk/gtk.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "audio.h"

static gboolean continue_value;

/*create a pointer to your Glade objects*/
GtkWidget *window;
GtkWidget *btn_play;
GtkWidget *sbtn_speed;
GtkWidget *Grid;
GtkWidget *lbl_text;
GtkBuilder *builder;

static Mix_Chunk *BEEP;
static gboolean start = FALSE;

gboolean play_sound(Mix_Chunk *beep){
    Mix_PlayChannel(-1, beep, 0);

    return continue_value;
}

int main(int argc, char *argv[])
{
    /*initialize gtk and SDL*/
    gtk_init(&argc, &argv);
    startSDL();

    BEEP = load_sound(BEEP_SINUSOID);

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
    if (start == FALSE){
        start = TRUE;
        continue_value = TRUE;
        g_timeout_add(1000, play_sound, BEEP);
        /*TODO: implement time setting*/
        /*usleep(1000000);*/

    } else {
        stop_sound();
        continue_value = FALSE;
        start = FALSE;
    }
    /*sample*/
    g_print("Ciao\n");
}

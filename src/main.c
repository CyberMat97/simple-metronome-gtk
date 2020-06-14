#include <stdio.h>
#include <unistd.h>
#include <gtk/gtk.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

/*local libraries*/
#include "gtk_functions.h"
#include "audio.h"

int main()
{
    startSDL();
    GtkBuilder      *builder;
    GtkWidget       *window;

    builder = gtk_builder_new_from_file("glade/window_main.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);

    gtk_widget_show(window);
    gtk_main();

    closeSDL();
    exit(EXIT_SUCCESS);
}

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <gtk/gtk.h>
#include "audio.h"

void startSDL(){
    SDL_Init(SDL_INIT_AUDIO);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
}

void closeSDL(){
    Mix_CloseAudio();
    SDL_Quit();
}

Mix_Chunk* load_sound(char *file_ptr){
    Mix_Chunk *sound = Mix_LoadWAV(file_ptr);
    if (sound==NULL)
    {
        /*TODO error handling*/
        fprintf(stderr, "Error: something loading '%s' went wrong\n", file_ptr);
    }

    return sound;
}

/*gboolean play_sound(Mix_Chunk *beep){
    Mix_PlayChannel(-1, beep, 0);

    return continue_value;
}*/

void stop_sound(){
    Mix_HaltChannel(-1);
}

/* TODO:
    Mix_Chunk *beep_sinusoid = Mix_LoadWAV(FILE_PATH);

    Mix_PlayChannel(-1, beep_sinusoid, 0);

    Mix_FreeChunk(beep_sinusoid);
*/

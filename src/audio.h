#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#define BEEP_SINUSOID "sounds/beep_sinusoid.wav"

/*init SDL function*/
void startSDL();

/*quit SDL function*/
void closeSDL();

/*load sound from source*/
Mix_Chunk* load_sound(char *file_ptr);

/*self explanatory name*/
void play_sound(Mix_Chunk *beep);

/*stop sound from all channels*/
void stop_sound();

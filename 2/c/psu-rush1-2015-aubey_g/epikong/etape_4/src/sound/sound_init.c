/*
** main.c for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 19:09:16 2012 geoffroy aubey
** Last update Sat Mar  3 19:09:16 2012 geoffroy aubey
*/

#include <stdlib.h>
#include <stdio.h>
#include "sound.h"

void sound_error(FMOD_RESULT result, FMOD_SYSTEM *system)
{
  if (result != FMOD_OK)
  {
    printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
    FMOD_System_Close(system);
    FMOD_System_Release(system);
    exit(-1);
  }
}

void msound_init_engine(t_sound *sound)
{
  FMOD_RESULT     result;

  result = FMOD_System_Create(&sound->system);
  sound_error(result, sound->system);
  result = FMOD_System_Init(sound->system, 5, FMOD_INIT_NORMAL, NULL);
  sound_error(result, sound->system);
  result = FMOD_System_CreateSound(sound->system, "data/sound/music.mp3",
      FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &sound->music);
  sound_error(result, sound->system);
  result = FMOD_System_CreateSound(sound->system, "data/sound/end.mp3",
      FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &sound->end);
  sound_error(result, sound->system);
  result = FMOD_System_CreateSound(sound->system, "data/sound/fire1.mp3",
      FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &sound->fire);
  sound_error(result, sound->system);
  FMOD_System_GetChannel(sound->system, 2, &sound->channel);
  FMOD_System_GetMasterChannelGroup(sound->system, &sound->master);
  sound->init = START;
}

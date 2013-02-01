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

/*
** TODO  mode degrade ?
*/

void msound_start_song(t_sound *sound)
{
  FMOD_RESULT     result;
  if (sound->init != START)
  {
    printf("FMOD error! init sound engine \
        before call sound engine function\n");
    exit(-1);
  }
  result = FMOD_System_PlaySound(sound->system,
      FMOD_CHANNEL_FREE, sound->music, 0, NULL);
  sound_error(result, sound->system);
  FMOD_Sound_SetLoopCount(sound->music, -1);
}

void msound_start_fire(t_sound *sound)
{
  FMOD_RESULT     result;

  if (sound->init != START)
  {
    printf("FMOD error! init sound engine \
        before call sound engine function\n");
    exit(-1);
  }
  result = FMOD_System_PlaySound(sound->system,
      FMOD_CHANNEL_FREE, sound->fire, 0, NULL);
  sound_error(result, sound->system);
}

void msound_start_end(t_sound *sound)
{
  FMOD_RESULT     result;

  if (sound->init != START)
  {
    printf("FMOD error! init sound engine \
        before call sound engine function\n");
    exit(-1);
  }
  FMOD_Sound_Release(sound->music);
  result = FMOD_System_PlaySound(sound->system,
      FMOD_CHANNEL_FREE, sound->end, 0, NULL);
  sound_error(result, sound->system);
  FMOD_Sound_SetLoopCount(sound->end, -1);
}

void msound_down(t_sound *sound)
{
  FMOD_ChannelGroup_SetVolume(sound->master, 0.f);
  printf("volume %.1f \n", 0.f);
}

void msound_up(t_sound *sound)
{
  float cur;

  FMOD_ChannelGroup_GetVolume(sound->master, &cur);
  cur += 0.1f;
  if (cur > 1.f)
    cur = 1.f;
  FMOD_ChannelGroup_SetVolume(sound->master, cur);
  printf("volume %.1f \n", cur);
}

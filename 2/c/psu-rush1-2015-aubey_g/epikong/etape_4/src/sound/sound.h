/*
** epikong.h for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 19:10:22 2012 geoffroy aubey
** Last update Sat Mar  3 19:10:22 2012 geoffroy aubey
*/

#ifndef SOUND_H
# define SOUND_H

#include "../../api/inc/fmod.h"
#include "../../api/inc/fmod_errors.h"

# define START			0xFF

typedef struct s_sound
{
  int		init;
  FMOD_SYSTEM   *system;
  FMOD_CHANNEL  *channel;
  FMOD_CHANNELGROUP *master;
  FMOD_RESULT   result;
  FMOD_SOUND    *music;
  FMOD_SOUND    *end;
  FMOD_SOUND    *fire;
} t_sound;

void msound_init_engine(t_sound *sound);
void msound_start_song(t_sound *sound);
void msound_start_fire(t_sound *sound);
void msound_start_end(t_sound *sound);
void msound_down(t_sound *sound);
void msound_up(t_sound *sound);

void sound_error(FMOD_RESULT result, FMOD_SYSTEM *system);
void msound_init_engine(t_sound *sound);

#endif /* end of include guard: SOUND_H */

/*
** event.h for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 19:10:21 2012 geoffroy aubey
** Last update Sat Mar  3 19:10:21 2012 geoffroy aubey
*/

#ifndef _EVENT_H_
#define _EVENT_H_

typedef enum
  {
    NONE = 0,
    MOVE_UP = 1 << 1,
    MOVE_DOWN = 1 << 2,
    MOVE_LEFT = 1 << 3,
    MOVE_RIGHT = 1 << 4,
    SELECT = 1 << 5,
    JUMP = 1 << 6,
    ESCAPE = 1 << 7,
    EXIT = 1 << 8
  } e_event_type;

typedef struct
{
  e_event_type action;
} t_event;

void	get_event(t_event *e);

#endif /* !_EVENT_H_ */

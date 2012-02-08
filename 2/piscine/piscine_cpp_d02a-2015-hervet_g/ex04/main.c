/*
** main.c for ex04 in /home/hervet_g/piscine/piscine_cpp_d02a-2015-hervet_g/ex04
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Jan 05 23:38:18 2012 geoffrey hervet
** Last update Thu Jan 05 23:38:18 2012 geoffrey hervet
*/

#include	<stdio.h>

#include	"queue.h"

int main(void)

{

t_queue queue = NULL;

int i = 5;

int j = 4;

int *data;



queue_push(&queue, &i);

queue_push(&queue, &j);



 data = (int *)queue_front(queue);



 printf("%d\n", *data);



 return (0);

 }




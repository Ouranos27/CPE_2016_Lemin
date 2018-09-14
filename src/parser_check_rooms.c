/*
** parser_check_rooms.c for lemin in /home/amaury/delivery/CPE_2016_Lemin
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Sun Apr 30 19:44:11 2017 Amaury Bernard
** Last update Sun Apr 30 19:44:11 2017 Amaury Bernard
*/

#include <stdlib.h>
#include "lemin.h"
#include "parser.h"

int		check_a_n_b_rooms(t_room *a, t_room *b)
{
  if (!a || !b)
    return (0);
  if (my_strcmp(a->room_name, b->room_name) == 0)
    return (ERR_FATAL);
  if (a->room_pos[X] == b->room_pos[X]
      && a->room_pos[Y] == b->room_pos[Y])
    return (ERR_FATAL);
  return (0);
}

int		check_a_room(t_anthill *anthill, t_room *room)
{
  int		i;

  if (!anthill || !(anthill->room) || !room)
    return (0);
  i = -1;
  while (anthill->room[++i] != NULL)
    {
      if (my_strcmp(anthill->room[i]->room_name, room->room_name) == 0)
	return (ERR_FATAL);
      if (anthill->room[i]->room_pos[X] == room->room_pos[X]
	  && anthill->room[i]->room_pos[Y] == room->room_pos[Y])
	return (ERR_FATAL);
    }
  return (0);
}

int		check_rooms(t_anthill *anthill)
{
  int		i;
  int		j;

  if (!anthill || !(anthill->room))
    return (0);
  i = -1;
  while (anthill->room[++i] != NULL)
    {
      j = -1;
      while (anthill->room[++j] != NULL)
	{
	  if (i == j && anthill->room[j + 1] != NULL)
	    ++j;
	  else
	    break ;
	  if (check_a_n_b_rooms(anthill->room[i],
				anthill->room[j]) == ERR_FATAL)
	  return (ERR_FATAL);
	}
    }
  if ((check_a_room(anthill, anthill->start) == ERR_FATAL)
      || (check_a_room(anthill, anthill->end) == ERR_FATAL)
      || (check_a_n_b_rooms(anthill->start, anthill->end) == ERR_FATAL))
    return (ERR_FATAL);
  return (0);
}

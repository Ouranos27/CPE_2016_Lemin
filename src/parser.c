/*
** parser.c for lemin in /home/amaury/delivery/CPE_2016_Lemin
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Thu Apr 13 16:58:22 2017 Amaury Bernard
** Last update Thu Apr 13 16:58:22 2017 Amaury Bernard
*/

#include <stdlib.h>
#include "lemin.h"
#include "parser.h"

t_anthill	*alloc_n_ini_anthill()
{
  t_anthill	*anthill;

  if (!(anthill = malloc(sizeof(t_anthill))))
    return (NULL);
  anthill->number_of_ant = -1;
  anthill->room = NULL;
  anthill->start = NULL;
  anthill->end = NULL;
  return (anthill);
}

int		parser_number_of_ant(t_anthill *anthill, char *line)
{
  if (patern_checker("*", line) == FALSE || my_str_isnum(line) != 1)
    return (ERR_FATAL);
  anthill->number_of_ant = my_atoi(line);
  my_printf("#number_of_ants\n%d\n", anthill->number_of_ant);
  return (0);
}

int		parser_rooms(t_anthill *anthill, char *line,
				     int *check_room, int *nb_room)
{
  if ((*check_room == ROOM_START && !(anthill->start = set_room(line)))
      || (*check_room == ROOM_END && !(anthill->end = set_room(line))))
    return (ERR_FATAL);
  else if (*check_room != ROOM_START && *check_room != ROOM_END)
    {
      if (others_rooms(anthill, *nb_room, line) == ERR_FATAL)
	return (ERR_FATAL);
      ++(*nb_room);
    }
  *check_room = ROOM_NDEF;
  return (0);
}

int		parser_main(t_anthill *anthill, int *check_room,
			    char *line)
{
  static int		nb_room;

  if (anthill->number_of_ant == -1)
    {
      if (parser_number_of_ant(anthill, line) != ERR_FATAL)
	return (0);
    }
  else if (patern_checker("* * *", line))
    {
      if (parser_rooms(anthill, line, check_room, &nb_room) != ERR_FATAL)
	return (0);
    }
  else if (patern_checker("*-*", line))
    {
      if (parser_links(anthill, line, check_room) != ERR_FATAL)
	return (0);
    }
  return (ERR_FATAL);
}

t_anthill	*parser()
{
  t_anthill	*anthill;
  char		*line;
  int		check_room;

  if (!(anthill = alloc_n_ini_anthill()))
    return (NULL);
  check_room = ROOM_NDEF;
  while ((line = get_next_line(0)) != NULL)
    {
      if (*line == 0)
	return (NULL);
      if (my_strcmp("##start", line) == 0 && my_printf("%s\n", line) > 0)
	check_room = ROOM_START;
      else if (my_strcmp("##end", line) == 0  && my_printf("%s\n", line) > 0)
	check_room = ROOM_END;
      else if (line[0] != '#'
	       && parser_main(anthill, &check_room, line) == ERR_FATAL)
	return (NULL);
      if (check_rooms(anthill) == ERR_FATAL)
	return (NULL);
     free(line);
    }
  if (!anthill->start || !anthill->end || my_printf("#moves\n") < 0)
    return (NULL);
  return (anthill);
}

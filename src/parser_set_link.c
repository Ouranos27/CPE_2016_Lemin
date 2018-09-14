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

char		*set_link_room2(char *room_name)
{
  while (*room_name != '-')
    {
      if (*room_name == 0)
	return (NULL);
      ++room_name;
    }
  *room_name = 0;
  ++room_name;
  return (room_name);
}

char		**add_to_tab(char **tab, char *line)
{
  int		i;
  char		**new_tab;

  i = 0;
  while (tab != NULL && tab[i] != NULL)
    {
      if (my_strcmp(tab[i], line) == 0)
	{
	  my_printf("%e", "ERROR: link du même nom\n");
	  return (NULL);
	}
      ++i;
    }
  if (!(new_tab = malloc(sizeof(char *) * (i + 2))))
    return (NULL);
  line = my_strdup(line);
  i = 0;
  while (tab != NULL && tab[i] != NULL)
    {
      new_tab[i] = tab[i];
      ++i;
    }
  new_tab[i] = line;
  new_tab[i + 1] = NULL;
  return (new_tab);
}

t_room		**set_good_rooms_link(t_room *room, t_room **rooms_tolink,
				      char *name1, char *name2)
{
  if (rooms_tolink == NULL)
    {
      if (!(rooms_tolink = malloc(sizeof(char **) * 2)))
	return (NULL);
      rooms_tolink[ROOM_1] = NULL;
      rooms_tolink[ROOM_2] = NULL;
    }
  if (my_strcmp(room->room_name, name1) == 0)
    rooms_tolink[ROOM_1] = room;
  else if (my_strcmp(room->room_name, name2) == 0)
    rooms_tolink[ROOM_2] = room;
 return (rooms_tolink);
}

int		set_link(t_anthill *anthill, char *room1)
{
  char		*room2;
  int		nb_room;
  t_room	**rooms_tolink;

  rooms_tolink = NULL;
  if (!(room2 = set_link_room2(room1))
      || (my_strcmp(room1, room2) == 0))
    return (ERR_FATAL);
  nb_room = -1;
  while (anthill->room && anthill->room[++nb_room] != NULL)
    rooms_tolink = set_good_rooms_link(anthill->room[nb_room],
				     rooms_tolink, room1, room2);
   rooms_tolink = set_good_rooms_link(anthill->start,
				    rooms_tolink, room1, room2);
   rooms_tolink = set_good_rooms_link(anthill->end,
				    rooms_tolink, room1, room2);
  if ((!rooms_tolink[ROOM_1] || !rooms_tolink[ROOM_1])
      || !(rooms_tolink[ROOM_1]->room_link =
	   add_to_tab(rooms_tolink[ROOM_1]->room_link, room2))
      || !(rooms_tolink[ROOM_2]->room_link =
	   add_to_tab(rooms_tolink[ROOM_2]->room_link, room1)))
    return (ERR_FATAL);
  my_printf("%s-%s\n", room1, room2);
  return (0);
}

int		parser_links(t_anthill *anthill, char *line,
			     int *check_room)
{
  if (*check_room != ROOM_STOP && my_printf("#tunnels\n") > 0)
    *check_room = ROOM_STOP;
  if (set_link(anthill, line))
    return (ERR_FATAL);
  return (0);
}

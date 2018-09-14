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

/*
** Return TRUE if the string is conform to the patern
** '*' is the aknow string value, alphaNumeric
** If the string is bigger then patern, the string is cuted
** at the end of the patern
*/
int		patern_checker(char *patern, char *string)
{
  if (string == 0)
    return (FALSE);
  --patern;
  while (*(++patern) != 0)
    {
      if (*patern == '*')
	while ((*string >= '0' && *string <= '9')
	       || (*string >= 'a' && *string <= 'z')
	       || (*string >= 'A' && *string <= 'Z'))
	  ++string;
      else if (*patern == *string)
	++string;
      else
	return (FALSE);
    }
  if (*patern != 0)
    return (FALSE);
  while ((*string == ' ' || *string == '\t') && *string != '\0')
    *string++ = 0;
  if (*string != '#' && *string != 0)
    return (FALSE);
  return (TRUE);
}

/*
** Sapces are replace by 0 value
*/
int		string_replacer_n_len(char *in)
{
  int		len;

  len = my_strlen(in);
  while (*in != 0)
    {
      if (*in == ' ')
	*in = 0;
      ++in;
    }
  return (len);
}

int		set_name_or_pos(t_room *room, int *i, int *elem, char *input)
{
  if (++(*elem) == -1)
    {
      if (!(room->room_name = my_strdup(&input[*i])))
	return (ERR_FATAL);
    }
  else if ((*elem == 0 || *elem == 1) && my_str_isnum(&input[*i]) == 1)
    room->room_pos[*elem] = my_atoi(&input[*i]);
  else
    return (ERR_FATAL);
  return (0);
}

t_room		*set_room(char *input)
{
  t_room	*room;
  int		i;
  int		elem;
  int		len;

  if ((room = malloc(sizeof(t_room))) == NULL
      || (room->room_pos = malloc(sizeof(int) * 2)) == NULL)
    return (NULL);
  elem = -2;
  i = -1;
  len = string_replacer_n_len(input);
  while (++i < len)
    {
      if ((i == 0 || input[i - 1] == 0)
	  && (set_name_or_pos(room, &i, &elem, input) == ERR_FATAL))
	return (NULL);
    }
  room->room_link = NULL;
  room->ant_number = 0;
  if (my_printf("%s %d %d\n", room->room_name,
		room->room_pos[X], room->room_pos[Y]) < 0)
    return (NULL);
  return (room);
}

int		others_rooms(t_anthill *anthill, int nb_room, char *line)
{
  t_room	**room;

  if (!(room = malloc(sizeof(t_anthill *) * (nb_room + 2))))
    return (ERR_FATAL);
  room[nb_room + 1] = NULL;
  if (!(room[nb_room] = set_room(line)))
    return (ERR_FATAL);
  if (anthill->room != NULL)
    {
      while (--nb_room >= 0)
	room[nb_room] = anthill->room[nb_room];
      free(anthill->room);
    }
  anthill->room = room;
  return (0);
}

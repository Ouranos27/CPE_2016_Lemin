/*
** lemin.h for lemin in /home/artha/CPE_2016_Lemin
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sun Apr 30 23:16:22 2017 dylan renard
** Last update Sun Apr 30 23:16:24 2017 dylan renard
*/

#ifndef LEMIN_H_
# define LEMIN_H_

# include "my.h"
# include <stdlib.h>
# include <unistd.h>

# define ERR_FATAL	84
# define X		0
# define Y		1

typedef struct	s_room
{
  char		*room_name;
  int		*room_pos;
  char		**room_link;
  int		ant_number;
}		t_room;

typedef struct	s_anthill
{
  int		number_of_ant;
  t_room	*start;
  t_room	**room;
  t_room	*end;
}		t_anthill;

t_anthill	*parser();
char		*get_next_line(int fd);
int		my_printf(char *, ...);

#endif /* !LEMIN_H_ */

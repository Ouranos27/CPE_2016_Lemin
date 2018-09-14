/*
** parser.h for lemin  in /home/amaury/delivery/CPE_2016_Lemin
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Sun Apr 30 17:28:14 2017 Amaury Bernard
** Last update Sun Apr 30 17:28:14 2017 Amaury Bernard
*/

#ifndef PARSER_H_
# define PARSER_H_

#define ROOM_START	-1
#define ROOM_STOP	-2
#define ROOM_END	-3
#define ROOM_NDEF	-4
#define TRUE		1
#define FALSE		0

#define ROOM_1		0
#define ROOM_2		1

int		patern_checker(char *patern, char *string);
int		string_replacer_n_len(char *in);
int		set_name_or_pos(t_room *room, int *i, int *elem, char *input);
t_room		*set_room(char *input);
int		others_rooms(t_anthill *anthill, int nb_room, char *line);

char		*set_link_room2(char *room_name);
char		**add_to_tab(char **tab, char *line);
int		set_link(t_anthill *anthill, char *room1);
int		parser_links(t_anthill *anthill, char *line,
			     int *check_room);

int		check_rooms(t_anthill *anthill);

#endif /* PARSER_H_ */

/*
** tree.h for tree in /home/artha/CPE_2016_Lemin
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sat Apr 29 14:37:32 2017 dylan renard
** Last update Sun Apr 30 23:08:25 2017 dylan renard
*/

#ifndef TREE_H_
# define TREE_H_
#include "list.h"
#include "lemin.h"
#include "queue.h"

typedef struct		s_link
{
  int			weight;
  struct s_node		*node;
}			t_link;

typedef struct		s_node
{
  char			*name;
  int			nb_ant;
  int			*pos;
  int			pass;
  t_ld			*link;
}			t_node;

typedef struct		s_graph
{
  int			nb_node;
  t_node		**start;
  t_node		*end;
}			t_graph;

t_graph			*create_graph(t_anthill *);
int			count_room(t_anthill *);
t_node			*to_node(t_list *);
t_node			*create_node(t_room *, int);
t_room			*find_room_by_name(char *, t_anthill *);
t_node			*find_node_by_name(char *, t_graph *);
t_link			*search_link_by_node(t_node *, t_node *);
void			add_weight_to_link(t_node *, int);
void			add_node_to_queue(t_queue *);
void			print_queue(t_queue *);
int			queue_count_item(t_queue *);
#endif /* !TREE_H_ */

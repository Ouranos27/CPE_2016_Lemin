/*
** tree_utils.c for lemin in /home/artha/CPE_2016_Lemin
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sun Apr 30 22:54:09 2017 dylan renard
** Last update Sun Apr 30 23:11:43 2017 dylan renard
*/

#include "my.h"
#include "lemin.h"
#include "tree.h"
#include "list.h"
#include "queue.h"

int		count_room(t_anthill *anthill)
{
  int		nb;

  if (anthill == NULL)
    return (-1);
  nb = 0;
  while (anthill->room[nb] != NULL)
    nb++;
  return (nb + 2);
}

t_node		*to_node(t_list *list)
{
  t_node	*node;

  node = list->data;
  return (node);
}

t_node		*create_node(t_room *room, int nb)
{
  t_node	*node;

  if (room == NULL)
    return (NULL);
  if ((node = malloc(sizeof(t_node))) == NULL)
    return (NULL);
  node->name = my_strdup(room->room_name);
  node->pos = room->room_pos;
  node->nb_ant = nb;
  node->pass = 0;
  node->link = new_list();
  return (node);
}

t_room		*find_room_by_name(char *name, t_anthill *anthill)
{
  t_room	*room;
  int		i;

  i = 0;
  room = NULL;
  if (my_strcmp(anthill->start->room_name, name) == 0)
    room = anthill->start;
  if (my_strcmp(anthill->end->room_name, name) == 0)
    room = anthill->end;
  while (anthill->room[i] != NULL)
    {
      if (my_strcmp(anthill->room[i]->room_name, name) == 0)
	room = anthill->room[i];
      i++;
    }
  if (room == NULL) return (NULL);
  return (room);
}

t_node		*find_node_by_name(char *name, t_graph *graph)
{
  int		i;
  t_node	*node;

  i = 0;
  node = NULL;
  while (graph->start[i] != graph->end)
    {
      if (my_strcmp(graph->start[i]->name, name) == 0)
	{
	  node = graph->start[i];
	  break;
	}
      i++;
    }
  if (my_strcmp(graph->end->name, name) == 0)
    node = graph->end;
  return (node);
}

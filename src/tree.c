/*
** tree.c for lemin in /home/artha/CPE_2016_Lemin
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sat Apr 29 14:36:33 2017 dylan renard
** Last update Sun Apr 30 22:58:11 2017 dylan renard
*/

#include "my.h"
#include "lemin.h"
#include "tree.h"
#include "list.h"
#include "queue.h"

int		make_link(t_node *node, t_graph *graph, t_anthill *anthill)
{
  int		i;
  t_room	*room;
  t_node	*current;
  t_link	*link;

  i = 0;
  room = find_room_by_name(node->name, anthill);
  if (room == NULL)
    return (1);
  while (room->room_link != NULL && room->room_link[i] != NULL)
    {
      current = find_node_by_name(room->room_link[i], graph);
      if (current != NULL)
	{
	  if ((link = malloc(sizeof(t_link))) == NULL)
	    return (1);
	  link->weight = -1;
	  link->node = current;
	  push_begin_list(node->link, link);
	}
      i++;
    }
  return (1);
}

void		make_all_link(t_graph *graph, t_anthill *anthill)
{
  int		i;

  i = 0;
  while (graph->start[i] != graph->end)
    {
      make_link(graph->start[i], graph, anthill);
      i++;
    }
  make_link(graph->end, graph, anthill);
}

t_graph		*create_graph(t_anthill *anthill)
{
  t_graph	*graph;
  int		i;

  i = 1;
  if (anthill == NULL) return (NULL);
  if ((graph = xmalloc(sizeof(t_graph))) == NULL)
    return (NULL);
  if ((graph->nb_node = count_room(anthill)) == -1) return (NULL);
  if ((graph->start = malloc(sizeof(t_node *) * (graph->nb_node + 1))) == NULL)
    return (NULL);
  graph->start[0] = create_node(anthill->start, anthill->number_of_ant);
  if (graph->start[0] == NULL)
    return (NULL);
  if ((graph->end = create_node(anthill->end, 0)) == NULL)
    return (NULL);
  while (i != graph->nb_node - 1)
    {
      graph->start[i] = create_node(anthill->room[i - 1], 0);
      i++;
    }
  graph->start[i] = graph->end;
  make_all_link(graph, anthill);
  return (graph);
}

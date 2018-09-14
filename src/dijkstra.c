/*
** dijkstra.c for Lemin in /home/ouranos27/my_desktop/CPE/CPE_2016_Lemin/src
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Fri Apr 28 16:48:09 2017 philippe kam
** Last update Fri Apr 28 16:48:09 2017 philippe kam
*/

#include "lemin.h"
#include "tree.h"

int		position_in_start(t_graph *graph, t_node *node)
{
  int		i;

  i = 0;
  while (my_strcmp(graph->start[i]->name, node->name) != 0)
    ++i;
  return (i);
}

t_link		*find_min_weight(t_graph *graph, int i)
{
  int		mini;
  int		used_node;
  t_link	*link;
  t_list	*temp;

  mini = -1;
  used_node = 0;
  temp = graph->start[i]->link->next;
  link = temp->data;
  while (temp != NULL)
    {
      /*if (node->nb_ants != 0)
	used_node = mini;*/
      //if (prev_node == NULL || prev_node->id_ant > 0)
      if (mini > link->weight || mini < 0)// && mini != used_node)
	{
	  link = temp->data;
	  mini = link->weight;
	}
      temp = temp->next;
    }
  my_printf("%s -- %d\n", link->node->name, mini);
  return (link);
}


void		dijkstra(t_graph *graph)//, int id)
{
  int		i;
  t_link	*link;

  i = 0;
  while (graph->start[i] != graph->end)
    {
      link = find_min_weight(graph, i);
      i = position_in_start(graph, link->node);
    }
  //link = find_min_weight(graph, i);
}

/*void	traffic_managemant(t_graph *graph, t_anthill *anthill)
{
  int	id;

  id = 1;
  while (id < anthill->number_of_ants)
    {
      dijkstra(graph, id);
      ++id;
    }
    }*/

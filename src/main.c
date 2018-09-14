/*
** main.c for my_strlen in /home/Artha77/CPE_2016_Lemin/src
**
** Made by dylan renard
** Login   <Artha77@epitech.net>
**
** Started on  Thu Oct  6 08:59:36 2016 dylan renard
** Last update Sun Apr 30 23:12:31 2017 dylan renard
*/

#include "tree.h"
#include "list.h"
#include "lemin.h"
#include "queue.h"

int		is_finish(t_queue *queue)
{
  t_link	*link;
  t_node	*node;
  t_list	*list;

  if (queue_count_item(queue) != 1)
    return (0);
  node = queue->next->data;
  list = node->link->next;
  while (list !=NULL)
    {
      link = list->data;
      node = link->node;
      if (node->pass == 0)
	return (0);
      list = list->next;
    }
  return (1);
}

int		count_link(t_node *node)
{
  int		i;
  t_list	*list;

  list = node->link->next;
  i = 0;
  while (list != NULL)
    {
      i++;
      list = list->next;
    }
  return (i);
}

void		make_weight(t_graph *graph)
{
  int		weight;
  t_node	*cur_node;
  t_queue	*queue;
  int		node_to_incr;

  queue = new_queue();
  node_to_incr = 0;
  enqueue(queue, graph->end);
  weight = 1;
  while (is_finish(queue) != 1)
    {
      cur_node = value_of_queue(queue);
      if (node_to_incr != 0)
	node_to_incr -= count_link(cur_node);
      if (node_to_incr == 0)
	node_to_incr = count_link(cur_node);
      if (node_to_incr < 0)
	node_to_incr = 0;
      add_weight_to_link(cur_node, weight);
      add_node_to_queue(queue);
      cur_node->pass = 1;
      dequeue(queue);
      weight = (node_to_incr == 0) ? weight + 1 : weight;
    }
  cur_node = value_of_queue(queue);
}

void		print_link(t_node *node)
{
  t_list	*list;
  t_node	*cur_node;
  t_link	*cur_link;

  list = node->link->next;
  my_printf("link : ");
  if (list == NULL)
    my_printf("NULL");
  while (list != NULL)
    {
      cur_link = list->data;
      cur_node = cur_link->node;
      my_printf("%s-%d : ", cur_node->name, cur_link->weight);
      list = list->next;
    }
  my_printf("\n");
}

int		main()
{
  t_anthill	*anthill;
  t_graph	*graph;

  if ((anthill = parser()) == NULL)
    return (ERR_FATAL);
  graph = create_graph(anthill);
  make_weight(graph);
  return (0);
}

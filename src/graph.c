/*
** graph.c for lemin in /home/artha/CPE_2016_Lemin
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sun Apr 30 23:00:21 2017 dylan renard
** Last update Sun Apr 30 23:06:34 2017 dylan renard
*/

#include "tree.h"
#include "list.h"
#include "lemin.h"
#include "queue.h"

t_link		*search_link_by_node(t_node *to_find, t_node *node)
{
  t_list	*list;
  t_link	*link;

  list = node->link->next;
  link = list->data;
  while (link->node != to_find)
    {
      list = list->next;
      link = list->data;
    }
  return (link);
}

void		add_weight_to_link(t_node *node, int weight)
{
  t_list	*list;
  t_link	*link;

  list = node->link->next;
  while (list != NULL)
    {
      link = list->data;
      if (link->weight == -1)
	{
	  link->weight = weight;
	  link = search_link_by_node(node, link->node);
	  link->weight = weight;
	}
      list = list->next;
    }
}

void		add_node_to_queue(t_queue *queue)
{
  t_list	*list;
  t_link	*link;
  t_node	*cur_node;

  cur_node = value_of_queue(queue);
  list = cur_node->link->next;
  while (list != NULL)
    {
      link = list->data;
      if (link->node->pass != 1)
	{
	  enqueue(queue, link->node);
	  link->node->pass = 1;
	}
      list = list->next;
    }
}

void		print_queue(t_queue *queue)
{
  t_list	*list;
  t_node	*node;

  list = queue->next;
  while (list != NULL)
    {
      node = list->data;
      my_printf("[%s]->", node->name);
      list = list->next;
    }
  my_printf("NULL\n");
}

int		queue_count_item(t_queue *queue)
{
  t_list	*list;
  int		i;

  list = queue->next;
  i = 0;
  while (list != NULL)
    {
      i++;
      list = list->next;
    }
  return (i);
}

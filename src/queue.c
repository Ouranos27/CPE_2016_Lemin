/*
** queue.c for queue in /home/artha/CPE_2016_Lemin
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sun Apr 30 22:53:01 2017 dylan renard
** Last update Sun Apr 30 22:53:30 2017 dylan renard
*/

#include "my.h"
#include "lemin.h"
#include "tree.h"
#include "list.h"
#include "queue.h"

t_queue		*new_queue(void)
{
  return (new_list());
}

void		enqueue(t_queue *queue, void *data)
{
  push_end_list(queue, data);
}

t_node		*value_of_queue(t_queue *queue)
{
  return ((t_node *)queue->next->data);
}

void		dequeue(t_queue *queue)
{
  pop_list(queue);
}

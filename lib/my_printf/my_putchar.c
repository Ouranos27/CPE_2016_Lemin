/*
** my_putchar.c for my_putchar in /home/amaury/CPool_Day03
**
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
**
** Started on  Wed Oct  5 10:42:23 2016 Amaury Bernard
** Last update Sun Apr 30 23:21:33 2017 dylan renard
*/

#include <unistd.h>

void	my_putchar(char c, int *len)
{
  write(1, &c, 1);
  *len += 1;
}

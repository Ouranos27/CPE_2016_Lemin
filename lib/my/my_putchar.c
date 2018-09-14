/*
** my_putchar.c for my_putchar in /home/Artha77/CPool_Day06/test
**
** Made by dylan renard
** Login   <Artha77@epitech.net>
**
** Started on  Tue Oct 11 18:19:09 2016 dylan renard
** Last update Mon Jan 16 21:10:07 2017 dylan renard
*/

#include <unistd.h>

int	my_putchar(char c)
{
  if ((write(1, &c, 1)) == -1)
    return (0);
  return (1);
}

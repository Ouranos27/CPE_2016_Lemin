/*
** my_putchar_fd.c for lib in /home/artha/lib_next/my
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Mon Jan 16 17:30:10 2017 dylan renard
** Last update Mon Jan 16 17:35:48 2017 dylan renard
*/

#include <unistd.h>

int	my_putchar_fd(char c, int fd)
{
  if ((write(fd, &c, 1)) == -1)
    return (0);
  return (1);
}

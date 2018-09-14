/*
** my_puterr.c for  in /home/Artha77/CPool_infinadd/src
**
** Made by dylan renard
** Login   <Artha77@epitech.net>
**
** Started on  Sun Oct 23 14:57:53 2016 dylan renard
** Last update Sun Oct 23 15:57:56 2016 dylan renard
*/

#include <unistd.h>
#include "my.h"

void		my_puterr(const char *s)
{
  write(2, s, my_strlen(s));
}

/*
** is_bt.c for is_bt in /home/Artha77/my_lib
** 
** Made by dylan renard
** Login   <Artha77@epitech.net>
** 
** Started on  Wed Oct 12 07:30:19 2016 dylan renard
** Last update Wed Oct 12 07:30:38 2016 dylan renard
*/

int	is_bt(char c, char a, char b)
{
  if (c >= a && c <= b)
    {
      return (1);
    }
  else
    {
      return (0);
    }
}

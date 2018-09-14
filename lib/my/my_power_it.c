/*
** my_power.c for my_power_it in /home/Artha77/tmp
**
** Made by dylan renard
** Login   <Artha77@epitech.net>
**
** Started on  Fri Oct  7 06:50:54 2016 dylan renard
** Last update Fri Feb 24 09:08:04 2017 dylan renard
*/

int	my_power_it(int nb, int power)
{
  int	nbi;

  nbi = nb;
  if (power == 0)
    {
      return (1);
    }
  if (power == 1)
    {
      return (nb);
    }
  while (power != 1)
    {
      if (power > 0)
	{
	  nb = nb * nbi;
	  power = power - 1;
	}
      else
	return (0);
    }
  return (nb);
}

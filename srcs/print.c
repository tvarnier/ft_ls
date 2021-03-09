/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/13 06:28:08 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 10:42:51 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_pathname(char *str)
{
	ft_putstr(str);
	ft_putendl(":");
}

void	print_folder(t_ls *ls, t_file **file, t_max *max, int nbr_file)
{
	int		i;

	if (file)
	{
		i = -1;
		while (++i < nbr_file)
		{
			if (ls->o_l)
				print_l(ls, file[i], max);
			else
				print_standard(ls, file[i], max);
		}
	}
}

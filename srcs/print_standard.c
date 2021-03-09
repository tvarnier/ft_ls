/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_standard.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 13:09:13 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/24 15:50:59 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	move_cursor(int line, int col)
{
	if (line != 0)
	{
		ft_putstr("\033[");
		ft_putnbr((line > 0) ? line : line * -1);
		if (line > 0)
			ft_putchar('A');
		else
			ft_putchar('B');
	}
	if (col != 0)
	{
		ft_putstr("\033[");
		ft_putnbr((col > 0) ? col : col * -1);
		if (col > 0)
			ft_putchar('C');
		else
			ft_putchar('D');
	}
}

void	print_standard(t_ls *ls, t_file *file, t_max *max)
{
	char	*name;

	name = (!ft_strlen(file->name)) ? file->path : file->name;
	print_name(ls, file);
	move_cursor(0, (int)ft_strlen(name) * -1);
	(max->line)++;
	(max->file)++;
	if (max->file == max->nbr_file)
		move_cursor((max->nbr_line - max->line) * -1,
				max->col * (max->name + 1) * -1);
	else if (max->line == max->nbr_line)
	{
		(max->col)++;
		max->line = 0;
		move_cursor(max->nbr_line - 1, max->name + 1);
	}
	else if (max->col == 0)
		ft_putchar('\n');
	else
		move_cursor(-1, 0);
}

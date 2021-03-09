/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_l.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 13:50:00 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/23 15:59:34 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_l(t_ls *ls, t_file *file, t_max *max)
{
	print_right(file, file->s.st_mode);
	ft_putchar(' ');
	print_nlink(file->s.st_nlink, max->nlink, ft_intlen(file->s.st_nlink));
	ft_putchar(' ');
	if (!ls->o_g)
	{
		print_user(file, max->usr);
		ft_putstr("  ");
	}
	print_group(file, max->grp);
	ft_putstr("  ");
	print_size(file->s.st_size, file->s.st_rdev, max);
	ft_putchar(' ');
	if (ls->o_u)
		print_date(file->s.st_atime);
	else
		print_date(file->s.st_mtime);
	ft_putchar(' ');
	print_name(ls, file);
	ft_putchar('\n');
}

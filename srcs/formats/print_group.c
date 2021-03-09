/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_group.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/17 14:14:01 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/19 11:05:49 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_group(t_file *file, int max_grp)
{
	char	*grp;
	int		i;
	int		mod;

	if (!(grp = ft_strinit(' ', max_grp)))
		return ;
	if (file->grp)
	{
		file->grp = getgrgid(file->s.st_gid);
		ft_strins(grp, file->grp->gr_name, 0);
	}
	else
	{
		i = ft_intlen(file->s.st_gid);
		mod = 1;
		while (--i >= 0)
		{
			grp[i] = file->s.st_gid / mod % 10 + '0';
			mod *= 10;
		}
	}
	ft_putstr(grp);
	ft_strdel(&grp);
}

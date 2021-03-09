/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_user.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/17 14:13:06 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/19 11:22:25 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_user(t_file *file, int max_usr)
{
	char	*usr;
	int		i;
	int		mod;

	if (!(usr = ft_strinit(' ', max_usr)))
		return ;
	if (file->usr)
	{
		file->usr = getpwuid(file->s.st_uid);
		ft_strins(usr, file->usr->pw_name, 0);
	}
	else
	{
		i = ft_intlen(file->s.st_uid);
		mod = 1;
		while (--i >= 0)
		{
			usr[i] = file->s.st_uid / mod % 10 + '0';
			mod *= 10;
		}
	}
	ft_putstr(usr);
	ft_strdel(&usr);
}

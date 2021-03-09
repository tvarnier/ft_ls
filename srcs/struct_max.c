/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_max.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/17 14:29:23 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/24 15:53:35 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_max(t_max *max)
{
	max->name = 0;
	max->nbr_file = 0;
	max->file = 0;
	max->nbr_line = 0;
	max->line = 0;
	max->col = 0;
	max->nlink = 0;
	max->usr = 0;
	max->grp = 0;
	max->size = 0;
	max->major = 0;
	max->minor = 0;
	max->date = 0;
	max->block = 0;
}

void	get_max_name(t_file *file, t_max *max, int g_cap)
{
	if (!g_cap && !ft_strlen(file->name)
			&& (int)ft_strlen(file->path) > max->name)
		max->name = ((int)ft_strlen(file->path) / 8) * 8 + 7;
	else if (!g_cap && (int)ft_strlen(file->name) > max->name)
		max->name = ((int)ft_strlen(file->name) / 8) * 8 + 7;
	else if (g_cap && !ft_strlen(file->name)
			&& (int)ft_strlen(file->path) > max->name)
		max->name = (int)ft_strlen(file->path);
	else if (g_cap && (int)ft_strlen(file->name) > max->name)
		max->name = (int)ft_strlen(file->name);
}

void	get_max_size(t_file *file, t_max *max)
{
	if (file->s.st_size > 0 && ft_intlen(file->s.st_size) > max->size)
		max->size = ft_intlen(file->s.st_size);
	else if (file->s.st_size == 0)
	{
		if (ft_intlen(major(file->s.st_rdev)) > max->major)
			max->major = ft_intlen(major(file->s.st_rdev));
		if (ft_intlen(minor(file->s.st_rdev)) > max->minor)
			max->minor = ft_intlen(minor(file->s.st_rdev));
		if (max->major + 2 + max->minor > max->size)
			max->size = max->major + 2 + max->minor;
	}
}

void	get_max(t_ls *ls, t_file *file, t_max *max)
{
	if (file)
	{
		max->nbr_file++;
		get_max_name(file, max, ls->o_g_cap);
		if (ft_intlen(file->s.st_nlink) > max->nlink)
			max->nlink = ft_intlen(file->s.st_nlink);
		if (file->usr && (int)ft_strlen(file->usr->pw_name) > max->usr)
			max->usr = (int)ft_strlen(file->usr->pw_name);
		else if (!file->usr && ft_intlen(file->s.st_uid) > max->usr)
			max->usr = ft_intlen(file->s.st_uid);
		if (file->grp && (int)ft_strlen(file->grp->gr_name) > max->grp)
			max->grp = (int)ft_strlen(file->grp->gr_name);
		else if (!file->grp && ft_intlen(file->s.st_gid) > max->grp)
			max->grp = ft_intlen(file->s.st_gid);
		get_max_size(file, max);
		max->block += file->s.st_blocks;
	}
}

int		max_nbr_line(t_max max)
{
	int				nbr_line;
	struct winsize	w;

	w.ws_col = 0;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	if (w.ws_col && w.ws_col > max.name)
	{
		nbr_line = max.nbr_file / (w.ws_col / (max.name + 1));
		nbr_line += (max.nbr_file % (w.ws_col / (max.name + 1)) != 0) ? 1 : 0;
	}
	else
		nbr_line = 1;
	return (nbr_line);
}

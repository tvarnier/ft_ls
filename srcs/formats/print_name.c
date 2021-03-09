/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_name.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/17 14:16:01 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/24 15:52:42 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_exec(mode_t m)
{
	return (((m & S_IXUSR) == S_IXUSR || (m & S_IXGRP) == S_IXGRP
				|| (m & S_IXOTH) == S_IXOTH));
}

void	change_color(mode_t m)
{
	if (S_ISDIR(m) && (m & S_ISVTX) != S_ISVTX && (m & S_IWOTH) == S_IWOTH)
		ft_putstr(WOTH_DIR_NSTICK);
	else if (S_ISDIR(m) && (m & S_ISVTX) == S_ISVTX && (m & S_IWOTH) == S_IWOTH)
		ft_putstr(WOTH_DIR_STICK);
	else if (S_ISDIR(m))
		ft_putstr(DIRECTORY);
	else if (S_ISCHR(m))
		ft_putstr(SPEC_CHAR);
	else if (S_ISBLK(m))
		ft_putstr(BLOCK);
	else if (S_ISFIFO(m))
		ft_putstr(FIFO);
	else if (S_ISSOCK(m))
		ft_putstr(SOCKET);
	else if (S_ISLNK(m))
		ft_putstr(LINK);
	else if ((m & S_ISUID) == S_ISUID && is_exec(m))
		ft_putstr(UID_EXEC);
	else if ((m & S_ISGID) == S_ISGID && is_exec(m))
		ft_putstr(GID_EXEC);
	else if (is_exec(m))
		ft_putstr(EXEC);
	else
		ft_putstr(DEFAULT);
}

void	print_name(t_ls *ls, t_file *file)
{
	char	*name;
	char	*buf;
	int		ret;

	if (!(buf = ft_strnew(NAME_MAX)))
		return ;
	if (ls->o_g_cap)
		change_color(file->s.st_mode);
	name = (!ft_strlen(file->name)) ? file->path : file->name;
	ft_putstr(name);
	if (ls->o_g_cap)
		ft_putstr(DEFAULT);
	if (ls->o_l && (ret = readlink(file->path, buf, NAME_MAX)) != -1)
	{
		ft_putstr(" -> ");
		ft_putstr(buf);
	}
	ft_strdel(&buf);
}

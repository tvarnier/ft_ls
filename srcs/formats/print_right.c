/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_right.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/17 14:09:13 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/19 11:19:22 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

char	type_char(mode_t m)
{
	if (S_ISBLK(m))
		return ('b');
	else if (S_ISCHR(m))
		return ('c');
	else if (S_ISDIR(m))
		return ('d');
	else if (S_ISLNK(m))
		return ('l');
	else if (S_ISFIFO(m))
		return ('p');
	else if (S_ISSOCK(m))
		return ('s');
	else
		return ('-');
}

char	exec_char(mode_t m, int t)
{
	if ((t == 1 && (m & S_ISUID) == S_ISUID && (m & S_IXUSR) != S_IXUSR)
			|| (t == 2 && (m & S_ISGID) == S_ISGID && (m & S_IXGRP) != S_IXGRP))
		return ('S');
	else if ((t == 1 && (m & S_ISUID) == S_ISUID && (m & S_IXUSR) == S_IXUSR)
			|| (t == 2 && (m & S_ISGID) == S_ISGID && (m & S_IXGRP) == S_IXGRP))
		return ('s');
	else if (t == 3 && (m & S_ISVTX) == S_ISVTX && (m & S_IXOTH) != S_IXOTH)
		return ('T');
	else if (t == 3 && (m & S_ISVTX) == S_ISVTX && (m & S_IXOTH) == S_IXOTH)
		return ('t');
	else if ((t == 1 && (m & S_IXUSR) == S_IXUSR)
			|| (t == 2 && (m & S_IXGRP) == S_IXGRP)
			|| (t == 3 && (m & S_IXOTH) == S_IXOTH))
		return ('x');
	return ('-');
}

char	acl_char(t_file *file)
{
	acl_t	acl;

	if (listxattr(file->path, NULL, 0, 0) > 0)
		return ('@');
	else if ((acl = acl_get_file(file->path, ACL_TYPE_EXTENDED)))
	{
		acl_free((void *)acl);
		return ('+');
	}
	return (' ');
}

void	print_right(t_file *file, mode_t mode)
{
	char	*c;

	if (!(c = ft_strnew(11)))
		return ;
	c[0] = type_char(mode);
	c[1] = ((mode & S_IRUSR) == S_IRUSR) ? 'r' : '-';
	c[2] = ((mode & S_IWUSR) == S_IWUSR) ? 'w' : '-';
	c[3] = exec_char(mode, 1);
	c[4] = ((mode & S_IRGRP) == S_IRGRP) ? 'r' : '-';
	c[5] = ((mode & S_IWGRP) == S_IWGRP) ? 'w' : '-';
	c[6] = exec_char(mode, 2);
	c[7] = ((mode & S_IROTH) == S_IROTH) ? 'r' : '-';
	c[8] = ((mode & S_IWOTH) == S_IWOTH) ? 'w' : '-';
	c[9] = exec_char(mode, 3);
	c[10] = acl_char(file);
	ft_putstr(c);
	ft_strdel(&c);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/15 05:52:46 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/24 15:56:59 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <grp.h>
# include <sys/xattr.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <sys/syslimits.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/acl.h>
# include <sys/xattr.h>

# define OPTIONS "GRadfglrtu"

# define DIRECTORY "\033[34m\033[49m"
# define LINK "\033[35m\033[49m"
# define SOCKET "\033[32m\033[49m"
# define FIFO "\033[33m\033[49m"
# define EXEC "\033[31m\033[49m"
# define BLOCK "\033[34m\033[46m"
# define SPEC_CHAR "\033[34m\033[43m"
# define UID_EXEC "\033[30m\033[41m"
# define GID_EXEC "\033[30m\033[46m"
# define WOTH_DIR_STICK "\033[30m\033[42m"
# define WOTH_DIR_NSTICK "\033[30m\033[43m"
# define DEFAULT "\033[0m"

typedef struct		s_file
{
	char			*path;
	char			*name;
	struct stat		s;
	struct passwd	*usr;
	struct group	*grp;
}					t_file;

typedef struct		s_ls
{
	int				nbr_paths;
	t_file			**paths;
	int				opt;
	int				o_a;
	int				o_d;
	int				o_f;
	int				o_g;
	int				o_g_cap;
	int				o_l;
	int				o_r;
	int				o_r_cap;
	int				o_t;
	int				o_u;
}					t_ls;

typedef struct		s_max
{
	int				name;
	int				nbr_file;
	int				file;
	int				nbr_line;
	int				line;
	int				col;
	int				nlink;
	int				usr;
	int				grp;
	int				size;
	int				major;
	int				minor;
	int				date;
	int				block;
}					t_max;

typedef struct		s_merge
{
	int				l;
	int				m;
	int				r;
	int				i;
	int				j;
	int				k;
	int				n1;
	int				n2;
}					t_merge;

void				init_ls(t_ls *ls);
void				free_ls(t_ls *ls);
t_file				*create_file(char *name, char *path);
void				free_files(t_file ***file, int nbr_file);

void				init_max(t_max *max);
void				get_max(t_ls *ls, t_file *file, t_max *max);
int					max_nbr_line(t_max max);

int					check_options(t_ls *ls, char **options, int nbr_options);
t_file				**pr_paths(t_ls *ls, int ac, char **av);
int					error_file(char *name);
void				browse_paths(t_ls *ls, t_file **paths);
void				browse_folder(t_ls *ls, char *path);
void				merge_sort(t_ls *ls, t_file **ar, int l, int r);

void				print_folder(t_ls *ls, t_file **file, t_max *max,
		int nbr_file);
void				print_standard(t_ls *ls, t_file *file, t_max *max);
void				print_l(t_ls *ls, t_file *file, t_max *max);

void				print_pathname(char *str);
void				print_name(t_ls *ls, t_file *file);
void				print_right(t_file *file, mode_t mode);
void				print_nlink(nlink_t nlink, int max_nlink, int size);
void				print_user(t_file *file, int max_usr);
void				print_group(t_file *file, int max_grp);
void				print_size(off_t st_size, dev_t st_rdev, t_max *max);
void				print_date(time_t date);
void				print_total(int total);

#endif

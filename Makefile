# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/15 23:02:25 by tvarnier     #+#   ##    ##    #+#        #
#    Updated: 2019/03/23 17:19:59 by tvarnier    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = ft_ls

CC = gcc

FLAGS = -Wall -Wextra -Werror
LIB = libft/libft.a

HEADER = ./includes/ft_ls.h

SRC =	main.c \
		options.c \
		pr_paths.c \
		browse_paths.c \
		browse_folder.c \
		file_cmp.c \
		print.c \
		print_standard.c \
		print_l.c \
		formats/print_date.c \
		formats/print_group.c \
		formats/print_name.c \
		formats/print_nlink.c \
		formats/print_right.c \
		formats/print_size.c \
		formats/print_user.c \
		formats/print_total.c \
		struct.c \
		struct_max.c

SRC_DIR = srcs
SRCS = $(SRC:%.c=$(SRC_DIR)/%.c)

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIB) $(OBJ_DIR) $(OBJ)
	$(CC) -I includes -o $@ $(OBJ) $(LIB) $(FLAGS)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)
	mkdir $(OBJ_DIR)/formats

$(LIB):
	make -C libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	$(CC) -I includes -o $@ -c $< $(FLAGS)

clean:
	make -C libft clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(LIB)
	rm -rf $(NAME)

re: fclean all

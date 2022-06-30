# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 13:17:29 by amarzana          #+#    #+#              #
#    Updated: 2022/06/30 18:10:08 by amarzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = 	./libft/ft_putendl_fd.c		\
		./libft/ft_putstr_fd.c		\
		./libft/ft_split.c 			\
		./libft/ft_strjoin_free.c	\
		./libft/ft_strlcat.c		\
		./libft/ft_strlcpy.c		\
		./libft/ft_strlen.c			\
		./libft/ft_strnstr.c		\
		./libft/ft_substr.c			\
		./utils.c					\
		./pipex.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@$(CC) $(CFLAGS) $(SRC) -o pipex
	@echo Compilation done

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo OBJ files removed

fclean: clean
	@rm -f $(NAME)
	@echo pipex file removed

re: fclean all

.PHONY: all clean fclean re
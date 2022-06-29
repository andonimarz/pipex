# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 13:17:29 by amarzana          #+#    #+#              #
#    Updated: 2022/06/29 16:32:19 by amarzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = 	ft_get_path.c		\
		ft_putendl_fd.c		\
		ft_putstr_fd.c		\
		ft_split.c 			\
		ft_strjoin_free.c	\
		ft_strlcat.c		\
		ft_strlcpy.c		\
		ft_strlen.c			\
		ft_strnstr.c		\
		ft_substr.c			\
		utils.c				\
		pipex.c

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
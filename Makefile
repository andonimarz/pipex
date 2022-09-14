# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 13:17:29 by amarzana          #+#    #+#              #
#    Updated: 2022/09/14 15:31:35 by amarzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)

SRC = 	./libft/ft_putendl_fd.c		\
		./libft/ft_putstr_fd.c		\
		./libft/ft_split.c 			\
		./libft/ft_strjoin_free.c	\
		./libft/ft_strlcat.c		\
		./libft/ft_strlcpy.c		\
		./libft/ft_strlen.c			\
		./libft/ft_strnstr.c		\
		./libft/ft_substr.c			\
		./libft/ft_strncmp.c		\
		./utils.c					\
		./pipex.c

BONUS = ./libft/ft_putendl_fd.c		\
		./libft/ft_putstr_fd.c		\
		./libft/ft_split.c 			\
		./libft/ft_strjoin_free.c	\
		./libft/ft_strlcat.c		\
		./libft/ft_strlcpy.c		\
		./libft/ft_strlen.c			\
		./libft/ft_strnstr.c		\
		./libft/ft_substr.c			\
		./libft/ft_strncmp.c		\
		./utils.c					\
		./bonus.c

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo Mandatory: Compilation done

bonus: $(BONUS_OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJ)
	@echo Bonus: Compilation done

%.o: %.c
	@echo Generating object $@
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)
	@echo Object files removed

fclean: clean
	@rm -f $(NAME)
	@echo Executable file removed

re: fclean all

.PHONY: all clean fclean re bonus
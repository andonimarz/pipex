# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 13:17:29 by amarzana          #+#    #+#              #
#    Updated: 2022/07/08 17:10:20 by amarzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS_NAME = pipex_bonus
CC = gcc
OBJ_DIR = ../obj
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

BONUS = ./libft/ft_putendl_fd.c		\
		./libft/ft_putstr_fd.c		\
		./libft/ft_split.c 			\
		./libft/ft_strjoin_free.c	\
		./libft/ft_strlcat.c		\
		./libft/ft_strlcpy.c		\
		./libft/ft_strlen.c			\
		./libft/ft_strnstr.c		\
		./libft/ft_substr.c			\
		./utils.c					\
		./bonus.c

all: $(NAME)

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@$(CC) $(CFLAGS) $(SRC) -o pipex
	@echo Mandatory: Compilation done

bonus: $(BONUS_NAME)

BONUS_OBJ = $(BONUS:.c=.o)

$(BONUS_NAME): $(BONUS_OBJ)
	@ar -rc $(BONUS_NAME) $(BONUS_OBJ)
	@ranlib $(BONUS_NAME)
	@$(CC) $(CFLAGS) $(BONUS) -o pipex_bonus
	@echo Bonus: Compilation done

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)
	@echo OBJ files removed

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@rm -f outfile
	@echo Executable file removed

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 13:17:29 by amarzana          #+#    #+#              #
#    Updated: 2022/06/30 18:12:52 by amarzana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

BONUS_NAME = pipex_bonus

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
		./pipex_bonus.c

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS:.c=.o)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@$(CC) $(CFLAGS) $(SRC) -o pipex
	@echo Compilation done

$(BONUS_NAME): $(OBJ)
	@ar -rc $(BONUS_NAME) $(OBJ)
	@ranlib $(BONUS_NAME)
	@$(CC) $(CFLAGS) $(BONUS) -o pipex_bonus
	@echo Compilation done

all: $(NAME)

bonus: $(BONUS_NAME)

clean:
	@rm -f $(OBJ)
	@echo OBJ files removed

fclean: clean
	@rm -f $(NAME)
	@echo pipex file removed

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/11 01:49:54 by zcarde            #+#    #+#              #
#    Updated: 2015/12/03 04:42:49 by zcarde           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		=	srcs/
OBJ_DIR		=	build/
INC_DIR		=	includes/ libft/includes
FILE_EXT	=	c

NAME		=	libftprintf.a
BIN_NAME	=	ft_printf
SRC_FILES	=	ft_printf.c\
				ftprintf_atoi.c\
				ftprintf_itoa.c\
				ftprintf_putchar.c\
				ftprintf_putstr.c\
				ftprintf_strchr.c\
				ftprintf_strdup.c\
				ftprintf_strjoin.c\
				ftprintf_strlen.c\
				ftprintf_strsub.c

CC			=	clang
CFLAGS		=	-Wall -Werror -Wextra

SRC		=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ		=	$(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.$(FILE_EXT)=.o))

#.SILENT:
all: $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "\033[32m•\033[0m $(BIN_DIR)$(NAME) is ready."

run: all
	$(CC) $(CFLAGS) $(subst $() $(), -I, $(INC_DIR)) -L . -lftprintf -L libft -lft main.c -o $(BIN_NAME)
	clear
	./ft_printf

$(BIN_NAME): $(OBJ)
	$(CC) $(LIBS) -o $(BIN_NAME) $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.$(FILE_EXT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS)$(subst $() $(), -I, $(INC_DIR)) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean:
	rm -rf $(NAME)
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_NAME)

re: fclean all

.PHONY: all re fclean clean $(BIN_NAME)

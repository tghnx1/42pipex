# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 17:52:33 by mkokorev          #+#    #+#              #
#    Updated: 2024/03/21 12:49:04 by mkokorev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
PRINTFNAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
PRINTFDIR = ./printf
PRINTF_LIB_PATH = $(PRINTFDIR)/libftprintf.a

SRCS = 	errors.c \
		extra.c \
		pipex.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

makeprintf:
	@make -C $(PRINTFDIR) || exit 1
	@cp $(PRINTFDIR)/$(PRINTFNAME) .
	@mv $(PRINTFNAME) $(NAME)

$(NAME): makeprintf $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(PRINTF_LIB_PATH)

clean:
	@rm -f $(OBJS)
	@cd $(PRINTFDIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(PRINTFDIR) && make fclean

re: fclean all

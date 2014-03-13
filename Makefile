#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 09:44:39 by jmaurice          #+#    #+#              #
#    Updated: 2014/02/27 13:07:43 by jmaurice         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = llvm-gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L/usr/X11/lib -lXext -lX11 -L/usr/lib -lmlx
INC = -I/opt/X11/include -I/usr/include/ -I.
FILES = rt cam crea drawl events img inter math utils vector
SRC = $(addsuffix .c, $(FILES))
OBJ = $(addsuffix .o, $(FILES))
NAME = rt

.PHONY: clean fclean re all

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJ): $(SRC)
	$(CC) -c $(CFLAGS) $^ $(INC)

debug: clean
	$(CC) -o $@ -g -Wall -Wextra $(SRC) $(INC) $(LDFLAGS)

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -f debug

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

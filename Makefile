# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbechri <hbechri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 15:24:29 by hbechri           #+#    #+#              #
#    Updated: 2023/04/15 22:26:24 by hbechri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLNAME = client
SVNAME = server
CC = gcc
CFLAGS = -Wall -Wextra -Werror

CLSRC = client.c minitalk_utils.c
SVSRC = server.c minitalk_utils.c

all : $(CLNAME) $(SVNAME)
$(CLNAME) :
	$(CC) $(CFLAGS) $(CLSRC) -o $(CLNAME)
$(SVNAME) :
	$(CC) $(CFLAGS) $(SVSRC) -o $(SVNAME)

clean :
	@rm -rf $(CLNAME)
	@rm -rf $(SVNAME)
fclean : clean

re : fclean all
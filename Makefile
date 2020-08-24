
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkebethi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 08:26:58 by lkebethi          #+#    #+#              #
#    Updated: 2019/09/18 07:05:52 by lkebethi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

lemIN_IO = lem-in

LIBFT = libft/

lemIN_SOURCE = algo1.c\
				algo2.c\
				coord1.c\
				coord2.c\
				coord3.c\
				coord4.c\
				coord5.c\
				del.c\
				error1.c\
				error2.c\
				find1.c\
				find2.c\
				handle1.c\
				handle2.c\
				handle3.c\
				main.c\
				map.c\
				strct.c\
				way1.c\
				way2.c\
				ft_str1.c\
				ft_str2.c
				
					

all: $(lemIN_IO) 

$(lemIN_IO):
	make -C $(LIBFT)/
	$(CC) $(CFLAGS) $(lemIN_SOURCE) $(LIBFT)libft.a -I $(LIBFT) -o $(lemIN_IO)

clean:
	make -C $(LIBFT)/ clean
	rm -f $(OBJECTS)

fclean:
	make -C $(LIBFT)/ fclean
	rm -f $(lemIN_IO) 

re: fclean all
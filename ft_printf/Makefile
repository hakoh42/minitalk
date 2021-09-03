# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakoh <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 10:32:27 by hakoh             #+#    #+#              #
#    Updated: 2020/02/15 17:23:08 by hakoh            ###   ########.fr        #
# **************************************************************************** #

NAME	=	libftprintf.a

FLAGS	=	-Wall -Wextra -Werror

SRCS	=	$(addprefix $(PATHSRCS), \
			ft_printf.c \
			get_arg.c \
			parse.c \
			road.c \
			flags.c \
			buffer.c \
			buffer_bis.c \
			utils.c \
			utils_bis.c \
			utils_next.c \
			print_s.c \
			print_pc.c \
			print_uxdi.c \
			print_x.c \
			print_di.c \
			print_di_next.c \
			)

OBJS	=	$(SRCS:.c=.o)

PATHINC	=	./

HEADERS	=	libftprintf.h

PATHSRCS=	./

all: $(NAME)

$(NAME): $(OBJS) $(addprefix $(PATHINC), $(HEADERS))
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

bonus:	$(NAME)

%.o: %.c
		gcc -o $@ -c $< $(FLAGS) -I $(PATHINC)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re:
		$(MAKE) fclean
		$(MAKE) all

.PHONY		: all clean fclean re

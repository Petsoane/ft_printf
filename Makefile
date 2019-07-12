# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/12 13:00:10 by lpetsoan          #+#    #+#              #
#    Updated: 2019/07/12 13:17:11 by lpetsoan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = ftprintf.a

SRC = ft_printf.c\
	  print_type.c\
	  print_conv.c\
	  print_float.c\
	  get_digit.c\
	  get_field.c\
	  get_flag.c\
	  get_id.c\
	  get_format.c\
	  valid_field.c\
	  valid_width.c\
	  validate.c\
	  spaces.c\
	  valid_flag.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@gcc $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lryst <lryst@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 12:05:57 by lryst             #+#    #+#              #
#    Updated: 2020/02/25 16:32:26 by lryst            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc $(INCLUDES) $(CFLAGS)

CFLAGS = -Wall -Wextra -Werror -g3

NAME = libft.a

HEADERS = libft.h

INCLUDES = -I 

SRCS =	ft_memset.c \
 		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memlen.c \
		ft_strlen.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strlcpy.c \
		ft_strncpy.c \
		ft_strcpy.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_strndup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strjoinfree.c \
		ft_split.c \
		ft_split_set.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putnbr.c \
		ft_strspn.c \
		ft_strlen.c \
		ft_intlen.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_intlen.c \
		ft_newstring.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_lstadd_front.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		get_next_line.c \
		ft_conv.c \
		ft_flags_m.c \
		ft_flags_z.c \
		ft_full_flags.c \
		ft_len.c \
		ft_parse.c \
		ft_precision.c \
		ft_print_char.c \
		ft_print_di.c \
		ft_print_s.c \
		ft_print_c.c \
		ft_print_maj_x.c \
		ft_print_p.c \
		ft_print_u.c \
		ft_print_x.c \
		ft_printf.c \
		ft_widths.c \
		ft_percent.c \
		ft_check_struct.c \
		ft_print_nbr.c \
		ft_s_wp.c \
		ft_s_lz_p.c \
		ft_s_w_p.c \
		ft_strcat.c \
		ft_strjoinfree_separate.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(SRCS) $(OBJS) $(HEADERS)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)
		@echo "\033[032mLibft : Object files Created\033[0m"
		@echo "\033[032mLibft : Libft.a Created\033[0m"

clean :
	@rm -f $(OBJS) $(LIST)
	@echo "\033[32mLibft : Object files Removed\033[0m"

fclean : clean
	@rm -f $(NAME) $(LIST)
	@echo "\033[32mLibft : Libft.a Removed\033[0m"

up : all clean

re : fclean all

.PHONY : all clean fclean re up
.SILENT : $(OBJS)
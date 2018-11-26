# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 22:17:06 by amelikia          #+#    #+#              #
#    Updated: 2018/11/01 14:43:53 by amelikia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
HEADER = libft.h

PRINTF_CFILES = ft_printf.c \
								src/ft_itoa_intmax.c \
								src/ft_itoa_base_unsigned.c \
								src/ft_itoa_unsigned.c \
								src/conversion_b_p.c \
								src/conversion_c_s.c \
								src/conversion_num.c \
								src/conversion_o_x.c \
								src/fn_struct.c \
								src/ftprintf_helper.c \
								src/minus_plus_space.c \
								src/parse_data.c \
								src/parse_format.c \
								src/parse_type.c \
								src/parse_w_and_a.c \
								src/precision.c \
								src/type_define.c \
								src/wide_s.c \
								src/width.c \

PRINTF_OFILES = ft_printf.o \
								ft_itoa_intmax.o \
								ft_itoa_base_unsigned.o \
								ft_itoa_unsigned.o \
								conversion_b_p.o \
								conversion_c_s.o \
								conversion_num.o \
								conversion_o_x.o \
								fn_struct.o\
								ftprintf_helper.o \
								minus_plus_space.o \
								parse_data.o \
								parse_format.o \
								parse_type.o \
								parse_w_and_a.o \
								precision.o \
								type_define.o \
								wide_s.o \
								width.o \

CFILES = ./ft_atoi.c \
		./ft_bzero.c \
		./ft_isalnum.c \
		./ft_isalpha.c \
		./ft_isascii.c \
		./ft_isdigit.c \
		./ft_isprint.c \
		./ft_itoa.c \
		./ft_memalloc.c \
		./ft_memccpy.c \
		./ft_memchr.c \
		./ft_memcmp.c \
		./ft_memcpy.c \
		./ft_memdel.c \
		./ft_memmove.c \
		./ft_memset.c \
		./ft_putchar.c \
		./ft_putchar_fd.c \
		./ft_putendl.c \
		./ft_putendl_fd.c \
		./ft_putnbr.c \
		./ft_putnbr_fd.c \
		./ft_putstr.c \
		./ft_putstr_fd.c \
		./ft_strcat.c \
		./ft_strchr.c \
		./ft_strclr.c \
		./ft_strcmp.c \
		./ft_strcpy.c \
		./ft_strdel.c \
		./ft_strdup.c \
		./ft_strequ.c \
		./ft_striter.c \
		./ft_striteri.c \
		./ft_strjoin.c \
		./ft_strlcat.c \
		./ft_strlen.c \
		./ft_strmap.c \
		./ft_strmapi.c \
		./ft_strncat.c \
		./ft_strncmp.c \
		./ft_strncpy.c \
		./ft_strnequ.c \
		./ft_strnew.c \
		./ft_strnstr.c \
		./ft_strrchr.c \
		./ft_strsplit.c \
		./ft_strstr.c \
		./ft_strsub.c \
		./ft_strtrim.c \
		./ft_tolower.c \
		./ft_toupper.c \
		./ft_lstadd.c \
		./ft_lstdel.c \
		./ft_lstdelone.c \
		./ft_lstiter.c \
		./ft_lstmap.c \
		./ft_lstnew.c \
		./ft_makestr.c \
		./ft_itoa_base.c \
		./ft_abs.c \
		./get_next_line.c \
		./b_printf.c \
		./ft_sizeofint.c \
		./ft_strccrt.c \
		./ft_update.c \
		./ft_strchrfill.c \
		./ft_bchar.c \
		./ft_strtoupper.c \

OFILES =   ./ft_atoi.o \
		./ft_bzero.o \
		./ft_isalnum.o \
		./ft_isalpha.o \
		./ft_isascii.o \
		./ft_isdigit.o \
		./ft_isprint.o \
		./ft_itoa.o \
		./ft_memalloc.o \
		./ft_memccpy.o \
		./ft_memchr.o \
		./ft_memcmp.o \
		./ft_memcpy.o\
		./ft_memdel.o \
		./ft_memmove.o \
		./ft_memset.o \
		./ft_putchar.o \
		./ft_putchar_fd.o \
		./ft_putendl.o \
		./ft_putendl_fd.o \
		./ft_putnbr.o \
		./ft_putnbr_fd.o \
		./ft_putstr.o \
		./ft_putstr_fd.o \
		./ft_strcat.o \
		./ft_strchr.o \
		./ft_strclr.o \
		./ft_strcmp.o \
		./ft_strcpy.o \
		./ft_strdel.o \
		./ft_strdup.o \
		./ft_strequ.o \
		./ft_striter.o \
		./ft_striteri.o \
		./ft_strjoin.o \
		./ft_strlcat.o \
		./ft_strlen.o \
		./ft_strmap.o \
		./ft_strmapi.o \
		./ft_strncat.o \
		./ft_strncmp.o \
		./ft_strncpy.o \
		./ft_strnequ.o \
		./ft_strnew.o \
		./ft_strnstr.o \
		./ft_strrchr.o \
		./ft_strsplit.o \
		./ft_strstr.o \
		./ft_strsub.o \
		./ft_strtrim.o \
		./ft_tolower.o \
		./ft_toupper.o \
		./ft_lstadd.o \
		./ft_lstdel.o \
		./ft_lstdelone.o \
		./ft_lstiter.o \
		./ft_lstmap.o \
		./ft_lstnew.o \
		./ft_makestr.o \
		./ft_itoa_base.o \
		./ft_abs.o \
		./get_next_line.o \
		./b_printf.o \
		./ft_sizeofint.o \
		./ft_strccrt.o \
		./ft_update.o \
		./ft_strchrfill.o \
		./ft_bchar.o \
		./ft_strtoupper.o \

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -I$(HEADER) -c $(CFILES) $(PRINTF_CFILES)
	ar rc $(NAME) $(OFILES) $(PRINTF_OFILES)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OFILES)
	/bin/rm -f $(PRINTF_OFILES)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

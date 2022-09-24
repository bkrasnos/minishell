# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nedebies <nedebies@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 09:54:51 by nedebies          #+#    #+#              #
#    Updated: 2022/06/21 19:55:01 by nedebies         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = libft.a

SRCS 	=	ft_atoi.c\
		ft_isalpha.c\
		ft_itoa.c\
		ft_memcpy.c\
		ft_strchr.c\
		ft_strlcpy.c\
		ft_strnstr.c\
		ft_tolower.c\
		ft_bzero.c\
		ft_isascii.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_strdup.c\
		ft_strlen.c\
		ft_strrchr.c\
		ft_toupper.c\
		ft_calloc.c\
		ft_isdigit.c\
		ft_memchr.c\
		ft_memset.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_isalnum.c\
		ft_isprint.c\
		ft_memcmp.c\
		ft_split.c\
		ft_strlcat.c\
		ft_strncmp.c\
		ft_substr.c\
		ft_strmapi.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_strcmp.c

BONUS		= ft_lstadd_back.c\
				  ft_lstadd_front.c\
				  ft_lstclear.c\
				  ft_lstdelone.c\
				  ft_lstiter.c\
				  ft_lstlast.c\
				  ft_lstnew.c\
				  ft_lstsize.c\
				  ft_lstmap.c\

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

OBJS	=	$(SRCS:.c=.o)

OBJS_B	=	$(BONUS:.c=.o)

ARRCS		=	ar rcs

RM		= rm -rf

.c.o:	$(SRCS)
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME): 	$(OBJS)
		$(ARRCS) $(NAME) $^

bonus: $(OBJS_B)
	$(ARRCS) $(NAME) $^

all:	 $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all



.PHONY:			all clean fclean re bonus

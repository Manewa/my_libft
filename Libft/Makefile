# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namalier <namalier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 19:37:32 by namalier          #+#    #+#              #
#    Updated: 2024/05/05 18:34:14 by namalier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GNLDIR		=	GNL
OBJDIR		=	objs

SRCS		=	ft_atoi.c ft_isascii.c ft_memchr.c ft_strchr.c ft_strlen.c \
				ft_bzero.c ft_isdigit.c ft_memcmp.c ft_strdup.c ft_calloc.c \
				ft_isprint.c ft_memcpy.c ft_strncmp.c ft_tolower.c \
				ft_isalnum.c ft_memmove.c ft_strlcat.c ft_strnstr.c \
				ft_toupper.c ft_isalpha.c ft_memset.c ft_strlcpy.c \
				ft_strrchr.c ft_strjoin.c ft_substr.c ft_strtrim.c ft_split.c \
				ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				$(GNLDIR)/get_next_line.c $(GNLDIR)/get_next_line_utils.c \

				

SRCS_BONUS	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c	ft_lstiter_bonus.c ft_lstmap_bonus.c \
				$(GNLDIR)/get_next_line_bonus.c ft_lstfree.c\
				$(GNLDIR)/get_next_line_utils_bonus.c \

OBJS		= $(patsubst %.c,$(OBJDIR)/%.o,$(notdir $(SRCS)))

OBJS_BONUS	= $(patsubst %.c,$(OBJDIR)/%.o,$(notdir $(SRCS_BONUS)))

NAME		= libft.a

CFLAGS		= -Wall -Werror -Wextra

${NAME}		:	$(OBJDIR) ${OBJS} $(OBJS_BONUS)
			ar rc ${NAME} ${OBJS} $(OBJS_BONUS)
			ranlib ${NAME}

$(OBJDIR)		:
	 			@mkdir -p $@

$(OBJDIR)/%.o	:	%.c
				cc $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o	:	$(GNLDIR)/%.c
				cc $(CFLAGS) -c $< -o $@

.c.o		:
			cc ${CFLAGS} -c $< -o ${<:.c=.o}
			
all			:	${NAME}

clean		:
			rm -rf ${OBJDIR}

fclean		:		clean
			rm -f ${NAME}

re			: fclean all

.PHONY		: all clean fclean re bonus

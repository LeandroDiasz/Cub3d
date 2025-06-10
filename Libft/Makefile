# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ledias-d <ledias-d@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/21 17:00:35 by ledias-d          #+#    #+#              #
#    Updated: 2024/10/02 14:22:34 by ledias-d         ###   ########.rio       #
#                                                                              #
# **************************************************************************** #

FUNC_NAMES = ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint\
			ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy\
			ft_strlcat ft_toupper ft_tolower ft_strchr ft_strrchr\
			ft_strncmp ft_memchr ft_memcmp ft_strnstr ft_atoi ft_calloc\
			ft_strdup ft_substr ft_strjoin ft_strtrim ft_strmapi ft_striteri\
			ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_itoa\
			ft_split

FUNC_NAMES_BONUS = ft_lstnew_bonus ft_lstadd_front_bonus ft_lstsize_bonus\
			ft_lstlast_bonus ft_lstadd_back_bonus ft_lstdelone_bonus\
			ft_lstclear_bonus ft_lstiter_bonus ft_lstmap_bonus

SRCS = $(addsuffix .c, $(FUNC_NAMES))
OBJS := $(SRCS:.c=.o)
BONUS_SRC = $(addsuffix .c, $(FUNC_NAMES_BONUS))
BONUS_OBJS := $(BONUS_SRC:%.c=%.o)

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
ARNAME = ar rcs $(NAME)
RANNAME = ranlib $(NAME)
OBJS_BASBO = $(OBJS) $(BONUS_OBJS)
OBJS_ALL = $(OBJS_BASBO) $(SUPP_OBJS)
TEST_SRC = $(SRCS)
TEST_EXEC = test
TEST_SRC_BONUS = $(BONUS_SRC)

all: $(NAME)

$(NAME): $(OBJS)
	$(ARNAME) $(OBJS)
	$(RANNAME)
%.o: %.c
	$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<

test: $(TEST_SRC)
	@$(CC) $(CFLAGS) -o $(TEST_EXEC) $(TEST_SRC)

testbonus: $(TEST_SRC_BONUS)
	@$(CC) $(CFLAGS) -o $(TEST_EXEC) $(TEST_SRC_BONUS) $(TEST_SRC)

clean:
	rm -f $(OBJS_ALL)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJS_BASBO)
	$(ARNAME) $(OBJS_BASBO)
	$(RANNAME)

.PHONY: clean

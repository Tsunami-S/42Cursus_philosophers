# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 11:08:47 by tssaito           #+#    #+#              #
#    Updated: 2025/04/02 18:27:26 by tssaito          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

# directories
SRCDIR = srcs
INCDIR = incs
OBJDIR = objs

# sources
SRCS = main.c \
	   isvalid_args.c init_data.c \
	   ft_utils.c ft_utils2.c

# objects
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

# flags
WFLAG = -Wall -Wextra -Werror
IFLAG = -I$(INCDIR)

# for test
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all -s
ARGS ?= 1 2 3 4 5

# rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(WFALG) $(OBJS) $(IFLAG) -o $(NAME)

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: all

test: $(OBJS)
	$(CC) $(WFALG) $(OBJS) $(IFLAG) -o $(NAME)
	valgrind $(VALGRIND_FLAGS) ./$(NAME) $(ARGS)

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(WFLAG) $(IFLAG) -c $< -o $@

.PHONY: all clean fclean re

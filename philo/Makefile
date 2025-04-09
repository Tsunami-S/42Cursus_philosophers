# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 11:08:47 by tssaito           #+#    #+#              #
#    Updated: 2025/04/09 00:48:50 by tssaito          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

# directories
INCDIR = incs
SRCDIR = srcs
UTILSDIR = ft_utils
OBJDIR = objs

# sources
SRCS = main.c \
	   validate.c init_philosopher.c \
	   routine.c actions.c manage_threads.c time_utils.c print.c \
	   exit_philosopher.c \
	   $(addprefix $(UTILSDIR)/, ft_atoi.c ft_isdigit.c ft_isspace.c \
	   ft_putstr_fd.c ft_putendl_fd.c ft_strlen.c \
	   ft_strjoin.c ft_strlcat.c ft_strlcpy.c)

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

$(OBJDIR)/%.o:$(UTILSDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(WFLAG) $(IFLAG) -c $< -o $@

.PHONY: all clean fclean re

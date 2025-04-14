# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tssaito <tssaito@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 11:08:47 by tssaito           #+#    #+#              #
#    Updated: 2025/04/11 23:40:15 by tssaito          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

# directories
INCDIR = incs
SRCDIR = srcs
UTILSDIR = ft_utils
OBJDIR = objs

# sources
SRCS = main_bonus.c \
	   validate.c init_philosopher.c \
	   manage_process.c actions.c time_utils.c \
	   exit_philosopher.c \
	   $(addprefix $(UTILSDIR)/, ft_atoi.c ft_isdigit.c ft_isspace.c \
	   ft_putstr_fd.c ft_putendl_fd.c ft_strlen.c \
	   ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_itoa.c)

# objects
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

# flags
WFLAG = -Wall -Wextra -Werror
IFLAG = -I$(INCDIR)

# rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(WFALG) $(OBJS) $(IFLAG) -o $(NAME)

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(WFLAG) $(IFLAG) -c $< -o $@

$(OBJDIR)/%.o:$(UTILSDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(WFLAG) $(IFLAG) -c $< -o $@

.PHONY: all clean fclean re

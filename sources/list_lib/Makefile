# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 22:11:12 by tgouedar          #+#    #+#              #
#    Updated: 2019/07/08 16:49:30 by tgouedar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

SRCFILE	= ft_listadd.c \
		  ft_listadd_back.c \
		  ft_lstfree.c \
		  ft_lstfreeone.c \
		  ft_lstnew.c \
		  ft_listlen.c \

SRCDIR	= ./
SRC		= $(addprefix $(SRCDIR),$(SRCFILE))

HDR_DIR	= ../../libft/includes\
		  ..\
		  .

HDR_FLAG= $(addprefix -I ,$(HDR_DIR))

OBJFILE	= $(SRCFILE:.c=.o)
OBJDIR	= obj
OBJ		= $(addprefix $(OBJDIR)/,$(OBJFILE))

NAME 	= list_lib.a

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "Your list_lib.a is ready"

$(OBJDIR)/%.o : %.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -o $@ -c $^ $(HDR_FLAG)
	@echo " \t \t \t \t \t \t \t \t [OK]  \r $^  \r "


$(OBJDIR) :
	@/bin/mkdir -p $(OBJDIR)

clean :
	@/bin/rm $(OBJ) 2>/dev/null || true
	@/bin/rm -R $(OBJDIR) 2>/dev/null || true

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all

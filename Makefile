# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baavril <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 10:37:50 by baavril           #+#    #+#              #
#    Updated: 2019/04/15 14:03:04 by tgouedar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-g3 -Wall -Werror -Wextra

NAME		=	Minishell

LIB_PATH	=	libft
LIB			=	libft.a

LIBS 		=	$(LIB_PATH)/$(LIB)

DIR_O		=   obj

SRC_PATH	=	sources
SOURCES 	=	Minishell.c

SRCS    	=   $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS    	=   $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

HDR_PATH	=	.
HEADERS		=	
HDR	    	=   $(addprefix $(HDR_PATH)/,$(HEADERS))

RM			=   rm -f

CLEAN		=   clean

all     	:   $(NAME)

$(LIB)  	:
	@make -C $(LIB_PATH)

$(NAME) 	: $(LIB) $(OBJS) Makefile
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(NAME) has been successfully created."

$(DIR_O)/%.o: $(SRC_PATH)/%.c | $(DIR_O)
	@$(CC) $(CFLAGS) -I $(HDR_PATH) -o $@ -c $<

$(DIR_O)	:
	@mkdir -p $(DIR_O)	

clean   	:
	@$(RM) $(OBJS)
	@rm -Rf $(DIR_O)
	@make clean -C $(LIB_PATH)
	@echo "All .o files have been deleted."

fclean  	:   clean
	@$(RM) $(NAME)
	@make fclean -C $(LIB_PATH)
	@echo "$(NAME) exectutable and libft.a have been deleted."

re      	:   fclean all

.PHONY: all clean fclean re

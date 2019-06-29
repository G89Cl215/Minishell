# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baavril <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 10:37:50 by baavril           #+#    #+#              #
#    Updated: 2019/06/29 17:50:42 by tgouedar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-g3 -Wall -Werror -Wextra

NAME		=	Minishell

LIB_PATH	=	libft
LIB			=	libft.a

LISTLIB_PATH=	sources/list_lib/
LISTLIB		=	list_lib.a

LIBS 		=	$(LIB_PATH)/$(LIB) \
				$(LISTLIB_PATH)/$(LISTLIB)

DIR_O		=   obj

SRC_PATH	=	sources
SOURCES 	=	Minishell.c \
				gestion_de_crise.c \
				env_tools.c \
				ft_init_env.c \
				ft_find_exec.c \
				ft_find_exec_path.c \
				ft_built_in.c \
				ft_built_in_cd.c \
				ft_built_in_env.c \
				parsing_command.c \
				parsing_tokenizing.c \
				parsing_expanding.c \

SRCS    	=   $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS    	=   $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))


HEADERS		=	includes/minishell.h \
				includes/dispatcher.h \
				includes/env.h \

HDR_PATH	=	includes \
				libft/includes \
				sources/list_lib/

HDR_FLAG   	=   $(addprefix -I ,$(HDR_PATH))

RM			=   rm -f

CLEAN		=   clean

all     	:	libs 
	@($(MAKE) $(NAME))

libs  	:
	@cd $(LIB_PATH) && (($(MAKE) -q && echo "Your LIBFT is up to date") || $(MAKE))
	@cd $(LISTLIB_PATH) && (($(MAKE) -q && echo "Your LISTLIB is up to date") || $(MAKE))

$(NAME) 	:	$(OBJS) Makefile
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HDR_FLAG) -o $@
	@echo "$@ has been successfully created."

$(DIR_O)/%.o: $(SRC_PATH)/%.c $(HEADERS) | $(DIR_O)
	@$(CC) $(CFLAGS) $(HDR_FLAG) -o $@ -c $<

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

.PHONY: all libs clean fclean re

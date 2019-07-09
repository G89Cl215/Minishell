# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 22:11:12 by tgouedar          #+#    #+#              #
#    Updated: 2019/07/08 16:35:56 by tgouedar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCFILE			= ft_swap.c\
				  ft_btw.c\
				  ft_bzero.c\
				  ft_memset.c\
				  ft_memcpy.c\
				  ft_memccpy.c\
				  ft_memmove.c\
				  ft_memchr.c\
				  ft_memcmp.c\
				  ft_strlen.c\
				  ft_strdup.c\
				  ft_strndup.c\
				  ft_strcpy.c\
				  ft_strncpy.c\
				  ft_strcat.c\
				  ft_strncat.c\
				  ft_strlcat.c\
				  ft_strchr.c\
				  ft_strrchr.c\
				  ft_strstr.c\
				  ft_strnstr.c\
				  ft_strspn.c\
				  ft_strcspn.c\
				  ft_strcmp.c\
				  ft_strncmp.c\
				  ft_atoi.c\
				  ft_unsigned_itoa_base.c\
				  ft_itoa.c\
				  ft_pow.c\
				  ft_isalpha.c\
				  ft_islower.c\
				  ft_isdigit.c\
				  ft_isalnum.c\
				  ft_isascii.c\
				  ft_isprint.c\
				  ft_isin.c\
				  ft_indice.c\
				  ft_toupper.c\
				  ft_tolower.c\
				  ft_memalloc.c\
				  ft_memdel.c\
				  ft_strnew.c\
				  ft_strdel.c\
				  ft_strclr.c\
				  ft_striter.c\
				  ft_strisnum.c\
				  ft_striteri.c\
				  ft_strmap.c\
				  ft_strmapi.c\
				  ft_strequ.c\
				  ft_strnequ.c\
				  ft_strsub.c\
				  ft_strjoin.c\
				  ft_strappend.c\
				  ft_strprefix.c\
				  ft_strtrim.c\
				  ft_strrev.c\
				  ft_strupper.c\
				  ft_tablen.c\
				  ft_tabcpy.c\
				  ft_tabfree.c\
				  ft_strsplit.c\
				  ft_strsplitnextword.c\
				  ft_putchar.c\
				  ft_putchar_fd.c\
				  ft_putstr.c\
				  ft_putstr_fd.c\
				  ft_putlpadstr.c\
				  ft_putrpadstr.c\
				  ft_putendl.c\
				  ft_print_nods.c\
				  ft_putendl_fd.c\
				  ft_putnbr.c\
				  ft_putnbr_fd.c\
				  ft_putnbr_base.c\
				  ft_lstadd.c\
				  ft_lstdel.c\
				  ft_lstdelone.c\
				  ft_lstfree.c\
				  ft_lstfreeone.c\
				  ft_lstnew.c\
				  ft_lstmap.c\
				  ft_lstiter.c\
				  ft_integer_len.c\
				  ft_lstadd_back.c\
				  get_next_line.c\
				  option.c\
				  match.c

SRC_DIR			= sources

HDR_DIR			= includes

OBJ_DIR			= obj
OBJ				= $(addprefix $(OBJ_DIR)/,$(SRCFILE:.c=.o))

NAME			=	libft.a

PRINTF_PATH		=	printf
PRINTFLIB		=	$(PRINTF_PATH)/libprintf.a

CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
CFLAGS			+=	$(addprefix -I ,$(HDR_DIR))	

LS				=	ls

.PHONY: all re clean fclean ls

all				: $(NAME)

$(NAME)			: $(OBJ) $(PRINTFLIB) Makefile
	@cp $(PRINTFLIB) ./$(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib	$(NAME)
	@echo "Your LIBFT is ready for use."

$(PRINTFLIB)	:
	@make -C $(PRINTF_PATH)

$(OBJ)			: $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $(OBJ_DIR)/$*.o -c $<
	@echo "\t\t\t\t\t\t\t\t[OK]\r\t$*"

$(OBJ_DIR)		:
	@/bin/mkdir -p $(OBJ_DIR)

ls				: $(NAME)
	@make -C $(LS)

clean			:
	@make clean -C $(PRINTF_PATH)
	@make clean -C $(LS)
	@/bin/rm -Rf $(OBJ_DIR) 2>/dev/null || true

fclean			: clean
	@make fclean -C $(PRINTF_PATH)
	@make fclean -C $(LS)
	@/bin/rm -f $(NAME)

re				: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/21 16:02:22 by tsilberm          #+#    #+#              #
#    Updated: 2016/01/22 17:15:23 by tsilberm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc
NAME			=	fillit
FLAGS			=	-Wall -Wextra -Werror

LIB_PATH		=	libft
LIB				=	$(LIB_PATH)/libft.a
LIB_LINK		=	-L $(LIB_PATH) -lft

INC_DIR			=	includes
INCS			=	-I $(LIB_PATH)/$(INC_DIR) -I $(INC_DIR)

SRC_DIR			=	srcs
SRC_BASE		=	main.c			\
					pattern.c		\
					parse.c			\
					parse_utils.c	\
					binary.c		\
					solve.c			\
					print.c			\
					dz.c			\
					error.c			\
					utils.c

OBJ_DIR			=	obj

SRCS			=	$(addprefix $(SRC_DIR)/, $(SRC_BASE))
OBJS			=	$(addprefix $(OBJ_DIR)/, $(SRC_BASE:.c=.o))

# COLORS
C_NO			=	"\033[00m"
C_OK			=	"\033[36m"
C_GOOD			=	"\033[32m"
C_ERROR			=	"\033[31m"
C_WARN			=	"\033[33m"

# DBG MESSAGE
SUCCESS			=	$(C_GOOD)SUCCESS$(C_NO)
OK				=	$(C_OK)OK$(C_NO)

all: obj $(NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(FLAGS) -o $@ $^ $(LIB_LINK)
	@echo "Compile" [ $(NAME) ] $(SUCCESS)

$(LIB):
	@make -C $(LIB_PATH)

obj:
	@mkdir -p obj

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/*.h
	@$(CC) $(FLAGS) $(INCS) -c -o $@ $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo "Clean" [ $(NAME) ] "..." $(OK)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo "Delete" [ $(NAME) ] $(OK)

re: fclean all

.PHONY: clean all re fclean

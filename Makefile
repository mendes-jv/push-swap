# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 11:17:20 by jovicto2          #+#    #+#              #
#    Updated: 2023/12/07 11:17:23 by jovicto2         ###   ########.org.br    #
#                                                                              #
# **************************************************************************** #

# Variables
NAME				:= push_swap
CHECKER				:= checker

SOURCES_DIR			:= sources/
OBJECTS_DIR			:= objects/push_swap/
CHECKER_OBJECTS_DIR	:= objects/checker/
HEADERS_DIR			:= includes/
LIBRARIES_DIR		:= libraries/
LIBFT_DIR			:= $(addprefix $(LIBRARIES_DIR), libft/)
LIBFT_FILE 			:= libft.a

MAKE				:= make
MAKE_LIBS			:= $(MAKE) -sC
CC					:= cc
CFLAGS				:= -Wall -Wextra -Werror -Wunreachable-code -Ofast -g3 -O3
MKDIR				:= mkdir -p
RM					:= rm -rf

# Sources
FILES				:= apply_move check_args_list push_swap small_stack_sort sort_stack stack_movements
CHECKER_FILES		:= apply_move check_args_list checker small_stack_sort sort_stack stack_movements
SOURCES				:= $(addprefix $(SOURCES_DIR), $(addsuffix .c, $(FILES)))
OBJECTS				:= $(addprefix $(OBJECTS_DIR), $(addsuffix .o, $(FILES)))
CHECKER_SOURCES		:= $(addprefix $(SOURCES_DIR), $(addsuffix .c, $(CHECKER_FILES)))
CHECKER_OBJECTS		:= $(addprefix $(OBJECTS_DIR), $(addsuffix .o, $(CHECKER_FILES)))
LIBFT				:= $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))
LIBFT_HEADER		:= $(addprefix $(LIBFT_DIR), includes/libft.h)
HEADERS				:= -I $(HEADERS_DIR)

# Colors
RED   				:= \033[0;31m
GREEN  				:= \033[0;32m
RESET  		 		:= \033[0m

# Rules
.PHONY: all clean fclean re

all:
	@$(MAKE) -s libraries
	@if [ ! -f $(NAME) ]; then \
		$(MAKE) -s $(NAME); \
		if [ -f $(NAME) ]; then \
    		printf "$(GREEN)Compiled $(NAME) successfully!$(RESET)\n"; \
    	else \
    		printf "$(RED)$(NAME) is not compiled yet!$(RESET)\n"; \
		fi \
    else \
    	printf "$(RED)$(NAME) is already compiled!$(RESET)\n"; \
    fi

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME) $(INCLUDES);

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.c
	@$(MKDIR) $(OBJECTS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

cleanlibft:
	@$(MAKE_LIBS) $(LIBFT_DIR) clean

fcleanlibft:
	@$(MAKE_LIBS) $(LIBFT_DIR) fclean

clean:
	@if [ -f $(NAME) ]; then \
		$(MAKE) -s cleanlibft; \
	else \
		printf "$(RED)$(LIBFT_FILE) is not compiled yet!$(RESET)\n"; \
	fi
	@if [ -d $(OBJECTS_DIR) ]; then \
		$(RM) $(OBJECTS_DIR); \
		printf "$(GREEN)Cleaned objects from $(NAME) successfully!$(RESET)\n"; \
	else \
		printf "$(RED)Objects from $(NAME) are already cleaned!$(RESET)\n"; \
	fi

fclean: clean fcleanlibft
	@if [ -f $(NAME) ]; then \
		$(RM) $(NAME); \
		printf "$(GREEN)Removed $(NAME) file successfully!$(RESET)\n"; \
	else \
		printf "$(RED)File $(NAME) is already removed!$(RESET)\n"; \
	fi

re: fclean
	@$(MAKE) -s

bonus:
	@$(MAKE) -s libraries
	@if [ ! -f $(CHECKER) ]; then \
		$(MAKE) -s $(CHECKER); \
		if [ -f $(CHECKER) ]; then \
    		printf "$(GREEN)Compiled $(CHECKER) successfully!$(RESET)\n"; \
    	else \
    		printf "$(RED)$(CHECKER) is not compiled yet!$(RESET)\n"; \
		fi \
    else \
    	printf "$(RED)$(CHECKER) is already compiled!$(RESET)\n"; \
    fi

$(CHECKER): $(CHECKER_OBJECTS)
	@$(CC) $(CFLAGS) $(CHECKER_OBJECTS) $(LIBFT) -o $(CHECKER) $(INCLUDES);

$(CHECKER_OBJECTS_DIR)%.o: $(SOURCES_DIR)%.c
	@$(MKDIR) $(CHECKER_OBJECTS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

programs: all bonus

libraries: $(LIBFT)

$(LIBFT):
	@$(MAKE_LIBS) $(LIBFT_DIR)

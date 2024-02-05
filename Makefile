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
NAME					:= push_swap
CHECKER					:= checker

SOURCES_DIR				:= sources/
SHARED_DIR				:= $(SOURCES_DIR)shared/
PUSH_SWAP_DIR			:= $(SOURCES_DIR)push_swap/
CHECKER_DIR				:= $(SOURCES_DIR)checker/
OBJECTS_DIR				:= objects/
SHARE_OBJECTS_DIR		:= $(OBJECTS_DIR)shared/
PUSH_SWAP_OBJECTS_DIR	:= $(OBJECTS_DIR)push_swap/
CHECKER_OBJECTS_DIR		:= $(OBJECTS_DIR)checker/
HEADERS_DIR				:= includes/
LIBRARIES_DIR			:= libraries/
LIBFT_DIR				:= $(addprefix $(LIBRARIES_DIR), libft/)
LIBFT_FILE 				:= libft.a

MAKE					:= make
MAKE_LIBS				:= $(MAKE) -sC
CC						:= cc
CFLAGS					:= -Wall -Wextra -Werror -Wunreachable-code -Ofast -g3 -O3
MKDIR					:= mkdir -p
RM						:= rm -rf

# Sources
SHARED_FILES			:= check_args_list handle_stacks stack_movements
PUSH_SWAP_FILES			:= apply_move push_swap sort_stack
CHECKER_FILES			:= checker read_moves
SHARED_SOURCES			:= $(addprefix $(SHARED_DIR), $(addsuffix .c, $(SHARED_FILES)))
PUSH_SWAP_SOURCES		:= $(addprefix $(PUSH_SWAP_DIR), $(addsuffix .c, $(PUSH_SWAP_FILES)))
CHECKER_SOURCES			:= $(addprefix $(CHECKER_DIR), $(addsuffix .c, $(CHECKER_FILES)))
SOURCES					:= $(SHARED_SOURCES) $(PUSH_SWAP_SOURCES)
BONUS_SOURCES			:= $(SHARED_SOURCES) $(CHECKER_SOURCES)
SHARED_OBJECTS			:= $(addprefix $(SHARE_OBJECTS_DIR), $(addsuffix .o, $(SHARED_FILES)))
PUSH_SWAP_OBJECTS		:= $(addprefix $(PUSH_SWAP_OBJECTS_DIR), $(addsuffix .o, $(PUSH_SWAP_FILES)))
CHECKER_OBJECTS			:= $(addprefix $(CHECKER_OBJECTS_DIR), $(addsuffix .o, $(CHECKER_FILES)))
OBJECTS					:= $(SHARED_OBJECTS) $(PUSH_SWAP_OBJECTS)
BONUS_OBJECTS			:= $(SHARED_OBJECTS) $(CHECKER_OBJECTS)
LIBFT					:= $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))
LIBFT_HEADER			:= $(addprefix $(LIBFT_DIR), includes/libft.h)
HEADERS					:= -I $(HEADERS_DIR)

# Colors
RED   					:= \033[0;31m
GREEN  					:= \033[0;32m
RESET  		 			:= \033[0m

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

$(NAME): $(OBJECTS) $(PUSH_SWAP_OBJECTS)
	@$(CC) $(CFLAGS) $^ $(LIBFT) -o $(NAME) $(INCLUDES);

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
	@if [ -f $(CHECKER) ]; then \
		$(MAKE) -s cleanlibft; \
	else \
		printf "$(RED)$(LIBFT_FILE) is not compiled yet!$(RESET)\n"; \
	fi
	@if [ -d $(CHECKER_OBJECTS_DIR) ]; then \
		$(RM) $(CHECKER_OBJECTS_DIR); \
		printf "$(GREEN)Cleaned objects from $(CHECKER) successfully!$(RESET)\n"; \
	else \
		printf "$(RED)Objects from $(CHECKER) are already cleaned!$(RESET)\n"; \
	fi

fclean: clean fcleanlibft
	@if [ -f $(NAME) ]; then \
		$(RM) $(NAME); \
		printf "$(GREEN)Removed $(NAME) file successfully!$(RESET)\n"; \
	else \
		printf "$(RED)File $(NAME) is already removed!$(RESET)\n"; \
	fi
	@if [ -f $(CHECKER) ]; then \
		$(RM) $(CHECKER); \
		printf "$(GREEN)Removed $(CHECKER) file successfully!$(RESET)\n"; \
	else \
		printf "$(RED)File $(CHECKER) is already removed!$(RESET)\n"; \
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

$(CHECKER): $(BONUS_OBJECTS) $(CHECKER_OBJECTS)
	@$(CC) $(CFLAGS) $^ $(LIBFT) -o $(CHECKER) $(INCLUDES);

$(SHARED_OBJECTS): $(SHARE_OBJECTS_DIR)%.o: $(SHARED_DIR)%.c
	@$(MKDIR) $(OBJECTS_DIR) $(SHARE_OBJECTS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(PUSH_SWAP_OBJECTS): $(PUSH_SWAP_OBJECTS_DIR)%.o: $(PUSH_SWAP_DIR)%.c
	@$(MKDIR) $(OBJECTS_DIR) $(PUSH_SWAP_OBJECTS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(CHECKER_OBJECTS): $(CHECKER_OBJECTS_DIR)%.o: $(CHECKER_DIR)%.c
	@$(MKDIR) $(OBJECTS_DIR) $(CHECKER_OBJECTS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
programs: all bonus

libraries: $(LIBFT)

$(LIBFT):
	@$(MAKE_LIBS) $(LIBFT_DIR)

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

SOURCES_DIR			:= sources/
OBJECTS_DIR			:= objects/
HEADERS_DIR			:= includes/
LIBRARIES_DIR		:= libraries/
LIBFT_DIR			:= $(addprefix $(LIBRARIES_DIR), libft/)
LIBFT_FILE 			:= libft.a

MAKE				:= make
MAKE_LIBS			:= $(MAKE) -sC
CC					:= cc
CFLAGS				:= -Wall -Wextra -Werror
MKDIR				:= mkdir -p
RM					:= rm -rf

# Sources

SOURCE_FILES		:= push_swap

CLIENT_SOURCES		:= $(addprefix $(SOURCES_DIR), $(addsuffix .c, $(CLIENT_FILES)))
SERVER_SOURCES		:= $(addprefix $(SOURCES_DIR), $(addsuffix .c, $(SERVER_FILES)))
CLIENT_OBJECTS		:= $(addprefix $(OBJECTS_DIR), $(addsuffix .o, $(CLIENT_FILES)))
SERVER_OBJECTS		:= $(addprefix $(OBJECTS_DIR), $(addsuffix .o, $(SERVER_FILES)))
LIBFT				:= $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))

LIBFT_HEADER		:= $(addprefix $(LIBFT_DIR), includes/libft.h)
HEADERS				:= -I $(HEADERS_DIR)

# colors
GREEN  				:= \033[0;32m
RESET  		 		:= \033[0m

# Rules

.PHONY: all clean fclean re

all: libraries programs
	if [ -f $(NAME) ] then \
		@printf "$(GREEN)Compiled $(NAME) successfully!$(RESET)\n"
	else
		@printf "$(GREEN)$(NAME) is already compiled!$(RESET)\n"
	fi

libraries: $(LIBFT)

programs: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME) $(INCLUDES)

$(LIBFT):
	@$(MAKE_LIBS) $(LIBFT_DIR)

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.c
	@$(MKDIR) $(OBJECTS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

cleanlibft:
	@$(MAKE_LIBS) $(LIBFT_DIR) fclean

clean: cleanlibft
	if [ -d $(OBJECTS_DIR) ] then \
		@$(RM) $(OBJECTS_DIR)
		@printf "$(GREEN)Cleaned objects from $(NAME) successfully!$(RESET)\n"
	else
		@printf "$(GREEN)$(NAME) objects are already cleaned!$(RESET)\n"
	fi

fclean: clean
	if [ -f $(NAME) ] then \
		@$(RM) $(NAME)
		@printf "$(GREEN)Cleaned $(CLIENT_NAME) and $(SERVER_NAME) successfully!$(RESET)\n"
	else
		@printf "$(GREEN)File $(NAME) is already cleaned!$(RESET)\n"
	fi

re: fclean
	@$(MAKE) -s

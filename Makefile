# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgales <bgales@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/10 12:55:07 by bgales            #+#    #+#              #
#    Updated: 2023/06/27 14:01:48 by bgales           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      ?=  cub3D

CC        =   gcc -Wall -Wextra -Werror
debug     ?=  -g -fsanitize=address
AR        ?=  ar
RM        ?=  rm -f
MKDIR     ?=  mkdir -p
ECHO      ?=  echo

RWILDCARD =   $(foreach d,\
              $(wildcard $(1:=/*)),\
              $(call RWILDCARD,$d,$2) $(filter $(subst *,%,$2),$d))

# ********************************* F O N T S *********************************

EOC       :=  "\033[0m"
LIGHT     :=  "\033[1m"
DARK      :=  "\033[2m"

ITALIC    :=  "\033[3m"
UNDERLINE :=  "\033[4m"

BLACK     :=  "\033[30m"
RED       :=  "\033[31m"
GREEN     :=  "\033[32m"
BLUE      :=  "\033[34m"
PURPLE    :=  "\033[35m"
CYAN      :=  "\033[36m"
WHITE     :=  "\033[37m"

# ********************************* P A T H S *********************************

SRCS_PATH :=  src
OBJS_PATH :=  bin
HDRS_PATH :=  include
LIBS_PATH :=  lib

LIBFT_PATH := $(LIBS_PATH)/libft

# ********************************* N A M E S *********************************

SRCS := $(filter-out src/game/raytracing_bonus.c,$(call RWILDCARD,$(SRCS_PATH),*.c))
SRCS_BONUS := $(filter-out src/game/raytracing.c,$(call RWILDCARD,$(SRCS_PATH),*.c))
OBJS := $(addprefix $(OBJS_PATH)/, $(SRCS:$(SRCS_PATH)/%.c=%.o))
OBJS_BONUS := $(addprefix $(OBJS_PATH)/, $(SRCS_BONUS:$(SRCS_PATH)/%.c=%.o))

# ********************************* H E A D S *********************************

HFLAGS := -I $(HDRS_PATH) -I $(LIBFT_PATH)/$(HDRS_PATH)

# ********************************** L I B S **********************************

# Libft
FTFLAGS := -L./$(LIBFT_PATH)

LFLAGS := $(FTFLAGS) -lft -lmlx -framework OpenGL -framework AppKit

# ********************************* N O R M E *********************************

NRM := norminette
NFLAGS ?= -R CheckForbiddenSourceHeader

# ********************************* R U L E S *********************************

ifeq ($(MAKECMDGOALS),bonus)
NO_LINK := 1
endif

ifeq ($(NO_LINK),1)
$(NAME): $(OBJS_BONUS)
	@$(CC) $^ $(FTFLAGS) $(LFLAGS) -o $(NAME)
	@$(ECHO) $(CYAN)$(UNDERLINE)"$@"$(EOC)": "$(GREEN)"complete"$(EOC)
else
$(NAME): $(OBJS)
	@$(CC) $^ $(FTFLAGS) $(LFLAGS) -o $(NAME)
	@$(ECHO) $(CYAN)$(UNDERLINE)"$@"$(EOC)": "$(GREEN)"complete"$(EOC)
endif

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c $(HDRS_PATH)
	@$(MKDIR) $(dir $@)
	@$(ECHO) $(WHITE)$(DARK)"Compiling $<"$(EOC)
	@$(CC) $(HFLAGS) -o $@ -c $<

all: $(NAME)

bonus:
	@$(MAKE) NO_LINK=1 $(NAME)

clean:
	@$(RM) -r $(OBJS_PATH)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

norme:
	@$(NRM) $(NFLAGS) $(SRCS_PATH)/*.c $(HDRS_PATH)/*.h

lib:				libft mlx
					mlx mlx_clean mlx_re
					mlx mlx_clean mlx_re

libft:
					@$(MAKE) -C ./$(LIBFT_PATH)

libft_clean:
					@$(MAKE) -C ./$(LIBFT_PATH) clean

libft_fclean:
					@$(MAKE) -C ./$(LIBFT_PATH) fclean

libft_re:
					@$(MAKE) -C ./$(LIBFT_PATH) re
					
.PHONY: all bonus clean fclean re norme
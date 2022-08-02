# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 09:21:47 by tlafont           #+#    #+#              #
#    Updated: 2022/08/02 20:37:06 by tlafont          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================================================================
#---------------------------- progress indicator --------------------------------

ifndef PERC
BASENAME	= `basename $(PWD)`
CR			= "\r"$(CLEAR)
CLEAR		= "\\033[0K"

HIT_TOTAL != ${MAKE} ${MAKECMDGOALS} --dry-run PERC="HIT_MARK" | grep -c "HIT_MARK"
HIT_COUNT = $(eval HIT_N != expr ${HIT_N} + 1)${HIT_N}
PERC = `expr ${HIT_COUNT} '*' 100 / ${HIT_TOTAL}`
endif

# ================================================================================
#---------------------------------- Colors ---------------------------------------

EOC:="\033[0;0m"
CLIC:="\033[01;05m"
GREEN:="\033[1;32m"
WHITE:="\033[1;37m"
FRED:="\033[01;41m"
FBLUE:="\033[01;44m"

# ================================================================================
#---------------------------------- General --------------------------------------

NAME	= event_mk

# ================================================================================
#--------------------------------- GNU compiler ----------------------------------

CC		= gcc -g

CFLAGS	= -Wall -Wextra -Werror

MLX	= -Lmlx/ -lmlx -L/usr/lib -lXext -lX11 -lm -lz

# ================================================================================
#------------------------------- System Commands ---------------------------------

RM			= rm

RD			= -rf

RF			= -f

SIL			= --no-print-directory

#================================================================================
#---------------------------------- Files Source ---------------------------------

SRC	=	main.c \
		ft_end_prog.c \
		ft_init_prog.c \
		ft_open_img.c \
		ft_open_img_next.c \
		ft_print_variables.c \
		ft_update.c \
		ft_print_variables_next.c \
		ft_print_variables_ter.c \
		ft_update_next.c \
		ft_update_ter.c

# ================================================================================
#------------------------------- Directory source ----------------------------------

SRCDIR	= src/
DINC	= inc/
DLIB	= libft/
DMLX	= mlx/

# ================================================================================
#------------------------------- Auto Directory ----------------------------------

OBJS = $(addprefix $(SRCDIR), $(SRC:.c=.o))

# ================================================================================
#------------------------------------- Rules -------------------------------------

$(NAME):	$(OBJS)
			@clear
			@$(MAKE) $(SIL) -C $(DLIB)
			@$(MAKE) $(SIL) -C $(DMLX)
			@$(CC) -o $(NAME) $(OBJS) -L$(DLIB) -lft $(MLX)
			@printf $(CR)$(GREEN)$(CLIC)"successfully created program !\n"$(EOC)$(CLEAR) $@

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $@
			@printf $(CR)"[ \e[32m$(PERC)\e[39m/100] $(BASENAME)/%s"$(CLEAR) $@

all:		$(NAME)


clean:
			clear
			@$(MAKE) $(SIL) -C $(DLIB) clean
			@$(RM) $(RF) $(OBJS)
			@printf $(CR)$(FBLUE)"event_mk files.o deleted !\n"$(EOC)$(CLEAR) $@

fclean:
			clear
			@$(MAKE) $(SIL) -C $(DLIB) fclean
			@$(MAKE) $(SIL) -C $(DMLX) clean
			@$(RM) $(RF) $(OBJS)
			@$(RM) $(RF) $(NAME)
			@$(RM) $(RF) $(NAMEB)
			@printf $(CR)$(FRED)"all binaries deleted !\n"$(EOC)$(CLEAR) $@

re:
			clear
			@$(MAKE) $(SIL) -C $(DLIB) fclean
			@$(MAKE) $(SIL) -C $(DMLX) clean
			@$(RM) $(RF) $(OBJS)
			@$(RM) $(RF) $(NAME)
			@printf $(CR)$(FRED)"all binaries deleted !\n"$(EOC)$(CLEAR) $@
			@$(MAKE) --no-print-directory

.PHONY:	all bonus clean fclean re

#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/01 15:00:00 by esaminad          #+#    #+#              #
#    Updated: 2015/07/01 15:00:00 by esaminad         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

##################################################
################## MAIN DEFINES ##################
##################################################
#PROGRAM NAME
NAME	=   philo

#LIST OF SRC FILES
SRC	=   src/env.c\
	    src/exit.c\
	    src/main.c\
		src/philosopher.c\
	    src/thread.c\
	    src/timer.c\
	    src/key_mgr.c

SRC_MLX	=   src/mlx/close.c\
	    src/mlx/color.c\
	    src/mlx/display.c\
	    src/mlx/hook.c\
	    src/mlx/img.c\
	    src/mlx/init.c\
	    src/mlx/keybind.c\
	    src/mlx/pixel.c\
	    src/mlx/sprite.c

SRC_SDL =	src/sdl/core.c\
			src/sdl/img.c\
			src/sdl/philo.c

##################################################
#################DEFINE SOME SHIT#################
##################################################
#GET .o FILES FROM SRC FILES
OBJ	= $(SRC:.c=.o) $(SRC_SDL:.c=.o)

#COMPILATOR C
CC	= clang
CFLAGS	= -Wall -Werror -Wextra -Ofast
FWORK	= -framework Cocoa

#LIBRARIES TO USE
LIB	= -lpthread -ldlst

#DIR TO INCLUDE
INC	= -I /usr/X11/include/X11

#ADDITIONAL CUSTOM LIBS & includes
ALIB	= -L libstd/ -lft \

AINC	=   -I libstd/includes \
	    -I include/

#SDL RELATED
SDL-DIR  = $(HOME)/.brew/Cellar/sdl/1.2.15
SDL-LINK = -L $(SDL-DIR)/lib -lSDLmain -lSDL
SDL-FINC = -include $(HOME)/.brew/Cellar/sdl/1.2.15/include/SDL/SDL.h

##################################################
################COMPILE THAT SHIT#################
##################################################
.PHONY: all clean fclean re mklib cllib fcllib

all: $(NAME)

#this compile every .c in a .o
#in the command, $@ = %.o, $< = %.c
%.o: %.c
	@printf "\033[1;36mCompile \e[33m%-41s\e[0m" "$<"
	@$(CC) $(CFLAGS) -c -o $@ $^ $(INC) $(AINC) $(SDL-FINC)
	@printf "\033[1;32m[✔]\033[0m\n"

#$(NAME) call for the compilation of every .o first by calling the .o list $(OBJ)
#after that, use the .o to make the final product
$(NAME): mklib $(OBJ)
	@echo "\033[0;32m> Building project\033[0m"
	@$(CC) $(CFLAGS) $(FWORK) $(OBJ) $(INC) $(LIB) $(AINC) $(ALIB) $(SDL-LINK) -o $(NAME)  $(SDL-FINC)
	@echo "\033[0;32m> Done.\033[0m"

#------------------------------------------------
#	             CLEANING
#------------------------------------------------
#Cleaning up, remove the .o
clean: cllib
	@echo "\033[1;33m-------- Cleaning philosopher ---------\033[0m"
	@echo "\033[1;31m> Cleaning object files\033[0m"
	@rm -f $(OBJ)
	@echo "\033[0;32m> Done.\033[0m"

#Event moar cleaning up, remove the .o & the final product
#could call clean but less text this way
fclean: fcllib
	@echo "\033[1;33m-------- Cleaning philosopher ---------\033[0m"
	@echo "\033[1;31m> Cleaning object files\033[0m"
	@rm -f $(OBJ)
	@echo "\033[1;31m> Cleaning executable\033[0m"
	@rm -f $(NAME)
	@echo "\033[0;32m> Done.\033[0m"

#------------------------------------------------
#	             LIBRARIES
#------------------------------------------------
mklib:
	@echo $(SDL-INCDEF)
	@echo "\033[0;35m[1]> Making libs.\033[0m"
	@make -C libstd/

cllib:
	@echo "\033[1;31m> Cleaning libs\033[0m"
	@make -C libstd/ clean

fcllib:
	@echo "\033[1;31m> Fclean libs\033[0m"
	@make -C libstd/ fclean

re: fclean all

.PHONY: all clean fclean re mklib cllib fcllib

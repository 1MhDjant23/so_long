NAME	= so_long

BONUS	= so_long_bonus

CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code

LIBMLX	= ~/Desktop/MLX42

CC		= cc

L_HEADER = libft.h

HEADER = so_long.h

B_HEADER = bonus/so_long_bonus.h

LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS	= map_cheking.c so_long_utils.c so_long.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c\
		layout_win.c move.c	utils2.c logo_exit.c

BNS_SRC	= bonus/so_long_bonus.c bonus/parsing.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c bonus/utils.c\
		bonus/utils_free.c bonus/init_window.c bonus/move_player.c bonus/logo1_exit.c

OBJS	= ${SRCS:.c=.o}

BNS_OBJ	= ${BNS_SRC:.c=.o}

LIBFT = ./libft/libft.a

PRINTF = ./printf/libftprintf.a

ifeq "$(MAKECMDGOALS)" "bonus"
%.o: %.c $(B_HEADER)
	$(CC) $(CFLAGS) -o $@ -c $< 
else
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<
endif

all: libmlx $(NAME)

libmlx:
	@(cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4)

$(NAME): logo $(OBJS)
	@echo "\033[0;33m\n Building the libft library, please wait... \n\033[0m"
	@make -C ./libft
	@sleep 1
	@echo "\033[0;36m\n Libft built. \n\033[0m"
	@echo "\033[0;33m\n Building the printf library, please wait... \n\033[0m"
	@make -C ./printf
	@sleep 1
	@echo "\033[0;36m\n Printf built. \n\033[0m"
	@sleep 1
	@($(CC) $(OBJS) $(LIBS) $(LIBFT) $(PRINTF) -o $(NAME))
	@echo "\033[0;32m\n =>=>=>=> so_long build completed. <=<=<=<=\n\033[0m"

$(BONUS): libmlx logo $(BNS_OBJ)
	@echo "\033[0;33m\n Building part bonus, please wait... \n\033[0m"
	@sleep 2
	@make -C libft
	@echo "\033[0;36m\n Libft built. \n\033[0m"
	@make -C printf
	@echo "\033[0;36m\n Printf built. \n\033[0m"
	@($(CC) $(BNS_OBJ) $(LIBS) $(LIBFT) $(PRINTF) -o $(BONUS))
	@echo "\033[0;32m\n =>=>=>=> so_long_bonus build completed. <=<=<=<=\n\033[0m"

bonus : $(BONUS)

logo:
	@printf "\033[0;36m\n  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄            ▄▄▄▄▄▄▄▄▄▄▄  ▄▄        ▄  ▄▄▄▄▄▄▄▄▄▄▄  "   
	@printf "			 \n ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌          ▐░░░░░░░░░░░▌▐░░▌      ▐░▌▐░░░░░░░░░░░▌ "             
	@printf "			 \n ▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░▌          ▐░█▀▀▀▀▀▀▀█░▌▐░▌░▌     ▐░▌▐░█▀▀▀▀▀▀▀▀▀  "      
	@printf "			 \n ▐░▌          ▐░▌       ▐░▌▐░▌          ▐░▌       ▐░▌▐░▌▐░▌    ▐░▌▐░▌           "      
	@printf "			 \n ▐░█▄▄▄▄▄▄▄▄▄ ▐░▌       ▐░▌▐░▌          ▐░▌       ▐░▌▐░▌ ▐░▌   ▐░▌▐░▌ ▄▄▄▄▄▄▄▄  "      
	@printf "			 \n ▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░▌          ▐░▌       ▐░▌▐░▌  ▐░▌  ▐░▌▐░▌▐░░░░░░░░▌ "      
	@printf "			 \n  ▀▀▀▀▀▀▀▀▀█░▌▐░▌       ▐░▌▐░▌          ▐░▌       ▐░▌▐░▌   ▐░▌ ▐░▌▐░▌ ▀▀▀▀▀▀█░▌ "      
	@printf "			 \n           ▐░▌▐░▌       ▐░▌▐░▌          ▐░▌       ▐░▌▐░▌    ▐░▌▐░▌▐░▌       ▐░▌ "      
	@printf "			 \n  ▄▄▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄█░▌▐░▌     ▐░▐░▌▐░█▄▄▄▄▄▄▄█░▌ "
	@printf "			 \n ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌      ▐░░▌▐░░░░░░░░░░░▌ "
	@printf "			 \n  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀        ▀▀  ▀▀▀▀▀▀▀▀▀▀▀  \n\033[0m"

clean:
	@echo "\033[0;31m\n CLEANNING OBJ FILE.. \n\033[0m"
	@sleep 1
	@make clean -C ./libft
	@make clean -C ./printf
	@rm -rf $(OBJS)
	@rm -rf $(BNS_OBJ)
	@rm -rf $(LIBMLX)/build
	@echo "\033[0;32m <<< ALL OBJECT FILE CLEANED >>> \n\033[0m"

fclean: clean
	@echo "\033[0;31m Cleaning up the project! \n\033[0m"
	@make fclean -C ./libft
	@make fclean -C ./printf
	@rm -rf $(NAME)
	@rm -rf $(BONUS)
	@sleep 2
	@echo "\033[0;34m <<< Project Cleaned! >>> \n\033[0m"

re: fclean all
	@echo "\033[0;30m rebuilding so_long succed! \n\033[0m"

.PHONY: all, clean, fclean, re, libmlx
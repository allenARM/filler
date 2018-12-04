INCLUDES = -I ./includes

SRCS = ./srcs/*

UTILS = ./utils/*

LIBFT = libft/libft.a
LIB_FILLLER = lib_filler.a

OBJ = ./obj

EXEC = amelikia.filler

RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;36m
RED_EXTRA = \033[1;31m
GREEN_EXTRA = \033[1;32m
BLUE_EXTRA = \033[1;36m

all: $(EXEC)

$(EXEC):
	@echo "$(GREEN)Making objects files for $(GREEN_EXTRA)$(LIB_FILLLER)$(RESET)"
	@gcc -Wall -Wextra -Werror $(SRCS) $(INCLUDES) -c -g
	@echo "$(GREEN)Compiling $(GREEN_EXTRA)$(LIB_FILLLER)$(RESET)"
	@ar rc $(LIB_FILLLER) *.o
	@ranlib $(LIB_FILLLER)
	@if [ ! -d "./obj" ]; then mkdir -p $(OBJ); fi
	@echo "$(GREEN)Moving objects files for $(GREEN_EXTRA)$(LIB_FILLLER)$(GREEN) to $(OBJ)$(RESET)"
	@mv *.o $(OBJ)
	@make -C libft
	@echo "$(GREEN)Compiling executable $(GREEN_EXTRA)$(EXEC)$(RESET)"
	@gcc -Wall -Wextra -Werror $(LIB_FILLLER) $(LIBFT) $(INCLUDES) -o $(EXEC) -g
	@echo "$(BLUE_EXTRA)$(EXEC)$(BLUE): Complete$(RESET)"

clean:
	@if [ -d "./obj" ]; then \
	echo "$(RED)Deleting objects for $(RED_EXTRA)$(LIB_FILLLER)$(RESET)"; \
	/bin/rm -rf $(OBJ); \
	fi
	@make -C libft clean
	@echo "$(BLUE_EXTRA)clean$(BLUE): Complete$(RESET)"

fclean: clean
	@if [ -a "$(LIB_FILLLER)" ]; then \
	echo "$(RED)Deleting $(RED_EXTRA)$(LIB_FILLLER)$(RESET)"; \
	/bin/rm -f $(LIB_FILLLER); \
	fi

	@if [ -a "$(EXEC)" ]; then \
	echo "$(RED)Deleting executable $(RED_EXTRA)$(EXEC)$(RESET)"; \
	/bin/rm -f $(EXEC); \
	fi

	@make -C libft fclean
	@echo "$(BLUE_EXTRA)fclean$(BLUE): Complete$(RESET)"

re: fclean all

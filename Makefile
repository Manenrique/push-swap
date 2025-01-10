NAME = push_swap

# Directories
SRC_DIR = src
OPERATIONS_DIR = $(SRC_DIR)/operations
SORT_DIR = $(SRC_DIR)/sort
UTILS_DIR = $(SRC_DIR)/utils
INC_DIR = includes
OBJ_DIR = obj

# Source files
SRCS = $(SRC_DIR)/push_swap.c \
       $(OPERATIONS_DIR)/push_operations.c \
       $(OPERATIONS_DIR)/swap_operations.c \
       $(OPERATIONS_DIR)/rotate_operations.c \
       $(OPERATIONS_DIR)/reverse_rotate_operations.c \
       $(SORT_DIR)/simple_sort.c \
       $(SORT_DIR)/sort_utils.c \
       $(UTILS_DIR)/stack_ops.c \
       $(UTILS_DIR)/utils.c \
       $(UTILS_DIR)/operations_counter.c

# Object files
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compiler flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

# Create object directories
$(shell mkdir -p $(OBJ_DIR) $(OBJ_DIR)/operations $(OBJ_DIR)/sort $(OBJ_DIR)/utils)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

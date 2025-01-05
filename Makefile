CC = gcc

CFLAGS = -Werror -Wextra -Wall -MMD -g3

INCLUDES = -Iincludes -I./lib/ft_printf/includes -I./lib/libft/includes

LIBPRINTF = lib/ft_printf/lib/libprintf.a

LIBLIBFT = lib/libft/lib/libft.a

SRC_DIR = src

OBJ_DIR = objs

SRCS = $(shell find $(SRC_DIR) -name '*.c')

OBJS = $(addprefix $(OBJ_DIR)/,$(addsuffix .o,$(notdir $(basename $(SRCS)))))

DEPENDS = $(OBJS:.o=.d)

NAME = push_swap

-include $(DEPEND)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS) $(LIBPRINTF) $(LIBLIBFT)
			$(CC) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBPRINTF):
	$(MAKE) -C lib/ft_printf

$(LIBLIBFT):
	$(MAKE) -C lib/libft

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C lib/ft_printf clean
	$(MAKE) -C lib/libft clean

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C lib/ft_printf fclean
	$(MAKE) -C lib/libft fclean

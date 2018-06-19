PROJECT = basicb
NAME = $(PROJECT)
C_FILES += src/main.c
LIBFT = ./libft/libft.a
CC = gcc
CFLAGS += -o
CEFLAGS += -lm



all:
	$(CC) $(CFLAGS) $(NAME) $(C_FILES) $(LIBFT) $(CEFLAGS);
test: all
	./$(NAME)

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cledant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 10:40:13 by cledant           #+#    #+#              #
#    Updated: 2017/01/18 15:06:02 by cledant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wall -Wextra -O2 -fsigned-char

SHARED_CFLAGS = -fPIC

SHARED_LIB_CFLAGS = -Wl,--whole-archive -lft -Wl,--no-whole-archive

OBJ_DIR_NAME = obj

LIBS = -lft

INCLUDES = ./includes

INCLUDES_LIBFT = ./libft/includes

LIBFT_PATH = ./libft

SRCS_NAME = malloc.c malloc_init.c malloc_getpagesize.c malloc_get_tiny.c \
			malloc_new_tiny.c malloc_get_small.c malloc_new_small.c \
			malloc_get_large.c malloc_new_large.c malloc_tiny.c \
			malloc_get_number_alloc.c malloc_get_userid.c malloc_allocid.c \
			malloc_get_available_tiny.c malloc_add_new_tiny.c \
			malloc_allocate_tiny.c malloc_small.c malloc_get_available_small.c \
			malloc_add_new_small.c malloc_allocate_small.c malloc_large.c \
			malloc_add_new_large.c malloc_get_available_large.c \
			malloc_allocate_large.c

SRCS_PATH = ./srcs

OBJ_SRCS = $(SRCS_NAME:%.c=$(OBJ_DIR_NAME)/%.o)

NAME = libft_malloc.so

all :	libft $(OBJ_DIR_NAME) $(NAME)

libft :
	make -C $(LIBFT_PATH)

$(OBJ_DIR_NAME) :
	mkdir $(OBJ_DIR_NAME)

$(NAME) : $(OBJ_SRCS)
	$(CC) -shared -o $@ $^ $(SHARED_LIB_CFLAGS) $(CFLAGS)

$(OBJ_DIR_NAME)/%.o : $(SRCS_PATH)/%.c
	$(CC) -o $@ -c $< $(CFLAGS) $(SHARED_CFLAGS) -I$(INCLUDES) -I$(INCLUDES_LIBFT)

clean :
	rm -rf $(OBJ_DIR_NAME)
	make -C $(LIBFT_PATH) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean

re : fclean all

.PHONY : all clean fclean re libft
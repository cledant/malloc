# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cledant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 10:40:13 by cledant           #+#    #+#              #
#    Updated: 2017/01/24 09:29:28 by cledant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

CC = gcc

CFLAGS = -Werror -Wall -Wextra -O2 -fsigned-char

SHARED_CFLAGS = -fPIC

OBJ_DIR_NAME = obj

LIBS = -lft

INCLUDES = ./includes

INCLUDES_LIBFT = ./libft/includes

LIBFT_PATH = ./libft

SRCS_NAME = malloc.c malloc_init.c malloc_getpagesize.c malloc_get_tiny.c \
			malloc_new_tiny.c malloc_get_small.c malloc_new_small.c \
			malloc_get_large.c malloc_new_large.c malloc_tiny.c \
			malloc_get_number_alloc.c malloc_get_userid.c malloc_get_allocid.c \
			malloc_get_available_tiny.c malloc_add_new_tiny.c \
			malloc_allocate_tiny.c malloc_small.c malloc_get_available_small.c \
			malloc_add_new_small.c malloc_allocate_small.c malloc_large.c \
			malloc_add_new_large.c malloc_get_available_large.c \
			malloc_allocate_large.c free.c free_tiny.c \
			free_seek_header_for_addr_tiny.c free_is_valid_alloc_tiny.c \
			free_seek_nb_alloc_tiny.c free_deallocate_tiny.c \
			free_check_to_delete_header_tiny.c free_delete_tiny.c \
			free_small.c free_seek_header_for_addr_small.c \
			free_is_valid_alloc_small.c free_seek_nb_alloc_small.c \
			free_deallocate_small.c free_check_to_delete_header_small.c \
			free_delete_small.c free_large.c free_seek_and_deallocate_large.c \
			free_check_to_delete_header_large.c free_delete_large.c \
			realloc.c realloc_seek_header_and_type.c \
			realloc_seek_header_for_addr_large.c realloc_tiny.c realloc_new_ptr.c \
			realloc_change_size_tiny.c realloc_small.c realloc_change_size_small.c \
			realloc_large.c show_alloc_mem.c sam_itoa_base_stack.c sam_get_list.c \
			sam_get_last_list.c sam_new_list.c sam_add_new_list.c sam_reset_list.c \
			sam_reset_list.c sam_get_tiny_list.c sam_get_small_list.c \
			sam_get_large_list.c sam_display_list.c sam_get_max_print.c \
			sam_get_zone_to_display.c sam_display_zone.c sam_clean_memory.c \
			sam_display_zone_header.c sam_display_zone_alloc.c \
			sam_display_zone_tiny.c sam_display_zone_small.c \
			sam_display_zone_large.c sam_display_total_mem.c \
			sam_display_zone_alloc.c sam_set_displayed.c calloc.c reallocarray.c \
			reallocf.c reallocf_wrapper.c show_alloc_mem_ex.c sam_display_list_ex.c \
			sam_display_zone_ex.c sam_display_zone_large_ex.c \
			sam_display_zone_tiny_ex.c sam_display_zone_small_ex.c \
			sam_disp_zone_alloc_ex.c sam_hex_dump.c

SRCS_PATH = ./srcs

OBJ_SRCS = $(SRCS_NAME:%.c=$(OBJ_DIR_NAME)/%.o)

NAME = libft_malloc_$(HOSTTYPE).so

all :	libft $(OBJ_DIR_NAME) $(NAME)
	ln -s $(NAME) libft_malloc.so

libft :
	make -C $(LIBFT_PATH)

$(OBJ_DIR_NAME) :
	mkdir $(OBJ_DIR_NAME)

$(NAME) : $(OBJ_SRCS)
	$(CC) -shared -o $@ $^ $(CFLAGS) $(LIBS) -L$(LIBFT_PATH)

$(OBJ_DIR_NAME)/%.o : $(SRCS_PATH)/%.c
	$(CC) -o $@ -c $< $(CFLAGS) $(SHARED_CFLAGS) -I$(INCLUDES) -I$(INCLUDES_LIBFT)

clean :
	rm -rf $(OBJ_DIR_NAME)
	make -C $(LIBFT_PATH) clean

fclean : clean
	rm -rf $(NAME)
	rm -rf libft_malloc.so
	make -C $(LIBFT_PATH) fclean

re : fclean all

.PHONY : all clean fclean re libft

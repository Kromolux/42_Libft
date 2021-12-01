#\norminette -R CheckForbiddenSourceHeader *.c *.h 			#check norminette
#gcc -c -Wall -Wextra -Werror ft_isalpha.c ft_strlen.c 		#to compile without main
#ar rc libft.a ft_isalpha.o ft_strlen.o 					#create library with .o files
#ranlib libft.a 											#to create an index in the library
#gcc main.c -L. -lft -Wall -Wextra -Werror -o test.out 		#compile with library to test functions

NAME := libft.a
LIB := lib/
OBJ := obj/
CC := gcc
HEADERFILES := libft.h
SRCFILES := ft_strlen.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c
OBJFILES := $(SRCFILES:%.c=%.o)
PRE_OBJFILES := $(OBJFILES:%=$(OBJ)%)
LDFLAGS ?=
CFLAGS ?= -Wall -Wextra -Werror

all: norminette $(NAME)

norminette:
	\norminette -R CheckForbiddenSourceHeader $(SRCFILES) $(HEADERFILES)

$(NAME): $(PRE_OBJFILES)
#	$(CC) $(LDFLAGS) -o $@ $^
	@mkdir -p $(dir $(LIB))
	ar rc $(LIB)$(NAME) $(PRE_OBJFILES)
	ranlib $(LIB)$(NAME)
	gcc main.c -L$(LIB) -lft -Wall -Wextra -Werror -o test.out -lbsd

$(OBJ)%.o: %.c $(HEADERFILES)
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(LIB)$(NAME) $(PRE_OBJFILES)
	rmdir $(LIB) $(OBJ)

.PHONY: clean
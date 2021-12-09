#\norminette -R CheckForbiddenSourceHeader *.c *.h 			#check norminette
#gcc -c -Wall -Wextra -Werror ft_isalpha.c ft_strlen.c 		#to compile without main
#ar rc libft.a ft_isalpha.o ft_strlen.o 					#create library with .o files
#ranlib libft.a 											#to create an index in the library
#gcc main.c -L. -lft -Wall -Wextra -Werror -o test.out 		#compile with library to test functions

NAME 		:= libft.a
LIBFOLDER 	:= lib/
OBJFOLDER 	:= obj/
CC 			:= gcc
HEADERFILES := libft.h
SRCFILES 	:= ft_strlen.c \
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
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_itoa.c \
				ft_split
BONUSSRC		ft_latnew.c
OBJFILES 	:= $(SRCFILES:%.c=%.o)
#PRE_OBJFILES := $(OBJFILES:%=$(OBJ)%)
LDFLAGS 	?=
CFLAGS 		?= -Wall -Wextra -Werror

all: norminette $(NAME)

norminette:
	\norminette -R CheckForbiddenSourceHeader $(SRCFILES) $(HEADERFILES)

$(NAME): $(OBJFILES)
#	$(CC) $(LDFLAGS) -o $@ $^
	@mkdir -p $(dir $(LIBFOLDER))
	ar rc $(LIBFOLDER)$(NAME) $(OBJFILES:%=$(OBJFOLDER)%)
#$(OBJFILES)
	ranlib $(LIBFOLDER)$(NAME)
	$(CC) main.c -L$(LIBFOLDER) -lft $(CFLAGS) -o test.out -lbsd

$(OBJFILES:%.o=$(OBJFOLDER)%): %.c $(HEADERFILES)
	@mkdir -p $(dir $(OBJFOLDER))
	$(CC) -c $(CFLAGS) -o $@ $<

bonus: $(BONUSSRC)
	ar rc $(LIBFOLDER)$(NAME) $(BONUSSRC)

$(BONUSSRC):%.o=: %.c $(HEADERFILES)
	$(CC) -c $(CFLAGS) -o $@ $<

clean: 
	rm -f $(OBJFILES:%=$(OBJFOLDER)%)
	@mkdir -p $(dir $(OBJFOLDER))
	rmdir $(OBJFOLDER)

fclean: clean
	rm -f $(LIBFOLDER)$(NAME)
	@mkdir -p $(dir $(LIBFOLDER))
	rmdir $(LIBFOLDER)

re: fclean all

.PHONY: clean fclean re
cc = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAG = rc

NAME = libftprintf.a
MY_SOURCES = \
			ft_printf_func.c \
			ft_printf_func2.c \
			ft_printf.c \



MY_OBJECTS = $(MY_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(MY_OBJECTS)
		$(AR) $(ARFLAG) $(NAME) $(MY_OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(MY_OBJECTS)

fclean: clean 
	rm -f $(NAME)

re: fclean all 
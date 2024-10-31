cc = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar

NAME = libftprintf.a
MY_SOURCES = \
ft_putchar_pr.c \
ft_putnbr_fd.c \
int ft_parse.c \



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
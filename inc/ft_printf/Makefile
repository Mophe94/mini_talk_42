# ************************************************************************** #
#                                 DIRECTORIES                                #
# ************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

# Répertoires pour les fichiers d'en-tête et les fichiers sources
INCDIR = inc
SRCDIR = src

# Fichiers source
SRCS = $(SRCDIR)/ft_printf.c $(SRCDIR)/ft_putadress.c $(SRCDIR)/ft_putchar.c \
       $(SRCDIR)/ft_putnbr.c $(SRCDIR)/ft_putstr.c $(SRCDIR)/ft_utils.c

# Fichiers objets correspondants
OBJ = $(SRCS:$(SRCDIR)/%.c=%.o)

# Option pour indiquer où chercher les fichiers d'en-tête
CFLAGS += -I$(INCDIR)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : re clean fclean all bonus

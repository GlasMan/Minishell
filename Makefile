NAME    = minishell
CC = gcc -lreadline -ltinfo
INC = minishell.h
CFLAGS =
RM = rm -rf

SRCS    =	ft_cd.c \
			main.c \
			ft_env.c \

ARCPATH = "libft/libft.a"

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) ${CFLAGS} $(OBJS) $(ARCPATH)  -o $(NAME)
	@echo shell is ready

%.o: %.c $(INC)
	@echo $(R)Complining [$<]
	@$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@$(RM) $(OBJS)
	@echo $(R)Removed [$(OBJS)]

fclean: clean
	@$(RM) $(NAME)
	@echo $(R)Removed [$(NAME)]

re: fclean all

.PHONY: all, clean, fclean, re
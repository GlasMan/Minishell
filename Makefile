NAME    = minishell
CC = gcc -lreadline
INC = minishell.h
CFLAGS =
RM = rm -rf
LIBFT	= libft/libft.a


SRCS    =	ft_cd.c \
			main.c \
			ft_env.c \

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(LIBFT):
	make -C libft/

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) ${CFLAGS} $(OBJS) $(LIBFT) -o $(NAME)
	@echo shell is ready

%.o: %.c $(INC)
	@echo $(R)Complining [$<]
	@$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@$(RM) $(OBJS)
	@make clean -C libft/
	@echo $(R)Removed [$(OBJS)]

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libft/
	@echo $(R)Removed [$(NAME)]

re: fclean all

.PHONY: all, clean, fclean, re

CC = cc
CFLAGS = #-Wall -Wextra -Werror -fsanitize=address -g

RM = rm -rf  
HEADERS = minitalk.h
SRCC = client.c utils.c
SRCS = server.c 


NAME = client 
NAME2 = server 

OBJC = $(SRCC:.c=.o)
OBJS = $(SRCS:.c=.o)


all : $(NAME) $(NAME2)

$(NAME) : $(OBJC)
	$(CC) $(CFLAGS) $(OBJC) -o $(NAME)

$(NAME2) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME2)

clean:
	@$(RM) $(OBJS) $(OBJC) 
	

%.o : %.c $(HEADERS) 
	$(CC) $(CFLAGS) -c $< -o $@ 

fclean : clean 
		@$(RM) $(NAME) $(NAME2)

re : fclean all 

.PHONY: all clean fclean re 
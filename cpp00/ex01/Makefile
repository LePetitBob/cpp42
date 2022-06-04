
SRCS = phonebook.cpp

NAME = phonebook

CC = clang++

FLAGS = -Wall -Werror -Wextra

OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@

clean:
	rm -rf $(OBJS)

fclean: clean 
	rm -rf $(NAME)
re: fclean all

PHONY = re fclean clean all

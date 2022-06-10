NAME = CL4P-TP

SRC_DIR = 	$(shell find srcs -type d)

OBJ_DIR	= obj

SRC = main.cpp ClapTrap.cpp

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))

CFLAGS =	-Wall -Wextra -Werror -std=c++98

CC =	c++

all: $(NAME)

$(NAME): $(OBJ)
				$(CC) $(OBJ) $(CFLAGS) $(IFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o : %.cpp
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

clean:
				rm -rf $(OBJ_DIR)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY: all clean fclean re
NAME = Fixed

INC_DIR = 	$(shell find includes -type d)

SRC_DIR = 	$(shell find srcs -type d)

OBJ_DIR	= obj

vpath %.cpp $(foreach dir, $(SRC_DIR), $(dir):)

vpath %.hpp $(foreach dir, $(INC_DIR), $(dir):)

SRC = main.cpp Fixed.cpp

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))

CFLAGS =	-Wall -Wextra -Werror -std=c++98

IFLAGS =	$(foreach dir, $(INC_DIR), -I $(dir))

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
BOLDBLUE = \033[1m\033[34m

NAME = test
FLAGS = -Wall -Wextra -Werror -std=c++98 -g
SRC = ./main.cpp
OBJ=$(SRC:.cpp=.o)

%.o:%.cpp
	@clang++ -o $@ -c $< $(FLAGS)

$(NAME): $(OBJ)
	@clang++ -o $(NAME) $(OBJ) $(FLAGS)
	@echo "$(BOLDBLUE)Tests are created $(B&W)"

all: $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
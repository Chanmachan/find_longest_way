NAME = find_longest_way

SRCS = src/main.cpp src/longest_way.cpp

CXX = c++

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

debug: CXXFLAGS = -DDEBUG
debug: re

test:
	mkdir -p build && cd build && cmake .. && make && ctest

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re debug test
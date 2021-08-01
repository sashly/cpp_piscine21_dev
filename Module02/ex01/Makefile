
NAME       =    fixed1
UNAME_S	   =    $(shell uname -s)
CPPC       =    clang++
CFLAGS     =    -Wall -Wextra -Werror
RM         =    rm -f

HEADERS	   =    .

SRCS_DIR   =    .
SRCS_LIST  =    main.cpp \
				Fixed.cpp
SRCS       =    $(addprefix $(SRCS_DIR)/, $(SRCS_LIST))

OBJS_DIR   =    ./objs_$(UNAME_S)
OBJS       =    $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CPPC) $(CFLAGS) -c $< -o $@ -I$(HEADERS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPPC) $(CFLAGS) $(OBJS) -o $(NAME) -I$(HEADERS)

clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJS_DIR)

fclean:     clean
	$(RM) $(NAME)

re:          fclean all

.PHONY:      all clean fclean re

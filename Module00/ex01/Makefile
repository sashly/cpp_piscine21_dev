
UNAME_S	   =   $(shell uname -s)

NAME       =    phone_book

CPPC       =    clang++

CFLAGS     =    -Wall -Wextra -Werror -std=c++98

RM         =    rm -f

HEADERS	   =    .

SRCS_DIR   =    .
SRCS_LIST  =    main.cpp \
				PbContact_class.cpp \
				PhoneBook_class.cpp
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

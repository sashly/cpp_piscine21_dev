
NAME       =    bsp
UNAME_S	   =    $(shell uname -s)
CPPC       =    clang++
CFLAGS     =    -Wall -Wextra -Werror
RM         =    rm -f

HEADERS	   =    .
SRCS_DIR   =    .
SRCS_LIST  =    main.cpp \
				Fixed.cpp \
				Point.cpp \
				bsp.cpp
SRCS       =    $(addprefix $(SRCS_DIR)/, $(SRCS_LIST))
OBJS_DIR   =    ./objs_$(UNAME_S)
DEPS_DIR   =    ./deps_$(UNAME_S)
OBJS       =    $(SRCS:%.cpp=$(OBJS_DIR)/%.o)
DEPS       =    $(SRCS:%.cpp=$(DEPS_DIR)/%.d)

$(OBJS_DIR)/%.o: %.cpp Makefile
	@mkdir -p $(@D)
	$(CPPC) $(CFLAGS) -c $< -o $@

$(DEPS_DIR)/%.d: %.cpp
	@mkdir -p $(@D)
	@$(CPPC) $(CFLAGS) -MM $< >> $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CPPC) $(CFLAGS) -MMD $(OBJS) -o $(NAME) -I$(HEADERS)

clean:
	$(RM) $(OBJS) $(DEPS)
	$(RM) -r $(OBJS_DIR) $(DEPS_DIR)
fclean:     clean
	$(RM) $(NAME)
re:          fclean all

.PHONY:      all clean fclean re

-include $(DEPS)

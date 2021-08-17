
NAME       =    serialization
UNAME_S	   =    $(shell uname -s)
CPPC       =    clang++
CFLAGS     =    -Wall -Wextra -Werror
RM         =    rm -f
HEADERS	   =    .
SRCS_DIR   =    .
SRCS_LIST  =    main.cpp \
				Data.cpp

SRCS       =    $(addprefix $(SRCS_DIR)/, $(SRCS_LIST))
OBJS_DIR   =    ./build_$(UNAME_S)
OBJS       =    $(SRCS:%.cpp=$(OBJS_DIR)/%.o)
DEPS       =    $(SRCS:%.cpp=$(OBJS_DIR)/%.d)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp Makefile
	@mkdir -p $(@D)
	$(CPPC) $(CFLAGS) -MMD -c $< -o $@ -I$(HEADERS)

all: $(NAME)
$(NAME): $(OBJS)
	$(CPPC) $(CFLAGS) $(OBJS) -o $(NAME) -I$(HEADERS)

clean:
	$(RM) $(OBJS) $(DEPS)
	$(RM) -r $(OBJS_DIR)
fclean:     clean
	$(RM) $(NAME)
re:          fclean all

.PHONY:      all clean fclean re

ifneq "$(MAKECMDGOALS)" "clean"
ifneq "$(MAKECMDGOALS)" "fclean"
-include $(DEPS)
endif
endif

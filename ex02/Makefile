NAME		:= main

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#
# LIBS			libraries to be used
# LIBS_TARGET	libraries to be built
#
# INCS			header file locations
#
# SRCS			source files
#
# OBJS			object files
#
# CC			compiler
# CFLAGS		compiler flags
# CPPFLAGS		preprocessor flags
# IFLAGS		Include flags
# LDFLAGS		linker flags
# LDLIBS		libraries name

INCS		:= .

SRCS		:=	main.cpp \
				Fixed.cpp

OBJ_DIR		:=	obj
OBJS		:= $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

CPP			:= c++
CFLAGS		:= -Wall -Wextra -Werror -std=c++98
IFLAGS		:= $(addprefix -I,$(INCS))

#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#
# RM		force remove
# MAKEFLAGS	make flags

MKDIR		= mkdir -p
RM			= rm -rf
MAKEFLAGS	+= --no-print-directory

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#
# all		default goal
# $(NAME)	link .o -> binary
# %.o		compilation .cpp -> .o
# clean		remove .o
# fclean	remove .o + binary
# re		remake default goal

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) $(CPPFLAGS) $(IFLAGS) -o $@ $(OBJS)
	$(info CREATED $(NAME))

$(OBJ_DIR)/%.o: %.cpp
	$(MKDIR) $(@D)
	$(CPP) $(CFLAGS) $(CPPFLAGS) $(IFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
# My perfect personal Makefile <3

# Spepcify the name of the executable
target := execname

# Depending if you want to compile specific files or all .c files
# comment/uncomment specific line


# Here its just gonna compile all .c files
SRCS=$(wildcard *.c)
objs=$(SRCS:.c=.o)

#  Here you have to specify by name you .c files like that:
# SRCS = main.c maasg.c
# objs=$(SRCS:.c=.o)


# Compiller
CC := gcc
# Flags
CFLAGS := -Wall -Werror

all: $(target)


deps := $(patsubst %.o,%.d,$(objs))
-include $(deps)
DEPFLAGS = -MMD -MF $(@:.o=.d)

$(target): $(objs)
	$(CC) $(CFLAGS) -o $@ $^
	@echo -e "\e[92mSUCCESS\033[0m"
	@echo -e "Executable name: \e[96m$(target)\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) -c $< $(DEFLAGS)
	

clean:
	rm -fv $(target) $(objs) $(deps)
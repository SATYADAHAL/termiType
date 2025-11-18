CC = g++
CFLAGS = -Wall -Wextra -std=c++11 -O3

SRCS = box.cpp check_value.cpp clear.cpp cursor.cpp \
       get_time.h main.cpp terminal.cpp ttyProperties.cpp time.cpp results.cpp

HDRS = anscii.h box.h get_time.h terminal.h ttyspeed.h word_generator.h wordlist.h

OBJS = $(SRCS:.cpp=.o)

all: main

main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o tt

%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o tt


#
#
#
#

C = gcc
CXX = clang++

CFLAGS = -ggdb -DDEBUG


TARGETS = pacific_atlantic weblinks cafeteria find_seq find_dups tree islands anagram search intervals rotate palidrome permutation card_game longest_unique_sub prime_test hackerrank sort sort_colors
#TARGETS = prime_test hackerrank sort recurse
# CPPFLAGS  = -v -Wall -std=c++0x -ggdb -fPIC
CPPFLAGS =  -ggdb -DDEBUG
LDFLAGS = -std=c++2a -stdlib=libc++ 

LDFLAGS_COMMON = -std=c++2a -stdlib=libc++ 

all: $(TARGETS)


% :: %.o
	$(CXX) $(LDFLAGS) $< -o $@ 

%.o : %.cc
	$(CXX) -c $(CPPFLAGS) $< -o $@

%.o : %.c
	$(C) -c $(CFLAGS) $< -o $@
#	$(C) $(CFLAGS) -c $(SOURCE_C) -o $(TARGET)
#	$(C) $(OBJECTS_C) $(LDFLAGS_COMMON) -o $(TARGET)
clean:
	rm -rf *.o $(TARGETS)

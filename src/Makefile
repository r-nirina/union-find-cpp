# Compiler options
CXX      = g++
CXXFLAGS  += -g -Wall -std=c++11 -pedantic

# make default
.DEFAULT_GOAL := all

# Source files
SOURCES = 
SOURCES += equivalence-class.cpp
SOURCES += union-find.cpp

OBJECTS = $(SOURCES:.cpp=.o)

LDFLAGS +=

$(OBJECTS) : %.o : %.cpp
	$(CXX) -MMD $(CXXFLAGS) -c $< -o $@

CLEAN_OBJECTS = $(OBJECTS)
TARGETS = 


# ------------- test_union_find -------------

UNION_FIND_SOURCES = test-union-find.cpp
UNION_FIND_OBJECTS = $(UNION_FIND_SOURCES:.cpp=.o)

test_union_find.out : $(UNION_FIND_OBJECTS) $(OBJECTS) $(HEADERS)
	$(CXX) $(UNION_FIND_OBJECTS) $(OBJECTS) -o $@ $(LDFLAGS)
	
$(UNION_FIND_OBJECTS): %.o : %.cpp
	$(CXX) -MMD $(CXXFLAGS) -c $< -o $@

all : test_union_find.out
TARGETS += test_union_find.out
CLEAN_OBJECTS += $(UNION_FIND_OBJECTS)


# ------------- cleanup -------------

DEPS = $(CLEAN_OBJECTS:.o=.d)

clean:
	@rm -f $(DEPS) $(TARGETS) $(CLEAN_OBJECTS)

-include $(DEPS)
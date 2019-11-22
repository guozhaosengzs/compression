#Add more sources by including additional lines of the format:
SOURCES += Heap.cpp
SOURCES += TreeNode.cpp

OBJECTS=$(SOURCES:.cpp=.o)

DEPFILES:=$(SOURCES:.cpp=.d)


.PHONY : all

all: compress uncompress

.PHONY : clean

CXX_FLAGS = -g -std=c++11 -Wall -Werror

clean:
	rm -rf compress uncompress ${OBJECTS}

compress: compress.cpp ${OBJECTS} makefile
	g++ $(CXX_FLAGS) ${OBJECTS} compress.cpp -o $@

uncompress: uncompress.cpp ${OBJECTS} makefile
	g++ $(CXX_FLAGS) ${OBJECTS} uncompress.cpp -o $@

$(OBJECTS): %.o: %.cpp %.h %.d makefile
	g++ $(CXX_FLAGS) -c $< -o $@

%.d: %.cpp makefile
	g++ $(CXX_FLAGS) -MM -MT '$(patsubst %.cpp,%.o,$<)' $< -MF $@

#Add more sources by including additional lines of the format:
#SOURCES += ClassName.cpp

OBJECTS=$(SOURCES:.cpp=.o)

DEPFILES:=$(SOURCES:.cpp=.d)


.PHONY : all

all: compressor

.PHONY : clean

CXX_FLAGS = -g -std=c++11 -Wall -Werror

clean: 
	rm -rf compressor ${OBJECTS}

compressor: main.cpp ${OBJECTS} makefile
	g++ $(CXX_FLAGS) ${OBJECTS} main.cpp -o $@

$(OBJECTS): %.o: %.cpp %.h %.d makefile
	g++ $(CXX_FLAGS) -c $< -o $@

%.d: %.cpp makefile
	g++ $(CXX_FLAGS) -MM -MT '$(patsubst %.cpp,%.o,$<)' $< -MF $@

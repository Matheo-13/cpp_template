# Define directories
CXXDIR = src
EXEDIR = build
BUILDFILEDIR = build/object_files
INCLUDEFILEDIR = include

# Define output executable
OUT = $(EXEDIR)/project

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -I./$(INCLUDEFILEDIR)
# LINKING = `pkg-config --cflags gtkmm-3.0`
# LDLIBS = `pkg-config --libs gtkmm-3.0`

# List of source files
CXXFILES = $(wildcard $(CXXDIR)/*.cc $(CXXDIR)/*.cpp)

# Object files
OFILES = $(patsubst $(CXXDIR)/%.cc,$(BUILDFILEDIR)/%.o, $(CXXFILES))

#Premiere regle 
all: $(OUT)

$(OUT): $(OFILES)
	$(CXX) $(CXXFLAGS) $(LINKING) $(OFILES) -o $@ $(LDLIBS)

$(BUILDFILEDIR)/%.o: $(CXXDIR)/%.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@


# Rule to generate dependencies
depend:
	@echo " *** MISE A JOUR DES DEPENDANCES ***"
	@(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	  $(CXX) -MM -std=c++11 -Wall -g $(CXXFLAGS) $(CXXFILES) | \
	  egrep -v "/usr/include" \
	 ) > Makefile.new
	@mv Makefile.new Makefile

# Clean rule
clean:
	@echo " *** EFFACE MODULES OBJET ET EXECUTABLE ***"
	@/bin/rm -f $(BUILDFILEDIR)/*.o $(BUILDFILEDIR)/*.x *.cc~ *.h~ $(OUT)

run:
	./$(OUT)


# DO NOT DELETE THIS LINE
hello.o: src/hello.cc include/hello.h
main.o: src/main.cc include/hello.h

# Final project
EXE=main

# Main target
all: $(EXE)

# MinGW
ifeq "$(OS)" "Windows_NT"
CFLG=-O3 -Wall
LIBS=
CLEAN=del *.exe *.o *.a
else

# OSX
ifeq "$(shell uname)" "Darwin"
CFLG=-O3 -Wall -Wno-deprecated-declarations
LIBS=

# Linux/Unix/Solaris
else
CFLG=-O3 -Wall -std=c++0x
LIBS=
endif

# OSX/Linux/Unix/Solaris
CLEAN=rm -f $(EXE) *.o *.a
endif

# SOURCE FILES
SOURCES = $(EXE).cpp Diary.cpp
OBJECTS = $(EXE).o Diary.o
$(OBJECT): $(SOURCES)

# Compile rules
.c.o:
	gcc -c $(CFLG) $<
.cpp.o:
	g++ -c $(CFLG) $<

# Link
$(EXE):$(OBJECTS)
	g++ -O3 -o $@ $^   $(LIBS)

# Clean
clean:
	$(CLEAN)

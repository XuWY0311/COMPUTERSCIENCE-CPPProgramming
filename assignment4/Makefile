# makefile template for CSC3002
# 
# Special Symbols used:
# 	$@ name of the file to be made (target)
# 	$* prefix of the file to be made (target)
# 	$? names of the CHANGED dependents.
#	$^ names of ALL the dependents (dependency).
# 	$< name of the related file that caused the action (command)
#
# Usage:
#	make all
#		It compiles everything so that you can do local testing 
#		before installing applications.
#
#	make clean
#		It cleans applications, gets rid of the executables, 
#		any temporary files, object files, etc.
#
#	make echo
#		It echo a string to the console.
#
# Custom Macros:
#
#	PROGRAM
#		Name of the executable program used to test your assignment
#
#	OBJECTS
#		Names of all the object files needed to be linked
#
# Assumptions:
#
#	If header file is used, it must share the SAME filename as
#	the source file.  Ex: Assignment1.cpp, Assignment1.h
#
#
# Note:
#	C++17 version is used to compile the source files.
#
#	lib.cpp contains the functions extracted from the stanford library.
#	
# Revision History:
#	2022/Sept/04	Initial Creation	Kinley	


PROGRAM = \
	p1 \
	p2 \
	p3 \
	p4

OBJECTS = \
	p1KnightsTour.o \
	p2MergeSort.o \
	p3buffer.o \
	p4WildcardMatch.o \
	SimpleTextEditor.o \
	lib.o

CPPFLAGS = -std=c++17
CC = g++

all: $(PROGRAM)

p1: p1KnightsTour.o lib.o
	$(CC) $(CPPFLAGS) -o $@ $^

p2: p2MergeSort.o lib.o
	$(CC) $(CPPFLAGS) -o $@ $^

p3: p3buffer.o lib.o SimpleTextEditor.o
	$(CC) $(CPPFLAGS) -o $@ $^

p4: p4WildcardMatch.o lib.o
	$(CC) $(CPPFLAGS) -o $@ $^

%.o: %.cpp %.h
	$(CC) $(CPPFLAGS) -c $*.cpp -o $@

# echo:
# 	@echo I love CSC3002 !!!!!
	
# ***************************************************************
# Standard entries to remove files from the directories
#    clean -- delete derived files in preparation for rebuild

clean:
	del *.o *.a *.exe

# rm -f *.o *.a $(PROGRAM)

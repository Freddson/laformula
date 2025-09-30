# How do i make it sort through all the lib folders bru :sob:
CXX := g++
#LIB_DIRS := $(notdir $(wildcard lib/*))
#foobar := $(foreach libr,$(LIB_DIRS),$(libr))
#OBJFLAGS := -c $(foobar).cpp -o $(foobar).o
#STATFLAGS := ar rcs lib$(foobar).a $(foobar).o
libs:
	$(CXX)

#clean:
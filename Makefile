# How do i make it sort through all the lib folders bru :sob:
CXX := g++
#LIB_DIRS := $(notdir $(wildcard lib/*))
#foobar := $(foreach libr,$(LIB_DIRS),$(libr))
#OBJFLAGS := -c $(foobar).cpp -o $(foobar).o
#STATFLAGS := ar rcs lib$(foobar).a $(foobar).o
net:
	$(CXX) -I/msys64/include -L/msys64/lib -c ./lib/Networking/Networking.cpp -lcpr -o Networking.o

test:
	$(CXX) -I/msys64/include -L/msys64/lib ./testing/test.cpp ./testing/libNetworking.a -lcpr
#g++ -I/msys64/include -L/msys64/lib -lcpr test.cpp
#clean:

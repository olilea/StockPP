CC=gcc
CXX=g++
RM=rm -f

FLAGS=	-Wall \
		-pedantic

EXECUTABLE=Stock++

SRCS=	main.cpp \
		stockPP.cpp \
		userInterface.cpp \
		user.cpp \
		userHandler.cpp

all:	main
		@echo "Build finished"

main:	$(SRCS)
		$(CXX) -o $(EXECUTABLE) $(SRCS) $(FLAGS)

clean:
		$(RM) $(EXECUTABLE)

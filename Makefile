CC=gcc
CXX=g++
RM=rm -f

FLAGS=	-Wall \
		-pedantic

EXECUTABLE=Stock++

SRCS=	main.cpp \
		StockPP.cpp \
		UserInterface.cpp \
		User.cpp \
		UserHandler.cpp

all:	main
		@echo "Build finished"

main:	$(SRCS)
		$(CXX) -o $(EXECUTABLE) $(SRCS) $(FLAGS)

clean:
		$(RM) $(EXECUTABLE)

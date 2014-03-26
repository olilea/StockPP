CC=gcc
CXX=g++
RM=rm -f

FLAGS=	-Wall \
		-pedantic

EXECUTABLE=Stock++

SRCS=	main.cpp \
		stockPP.cpp \
		userInterface.cpp \
		accounts/account.cpp \
		accounts/accountHandler.cpp \
		stocks/stock.cpp

all:	main
		@echo "Build finished"

main:	$(SRCS)
		$(CXX) -o $(EXECUTABLE) $(SRCS) $(FLAGS)

clean:
		$(RM) $(EXECUTABLE)

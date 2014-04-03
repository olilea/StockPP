CC=gcc
CXX=g++
RM=rm -f

FLAGS=	-Wall \
		-pedantic

EXECUTABLE=bin/Stock++

SRCS=	src/main.cpp \
		src/stockPP.cpp \
		src/userInterface.cpp \
		src/accounts/account.cpp \
		src/accounts/accountHandler.cpp \
		src/stocks/stock.cpp \
		src/stocks/stockHandler.cpp

all:	main
		@echo "Build finished"

main:	$(SRCS)
		mkdir -p bin/
		$(CXX) -o $(EXECUTABLE) $(SRCS) $(FLAGS)

clean:
		$(RM) $(EXECUTABLE)

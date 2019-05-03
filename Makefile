CC=g++
INC_DIR=include
SRC_DIR=src
CFLAGS=-I$(INC_DIR) -Wall -c -O2
TARGET=$(SRC_DIR)/lag.o $(SRC_DIR)/nfa.o $(SRC_DIR)/dfa.o $(SRC_DIR)/parser.o $(SRC_DIR)/printer.o
TARGET_OBJ= lag.o nfa.o dfa.o parser.o printer.o

all: clean lag

lag: $(TARGET_OBJ)
	$(CC) $(TARGET) -o lag

lag.o:$(SRC_DIR)/lag.cpp
	$(CC) $< -o $(SRC_DIR)/lag.o $(CFLAGS)

nfa.o:$(SRC_DIR)/nfa.cpp
	$(CC) $< -o $(SRC_DIR)/nfa.o $(CFLAGS)

dfa.o:$(SRC_DIR)/dfa.cpp
	$(CC) $< -o $(SRC_DIR)/dfa.o $(CFLAGS)

parser.o:$(SRC_DIR)/parser.cpp
	$(CC) $< -o $(SRC_DIR)/parser.o $(CFLAGS)

printer.o:$(SRC_DIR)/printer.cpp
	c++ $< -o $(SRC_DIR)/printer.o $(CFLAGS)

clean:
	rm -rf $(SRC_DIR)/*.o
	rm -rf lag
	rm -rf lex

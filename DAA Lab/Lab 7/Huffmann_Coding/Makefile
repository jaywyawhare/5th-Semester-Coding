CC      = gcc
CFLAGS	= -g -Wall
SRC		= src
OBJ		= obj
SRCS	= $(wildcard $(SRC)/*.c)
OBJS	= $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

BINDIR 	= bin
BIN		= $(BINDIR)/main
SUBMITNAME = code.zip

all: $(BIN)

release: CFLAGS = -wall -O2 -DNDEBUG
release: clean
release: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(BINDIR)/* $(OBJ)/*

submit:
	$(RM) -r $(SUBMITNAME)
	$(ZIP) $(SUBMITNAME) $(BIN)
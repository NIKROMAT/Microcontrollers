COMP = sdcc
SRC = code.c
OBJ = code
CFLAGS = -mmcs51 --model-small
TARGET = code
DIR = ./build
SHELL = /bin/bash


.PHONY: all run clean cleanall comp

all: comp clean 

# run: comp
# 	cd $(DIR) &&	./$(TARGET)

comp: 
	mkdir -p $(DIR)
	cd $(DIR) && $(COMP) $(CFLAGS) ../$(SRC)

# $(OBJ): 
# %.rel %.lst %.sym %.asm &: %.c
# 	cd $(DIR) &&	$(GXX) -c $(CFLAGS) $< 
# {lk,lst,map,mem,rel,rst,sym}

clean:
	rm -f $(DIR)/code.{lk,lst,map,mem,rel,rst,sym}

cleanall:
	rm -rf $(DIR)
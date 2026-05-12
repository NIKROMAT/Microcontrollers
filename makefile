COMP = gcc
SRC = code.c
# OBJ = code
CFLAGS = 
TARGET = code
# DIR = ./code


.PHONY: all run clean cleanall

all: comp clean 

# run: comp
# 	cd $(DIR) &&	./$(TARGET)

comp: $(SRC)
	$(COMP) $^ -o $(TARGET)
# 	cd $(DIR) &&	$(COMP) $^ -o $(TARGET)

# $(OBJ): 
# %.rel %.lst %.sym %.asm &: %.c
# 	cd $(DIR) &&	$(GXX) -c $(CFLAGS) $< 

# cleanall: clean
# 	rm -f $(filter-out $(DIR)/code.c, $(wildcard $(DIR)/code.*))
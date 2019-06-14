
###################################
###	STATIC PATHS VARIABLES
###################################

SOURCE_DIR=src
BUILD_DIR=build
EXECUTABLE_NAME=laba3

###################################
###	COMPILER FLAGS
###################################

CC=nasm
LD=gcc
CFLAGS=-f elf -g
LDFLAGS=-m32 -nostartfiles


###################################
###	SOURCES TO COMPILE
###################################

rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

SOURCES=$(patsubst $(SOURCE_DIR)/%,%, $(call rwildcard, src/, *.asm *.ASM))
OBJECTS=$(addprefix $(BUILD_DIR)/, $(filter %.o, $(SOURCES:.asm=.o) $(SOURCES:.ASM=.o)))
TARGET=$(BUILD_DIR)/$(EXECUTABLE_NAME)



###################################
###	MAKEFILE RULES
###################################


.PHONY: all, clean, run
all: $(TARGET)

clean:
	@rm -rf $(BUILD_DIR)
	


$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.asm
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $< -o $@

$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(LD) $(LDFLAGS) $^ -o $@


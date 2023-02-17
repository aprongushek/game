SHELL := bash
CC = g++

EXEC = game
BIN = ./bin
SRCS_DIR = ./srcs
OBJS_DIR = ./srcs/objs

# flags for linking and compiling
LIBS = -lSDL2.dll -lSDL2_image.dll -lmingw32
LDFLAGS = -L./libs
CPPFLAGS = -I$(SRCS_DIR) -I./includes -g

# getting object and dependencies files
SRCS = $(wildcard $(SRCS_DIR)/*.cpp)
OBJS = $(patsubst $(SRCS_DIR)%.cpp,$(OBJS_DIR)%.o,$(SRCS))
DEPS = $(patsubst %.o,%.d,$(OBJS))

# default target 
# (build project but dont run)
.PHONY: all
all: $(BIN)/$(EXEC)
	@echo $(EXEC) was built successfully

# linking program from object files
$(BIN)/$(EXEC): $(OBJS)
	@mkdir -p $(BIN)
	@echo linking $(EXEC)
	@$(CC) $^ -o $@ $(LDFLAGS) $(LIBS)

# compiling updated source files
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@mkdir -p $(OBJS_DIR)
	@echo compiling $<
	@$(CC) -c -MMD $(CPPFLAGS) $< -o $@

# run program
.PHONY: run
run: all
	@echo running...
	@cd $(BIN) && ./$(EXEC)

# remove executable and object files
.PHONY: clean
clean:
	@rm -rf $(OBJS_DIR)
	@rm -f $(BIN)/$(EXEC)
	@echo cleaning done

# include dependencies
-include $(DEPS)
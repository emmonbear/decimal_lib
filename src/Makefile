
#================================== COMPILER ==================================#
PROJECT_NAME = decimal
CC = gcc
#==============================================================================#


#=============================== DIRECTORY NAMES ==============================#
OBJ_DIR = ./obj
MODULES_DIR = ./modules
TEST_DIR = ./tests
REPORT_DIR = ./report
DVI_DIR = ./../docs
#==============================================================================#

#==================================== FLAGS ===================================#
# MAIN FLAGS FOR COMPILER
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c11 -g

# CHECK LIBRARIES FOR LINKING
LDFLAGS = -lcheck -lsubunit -lm

# CHECK & GCOV LIBRARIES FOR LINKING GCOV
LDGCOV = $(LDFLAGS) -lgcov

# FLAGS FOR COVERING MODULES
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

# FLAGS FOR VALGRING TEST
VAL = --tool=memcheck --leak-check=yes

# FLAGS FOR CPPCHECK TEST
CPPCHECK = --enable=all --suppress=missingIncludeSystem
#==============================================================================#


#================================ TARGET NAMES ================================#
LIBRARY = $(PROJECT_NAME).a
TARGET = test
GCOV = gcov_report
#==============================================================================#


#================================ MAIN HEADER =================================#
MAIN_H = $(shell find ./ -maxdepth 1 -name "*.h")
#==============================================================================#


#====================== LIST OF FILE AND DIRS IN MODULES ======================#
MODULES_DIRS = $(shell find $(MODULES_DIR) -type d)
MODULES_C = $(shell find $(MODULES_DIR) -type f -name "*.c")
MODULES_H = $(shell find $(MODULES_DIR) -type f -name "*.h")
MODULES_O = $(MODULES_C:%.c=%.o)
#==============================================================================#


#==================== LIST OF FILE AND DIRS IN TEST MODULES ===================#
TEST_DIRS = $(shell find $(TEST_DIR) -type d)
TEST_C = $(shell find $(TEST_DIR) -type f -name "*.c")
TEST_H = $(shell find $(TEST_DIR) -type f -name "*.h")
TEST_O = $(TEST_C:%.c=%.o)
#==============================================================================#

#================= LIST OF FILES TO CLANG-FORMAT AND CPPCHECK =================#
C_FILES = $(MODULES_C) $(TEST_C)
H_FILES = $(MODULES_H) $(MAIN_H) $(TEST_H)
ALL_FILES = $(C_FILES) $(H_FILES)
#==============================================================================#


#=============== CONFIGURING PATH TO SEARH FOR UNPREFIXED PATHS ===============#
vpath %.c $(MODULES_DIRS) : $(TEST_DIRS)
vpath %.o $(OBJ_DIR)
#==============================================================================#

#================================= MAIN TARGETS ===============================#
all: $(TARGET) dvi

$(LIBRARY): $(OBJ_DIR) $(MODULES_O) $(MODULES_H) $(MAIN_H)
	ar rcs $@ $(addprefix $(OBJ_DIR)/, $(notdir $(MODULES_O)))
	ranlib $@

$(TARGET): $(LIBRARY) $(TEST_O)
	$(CC) $(addprefix $(OBJ_DIR)/, $(notdir $(TEST_O))) $(LIBRARY) $(LDFLAGS) -o $@
	./$@

$(GCOV): $(OBJ_DIR) $(TEST_O) $(REPORT_DIR)
	$(CC) $(addprefix $(OBJ_DIR)/, $(notdir $(TEST_O))) $(MODULES_C) $(LDFLAGS) $(GCOV_FLAGS) -o $(TARGET)
	./$(TARGET)
	gcovr -r . --html --html-details -o $(REPORT_DIR)/coverage.html
	xdg-open $(REPORT_DIR)/coverage.html

m: $(LIBRARY)
	$(CC) $(CFLAGS) main.c $(LIBRARY) $(LDFLAGS)
	./a.out

dvi:
	rm -rf $(DVI_DIR)
	doxygen Doxyfile
	xdg-open $(DVI_DIR)/html/index.html

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(REPORT_DIR)
	rm -rf $(DVI_DIR)
	rm -rf $(GCOV)
	rm -f $(TARGET)
	rm -f *.a *.o
	rm -f *.gc*
	rm -f main
	rm -f val.txt
	rm -f a.out

rebuild: clean all
#==============================================================================#


#============================== CREATE DIRECTORIES ============================#
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(REPORT_DIR):
	mkdir -p $(REPORT_DIR)
#==============================================================================#


#============================== OBJECTIVE TARGETS =============================#
%.o: %.c $(H_FILES)
	$(CC) $(CFLAGS) -c -o $(addprefix $(OBJ_DIR)/, $(notdir $@)) $<
#==============================================================================#


#=============================== CHECKS TARGETS ===============================#
clang_check:
	clang-format -style=Google -n $(ALL_FILES)

clang_fix:
	clang-format -style=Google -i $(ALL_FILES)

cppcheck:
	$@ $(CPPCHECK) $(MODULES_C) $(MODULES_H)

valgrind: $(TARGET)
	@printf '\033[33m\n                   _            _           _   _            _   _             \n'
	@printf '                  | |          (_)         | | | |          | | (_)            \n'
	@printf '       __   ____ _| | __ _ _ __ _ _ __   __| | | |_ ___  ___| |_ _ _ __   __ _ \n'
	@printf '       \ \ / / _` | |/ _` | '\''__| | '\''_ \ / _` | | __/ _ \/ __| __| | '\''_ \ / _` |\n'
	@printf '        \ V / (_| | | (_| | |  | | | | | (_| | | ||  __/\__ \ |_| | | | | (_| |\n'
	@printf '         \_/ \__,_|_|\__, |_|  |_|_| |_|\__,_|  \__\___||___/\__|_|_| |_|\__, |\n'
	@printf '                      __/ |                                               __/ |\n'
	@printf '                     |___/                                               |___/ \n\033[0m\n'

	@$@ $(VAL) ./$(TARGET) > val.txt 2>&1 && \
	{ \
		printf "\033[33m\n"; \
		printf "########################################################################################\n\n"; \
		printf "                                Valgrind test results:                          \n"; \
		printf "                               Passed tests $$(grep "ERROR SUMMARY: 0" -c val.txt) from $$(grep "ERROR SUMMARY:" -c val.txt)                       \n\n"; \
		printf "########################################################################################\n"; \
		printf "\033[0m\n"; \
	}
#==============================================================================#


#============================= ADDITIONAL TARGETS =============================#
dependencies:
	sudo apt install cppcheck
	sudo apt install clang-format
	sudo apt-get install check
	sudo apt install doxygen
	sudo apt-get install graphviz
	sudo apt-get install texlive
#==============================================================================#

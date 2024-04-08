# Makefile for ProjectBuildv01
# Target executable
TargetApp := ProjectBuildv01.exe

# Compiler
CC := gcc

# Compilation flags
CCFlag := -c
OutFlag := -save-temps

# Directories Assignation
# ->>> std_Headers
std_Headers_IncDIR := std_Headers
# -----------------------------------------------------------------------
# ->>> Support_Libs
Support_Libs_IncDIR := Support_Libs/Inc
Support_Libs_SrcDIR := Support_Libs/Src
# -----------------------------------------------------------------------
#->>> ShapesDesign

ShapesDesign_IncDIR := ShapesDesign
ShapesDesign_SrcDIR := ShapesDesign


# -----------------------------------------------------------------------

# -----------------------------------------------------------------------
# ->>> Build Process Generated Objects
ObjDIR := Build_Process
# -----------------------------------------------------------------------
# ->>> Dependency .i, .s, .o files
DepDIR := Dependency
# -----------------------------------------------------------------------

# wildcard all documents inside the directories
# SrcDs: Source Documents
SrcDs := $(wildcard *.c)
SrcDs += $(wildcard $(Support_Libs_SrcDIR)/*.c)
SrcDs += $(wildcard $(ShapesDesign_SrcDIR)/*.c)

# -----------------------------------------------------------------------
# IncDs: Include Documents
IncDs := $(wildcard *.h) 
IncDs += $(wildcard $(std_Headers_IncDIR)/*.h) 
IncDs += $(wildcard $(Support_Libs_IncDIR)/*.h) 
IncDs += $(wildcard $(ShapesDesign_IncDIR)/*.h) 

# -----------------------------------------------------------------------
# ObjDs: Objects Documents for the Build Process
ObjDs := $(addprefix $(ObjDIR)/, $(patsubst %.c, %.o, $(notdir $(SrcDs))))
# -----------------------------------------------------------------------
# ObjDs: Dependency Documents
DepDs := $(addprefix $(DepDIR)/, $(patsubst %.c, %.o, $(notdir $(SrcDs))))
# -----------------------------------------------------------------------

# Build rules for each source directory
all: build

build: $(ObjDIR) $(TargetApp)

$(TargetApp): $(ObjDs)
	@echo
	@echo -e "\033[43;97m+++\033[0;33m Linking object files:"
	$(CC) $^ -o $@
	@echo -e "\033[0m"

$(ObjDIR)/%.o: %.c $(IncDs)
	@echo -e "\033[42;97m+++\033[0;32m Building file: $(notdir $@)\033[0;35m"
	$(CC) $(CCFlag) $< -o $@
	@echo -n -e "\033[0m"

$(ObjDIR)/%.o: $(Support_Libs_SrcDIR)/%.c $(IncDs)
	@echo -e "\033[42;97m+++\033[0;32m Building file: $(notdir $@)\033[0;35m"
	$(CC) $(CCFlag) $< -o $@
	@echo -n -e "\033[0m"
	
$(ObjDIR)/%.o: $(ShapesDesign_SrcDIR)/%.c $(IncDs)
	@echo -e "\033[42;97m+++\033[0;32m Building file: $(notdir $@)\033[0;35m"
	$(CC) $(CCFlag) $< -o $@
	@echo -n -e "\033[0m"


# Phony targets
.PHONY: build help run clean fast print output tree size

# Generating Dependency Files Rules .i, .s, .o
output: $(DepDs)

$(DepDIR)/%.o: %.c $(IncDs) $(DepDIR)
	$(CC) $(CCFlag) $(OutFlag) -o $@ $<

$(DepDIR)/%.o: $(Support_Libs_SrcDIR)/%.c $(IncDs) $(DepDIR)
	$(CC) $(CCFlag) $(OutFlag) -o $@ $<
$(DepDIR)/%.o: $(ShapesDesign_SrcDIR)/%.c $(IncDs) $(DepDIR)
	$(CC) $(CCFlag) $(OutFlag) -o $@ $<


help:
	@echo -e "\033[0;32mbuild\033[0m:  Create objects and build the application"
	@echo -e "\033[0;32mrun\033[0m:    Run the application"
	@echo -e "\033[0;32mclean\033[0m:  Clean up build process generated files"
	@echo -e "\033[0;32mfast\033[0m:   Build the application directly without generating the .o files"
	@echo -e "\033[0;32mprint\033[0m:  Print project information {compiler name} and source files build overview"
	@echo -e "\033[0;32moutput\033[0m: Generate dependency .i, .s, .o files"
	@echo -e "\033[0;32mtree\033[0m:   Generate a tree view of the project directory"
	@echo -e "\033[0;32msize\033[0m:   Calculate the size of .text, .data, .bss of every the project file"

run: $(TargetApp)
	./$(TargetApp)

clean:
	rm -r -f $(ObjDIR) $(DepDIR) $(TargetApp)

fast:
	$(CC) $(SrcDs) -o $(TargetApp)


# Create directories for objects and dependency files
$(ObjDIR):
	mkdir -p $@
	@echo
	
$(DepDIR):
	mkdir -p $@
	@echo

# Print information
print:
	@echo
	@echo "TargetApp = $(TargetApp)"
	@echo "cCompiler = $(CC)"
	@echo
	@echo "-------------------------------------------------------------------------------------------------------"
	@echo "Build Process Files:"
	@echo "-------------------------------------------------------------------------------------------------------"
	@printf "%-43s %-19s %-19s %-19s\n" "Source" "Intermediate" "Assembly" "Object"
	@echo "-------------------------------------------------------------------------------------------------------"
	@$(foreach file,$(SrcDs), printf "\033[0;31m%-43s \033[0;34m%-19s \033[0;32m%-19s \033[0;33m%-19s\n\033[0m" "$(file)" "$(subst .c,.i,$(notdir $(file)))" "$(subst .c,.s,$(notdir $(file)))" "$(subst .c,.o,$(notdir $(file)))";)
	@echo "-------------------------------------------------------------------------------------------------------"
	@echo

tree:
	tree

tree_files:
	tree /f

# Determine size of .text, .data, .rodata, and .bss sections for each object file and the target executable
size:
	@echo -e "\033[1;32mSize of .text, .data, .rodata, and .bss sections for $(TargetApp):\033[0m"
	@size $(ObjDs) $(TargetApp)
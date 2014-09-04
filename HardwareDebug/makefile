################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf *.lst *.lis *.lpp *.map *.x *.lbp src/*.src src/*.p src/*.pp *.bls *.libelf *.lbk *.abs

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include objects.mk

ifneq ($(strip $(C++_UPPER_DEPS)),)
ALL_DEPS += $(C++_UPPER_DEPS) 
endif
ifneq ($(strip $(C_DEPS)),)
ALL_DEPS += $(C_DEPS) 
endif
ifneq ($(strip $(O_DEPS)),)
ALL_DEPS += $(O_DEPS) 
endif
ifneq ($(strip $(S_DEPS)),)
ALL_DEPS += $(S_DEPS) 
endif
ifneq ($(strip $(ABS_DEPS)),)
ALL_DEPS += $(ABS_DEPS) 
endif
ifneq ($(strip $(CXX_DEPS)),)
ALL_DEPS += $(CXX_DEPS) 
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
ALL_DEPS += $(S_UPPER_DEPS) 
endif
ifneq ($(strip $(C++_DEPS)),)
ALL_DEPS += $(C++_DEPS) 
endif
ifneq ($(strip $(SRC_DEPS)),)
ALL_DEPS += $(SRC_DEPS) 
endif
ifneq ($(strip $(CC_DEPS)),)
ALL_DEPS += $(CC_DEPS) 
endif
ifneq ($(strip $(SRC_UPPER_DEPS)),)
ALL_DEPS += $(SRC_UPPER_DEPS) 
endif
ifneq ($(strip $(CP_DEPS)),)
ALL_DEPS += $(CP_DEPS) 
endif
ifneq ($(strip $(CPP_UPPER_DEPS)),)
ALL_DEPS += $(CPP_UPPER_DEPS) 
endif
ifneq ($(strip $(OBJ_DEPS)),)
ALL_DEPS += $(OBJ_DEPS) 
endif
ifneq ($(strip $(CPP_DEPS)),)
ALL_DEPS += $(CPP_DEPS) 
endif
ifneq ($(strip $(CP_UPPER_DEPS)),)
ALL_DEPS += $(CP_UPPER_DEPS) 
endif
ifneq ($(strip $(CC_UPPER_DEPS)),)
ALL_DEPS += $(CC_UPPER_DEPS) 
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
ALL_DEPS += $(C_UPPER_DEPS) 
endif
ifneq ($(strip $(CXX_UPPER_DEPS)),)
ALL_DEPS += $(CXX_UPPER_DEPS) 
endif

ifneq ($(strip $(SRC_UPPER_SRCS)),)
ALL_ASMS += $(SRC_UPPER_SRCS) 
endif
ifneq ($(strip $(SRC_SRCS)),)
ALL_ASMS += $(SRC_SRCS) 
endif
ifneq ($(strip $(S_UPPER_SRCS)),)
ALL_ASMS += $(S_UPPER_SRCS) 
endif
ifneq ($(strip $(S_SRCS)),)
ALL_ASMS += $(S_SRCS) 
endif
-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LINKER_OUTPUT_OUTPUTS += \
Tutorial.abs \

LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS += \
Tutorial.lib \


# All Target
all: Tutorial.mot
	@echo 'Build complete.'

# Tool invocations
Tutorial.mot: $(LINKER_OUTPUT_OUTPUTS)
	@echo 'Invoking: Converter'
	optlnk   "C:\Users\220038362\My Documents\e2studio\workspace\Tutorial\HardwareDebug\Tutorial.abs" -form=stype  -output="C:\Users\220038362\My Documents\e2studio\workspace\Tutorial\HardwareDebug\Tutorial.mot"
	@echo 'Finished building target:'
	@echo.
	$(MAKE) --no-print-directory post-build

Tutorial.abs: $(OBJS) $(LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS) $(ALL_DEPS) $(ALL_ASMS)
	@echo 'Invoking: Linker'
	@echo 'Building target:'
	optlnk  -subcommand="C:/Users/220038362/My Documents/e2studio/workspace/Tutorial\HardwareDebug\LinkerSubCommand.tmp"  $(USER_OBJS) $(LIBS) -library="C:\Users\220038~1\DOCUME~1\e2studio\WORKSP~1\Tutorial\HARDWA~2\Tutorial.lib"   -noprelink -list="Tutorial.map" -show -nooptimize -rom=D=R,D_1=R_1,D_2=R_2 -nomessage -nologo -output="C:\Users\220038362\My Documents\e2studio\workspace\Tutorial\HardwareDebug\Tutorial.abs"
	@echo 'Finished building:'
	@echo.

Tutorial.lib:  
	@echo 'Invoking: Standard Library'
	lbgrx -head=runtime,stdio,stdlib,string,new -cpu=rx200 -output="Tutorial.lib"
	@echo 'Finished building:'
	@echo.

# Other Targets
clean:
	-$(RM) $(C++_UPPER_DEPS)$(OBJS)$(C_DEPS)$(O_DEPS)$(S_DEPS)$(ABS_DEPS)$(CONVERTOR_OUTPUT_OUTPUTS)$(CXX_DEPS)$(S_UPPER_DEPS)$(C++_DEPS)$(SRC_DEPS)$(CC_DEPS)$(LINKER_OUTPUT_OUTPUTS)$(SRC_UPPER_DEPS)$(CP_DEPS)$(CPP_UPPER_DEPS)$(LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS)$(OBJ_DEPS)$(CPP_DEPS)$(CP_UPPER_DEPS)$(CC_UPPER_DEPS)$(C_UPPER_DEPS)$(CXX_UPPER_DEPS) Tutorial.mot
	@echo.
	@echo 'Clean complete.'

post-build:
	@echo.
	-C:\Renesas\e2studio\DEBUGC~1\RX\RX_CON~1.EXE Tutorial.abs Tutorial.x
	@echo.
	@echo.

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets

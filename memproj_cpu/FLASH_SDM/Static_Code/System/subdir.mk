################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Static_Code/System/CPU_Init.c" \
"../Static_Code/System/Peripherals_Init.c" \
"../Static_Code/System/Vectors.c" \

C_SRCS += \
../Static_Code/System/CPU_Init.c \
../Static_Code/System/Peripherals_Init.c \
../Static_Code/System/Vectors.c \

OBJS += \
./Static_Code/System/CPU_Init_c.obj \
./Static_Code/System/Peripherals_Init_c.obj \
./Static_Code/System/Vectors_c.obj \

OBJS_QUOTED += \
"./Static_Code/System/CPU_Init_c.obj" \
"./Static_Code/System/Peripherals_Init_c.obj" \
"./Static_Code/System/Vectors_c.obj" \

C_DEPS += \
./Static_Code/System/CPU_Init_c.d \
./Static_Code/System/Peripherals_Init_c.d \
./Static_Code/System/Vectors_c.d \

C_DEPS_QUOTED += \
"./Static_Code/System/CPU_Init_c.d" \
"./Static_Code/System/Peripherals_Init_c.d" \
"./Static_Code/System/Vectors_c.d" \

OBJS_OS_FORMAT += \
./Static_Code/System/CPU_Init_c.obj \
./Static_Code/System/Peripherals_Init_c.obj \
./Static_Code/System/Vectors_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Static_Code/System/CPU_Init_c.obj: ../Static_Code/System/CPU_Init.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: DSC Compiler'
	"$(DSC_ToolsDirEnv)/mwcc56800e" -c @@"Static_Code/System/CPU_Init.args" -o "Static_Code/System/CPU_Init_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Static_Code/System/%.d: ../Static_Code/System/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Static_Code/System/Peripherals_Init_c.obj: ../Static_Code/System/Peripherals_Init.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: DSC Compiler'
	"$(DSC_ToolsDirEnv)/mwcc56800e" -c @@"Static_Code/System/Peripherals_Init.args" -o "Static_Code/System/Peripherals_Init_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Static_Code/System/Vectors_c.obj: ../Static_Code/System/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: DSC Compiler'
	"$(DSC_ToolsDirEnv)/mwcc56800e" -c @@"Static_Code/System/Vectors.args" -o "Static_Code/System/Vectors_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '



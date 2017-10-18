################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/src/Events.c" \
"../Sources/src/main.c" \

C_SRCS += \
../Sources/src/Events.c \
../Sources/src/main.c \

OBJS += \
./Sources/src/Events_c.obj \
./Sources/src/main_c.obj \

OBJS_QUOTED += \
"./Sources/src/Events_c.obj" \
"./Sources/src/main_c.obj" \

C_DEPS += \
./Sources/src/Events_c.d \
./Sources/src/main_c.d \

C_DEPS_QUOTED += \
"./Sources/src/Events_c.d" \
"./Sources/src/main_c.d" \

OBJS_OS_FORMAT += \
./Sources/src/Events_c.obj \
./Sources/src/main_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/src/Events_c.obj: ../Sources/src/Events.c
	@echo 'Building file: $<'
	@echo 'Executing target #40 $<'
	@echo 'Invoking: DSC Compiler'
	"$(DSC_ToolsDirEnv)/mwcc56800e" -c @@"Sources/src/Events.args" -o "Sources/src/Events_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/src/%.d: ../Sources/src/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/src/main_c.obj: ../Sources/src/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #41 $<'
	@echo 'Invoking: DSC Compiler'
	"$(DSC_ToolsDirEnv)/mwcc56800e" -c @@"Sources/src/main.args" -o "Sources/src/main_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '



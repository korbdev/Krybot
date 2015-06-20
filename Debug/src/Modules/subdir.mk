################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Modules/Entity.cpp \
../src/Modules/Module.cpp 

OBJS += \
./src/Modules/Entity.o \
./src/Modules/Module.o 

CPP_DEPS += \
./src/Modules/Entity.d \
./src/Modules/Module.d 


# Each subdirectory must supply rules for building sources it contributes
src/Modules/%.o: ../src/Modules/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/home/rkorb/workspace/Krybot/src" -I"/home/rkorb/workspace/Krybot/src/External/JsonCpp" -O0 -g3 -Wall -c -fmessage-length=0 -pthread -std=c++11 -Wl,--no-as-needed -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



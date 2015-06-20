################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Sensors/Hcsr04.cpp \
../src/Sensors/Sonar.cpp 

OBJS += \
./src/Sensors/Hcsr04.o \
./src/Sensors/Sonar.o 

CPP_DEPS += \
./src/Sensors/Hcsr04.d \
./src/Sensors/Sonar.d 


# Each subdirectory must supply rules for building sources it contributes
src/Sensors/%.o: ../src/Sensors/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/home/rkorb/workspace/Krybot/src" -I"/home/rkorb/workspace/Krybot/src/External/JsonCpp" -O0 -g3 -Wall -c -fmessage-length=0 -pthread -std=c++11 -Wl,--no-as-needed -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



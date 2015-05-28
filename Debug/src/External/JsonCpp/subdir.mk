################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/External/JsonCpp/jsoncpp.cpp 

OBJS += \
./src/External/JsonCpp/jsoncpp.o 

CPP_DEPS += \
./src/External/JsonCpp/jsoncpp.d 


# Each subdirectory must supply rules for building sources it contributes
src/External/JsonCpp/%.o: ../src/External/JsonCpp/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/home/rkorb/workspace/Krybot/src" -I"/home/rkorb/workspace/Krybot/src/External/JsonCpp" -O0 -g3 -Wall -c -fmessage-length=0 -pthread -std=c++11 -Wl,--no-as-needed -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



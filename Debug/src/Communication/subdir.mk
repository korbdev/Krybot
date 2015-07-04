################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Communication/Connection.cpp \
../src/Communication/Message.cpp \
../src/Communication/MessageSimulator.cpp \
../src/Communication/Serial.cpp \
../src/Communication/TcpSocket.cpp 

OBJS += \
./src/Communication/Connection.o \
./src/Communication/Message.o \
./src/Communication/MessageSimulator.o \
./src/Communication/Serial.o \
./src/Communication/TcpSocket.o 

CPP_DEPS += \
./src/Communication/Connection.d \
./src/Communication/Message.d \
./src/Communication/MessageSimulator.d \
./src/Communication/Serial.d \
./src/Communication/TcpSocket.d 


# Each subdirectory must supply rules for building sources it contributes
src/Communication/%.o: ../src/Communication/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/home/rkorb/workspace/Krybot/src" -I"/home/rkorb/workspace/Krybot/src/External/JsonCpp" -O0 -g3 -Wall -c -fmessage-length=0 -pthread -std=c++11 -Wl,--no-as-needed -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



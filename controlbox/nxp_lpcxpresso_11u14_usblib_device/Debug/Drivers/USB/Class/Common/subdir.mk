################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/USB/Class/Common/HIDParser.c 

OBJS += \
./Drivers/USB/Class/Common/HIDParser.o 

C_DEPS += \
./Drivers/USB/Class/Common/HIDParser.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/USB/Class/Common/%.o: ../Drivers/USB/Class/Common/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DDEBUG -D__CODE_RED -DCORE_M0 -D__LPC11U1X__ -DUSB_DEVICE_ONLY -I"C:\Users\david_000\Documents\LPCXpresso_7.6.2_326\lpc11u14joystick\controlbox\lpc_chip_11uxx_lib\inc" -I"C:\Users\david_000\Documents\LPCXpresso_7.6.2_326\lpc11u14joystick\controlbox\nxp_lpcxpresso_11u14_board_lib\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



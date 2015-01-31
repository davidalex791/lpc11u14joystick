################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../example/src/adc.c \
../example/src/cr_startup_lpc11xx.c \
../example/src/freertos_blinky.c \
../example/src/hid_desc.c \
../example/src/hid_main.c \
../example/src/hid_mouse.c \
../example/src/keyboard.c \
../example/src/potentiometer.c \
../example/src/sysinit.c 

OBJS += \
./example/src/adc.o \
./example/src/cr_startup_lpc11xx.o \
./example/src/freertos_blinky.o \
./example/src/hid_desc.o \
./example/src/hid_main.o \
./example/src/hid_mouse.o \
./example/src/keyboard.o \
./example/src/potentiometer.o \
./example/src/sysinit.o 

C_DEPS += \
./example/src/adc.d \
./example/src/cr_startup_lpc11xx.d \
./example/src/freertos_blinky.d \
./example/src/hid_desc.d \
./example/src/hid_main.d \
./example/src/hid_mouse.d \
./example/src/keyboard.d \
./example/src/potentiometer.d \
./example/src/sysinit.d 


# Each subdirectory must supply rules for building sources it contributes
example/src/%.o: ../example/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -DCORE_M0 -I"C:\Users\david_000\Documents\LPCXpresso_7.5.0_254\controlbox\ControlBox\example\inc" -I"C:\Users\david_000\Documents\LPCXpresso_7.5.0_254\controlbox\lpc_chip_11uxx_lib\inc\usbd" -I"C:\Users\david_000\Documents\LPCXpresso_7.5.0_254\controlbox\ControlBox\freertos\inc" -I"C:\Users\david_000\Documents\LPCXpresso_7.5.0_254\controlbox\lpc_chip_11uxx_lib\inc" -I"C:\Users\david_000\Documents\LPCXpresso_7.5.0_254\controlbox\nxp_lpcxpresso_11u14_board_lib\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

example/src/cr_startup_lpc11xx.o: ../example/src/cr_startup_lpc11xx.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -DCORE_M0 -I"C:\Users\david_000\Documents\LPCXpresso_7.5.0_254\controlbox\ControlBox\example\inc" -I"C:\Users\david_000\Documents\LPCXpresso_7.5.0_254\controlbox\lpc_chip_11uxx_lib\inc\usbd" -I"C:\Users\david_000\Documents\LPCXpresso_7.5.0_254\controlbox\ControlBox\freertos\inc" -I"C:\Users\david_000\Documents\LPCXpresso_7.5.0_254\controlbox\lpc_chip_11uxx_lib\inc" -I"C:\Users\david_000\Documents\LPCXpresso_7.5.0_254\controlbox\nxp_lpcxpresso_11u14_board_lib\inc" -Os -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"example/src/cr_startup_lpc11xx.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



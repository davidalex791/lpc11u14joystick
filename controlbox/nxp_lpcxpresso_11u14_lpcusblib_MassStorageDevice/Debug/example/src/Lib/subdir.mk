################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../example/src/Lib/DataRam.c \
../example/src/Lib/SCSI.c \
../example/src/Lib/UsbRom.c \
../example/src/Lib/fatutil.c 

OBJS += \
./example/src/Lib/DataRam.o \
./example/src/Lib/SCSI.o \
./example/src/Lib/UsbRom.o \
./example/src/Lib/fatutil.o 

C_DEPS += \
./example/src/Lib/DataRam.d \
./example/src/Lib/SCSI.d \
./example/src/Lib/UsbRom.d \
./example/src/Lib/fatutil.d 


# Each subdirectory must supply rules for building sources it contributes
example/src/Lib/%.o: ../example/src/Lib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -DCORE_M0 -D__LPC11U1X__ -DUSB_DEVICE_ONLY -I"C:\Users\david_000\Documents\LPCXpresso_7.5.0_254\controlbox\nxp_lpcxpresso_11u14_lpcusblib_MassStorageDevice\example\src" -I"C:\Users\david_000\Documents\LPCXpresso_7.5.0_254\controlbox\nxp_lpcxpresso_11u14_lpcusblib_MassStorageDevice\example\src\Lib" -I"C:\Users\david_000\Documents\LPCXpresso_7.5.0_254\controlbox\lpc_chip_11uxx_lib\inc" -I"C:\Users\david_000\Documents\LPCXpresso_7.5.0_254\controlbox\nxp_lpcxpresso_11u14_board_lib\inc" -I"C:\Users\david_000\Documents\LPCXpresso_7.5.0_254\controlbox\nxp_lpcxpresso_11u14_usblib_device\Drivers\USB" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



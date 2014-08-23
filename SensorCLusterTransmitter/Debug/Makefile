################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../Visual\ Micro/


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../MyClass.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
MyClass.o

OBJS_AS_ARGS +=  \
MyClass.o

C_DEPS +=  \
MyClass.d

C_DEPS_AS_ARGS +=  \
MyClass.d

OUTPUT_FILE_PATH +=SensorCLusterTransmitter.elf

OUTPUT_FILE_PATH_AS_ARGS +=SensorCLusterTransmitter.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

# AVR32/GNU C Compiler



./%.o: .././%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 4.8.1
	$(QUOTE)D:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -D__AVR_ATmega8__ -DARDUINO=101 -DARDUINO_MAIN -DF_CPU=16000000L -D__AVR__ -D__cplusplus  -I"D:\Program Files (x86)\Arduino\hardware\MyCustomBoards\avr\cores\arduino" -I"D:\Program Files (x86)\Arduino\hardware\MyCustomBoards\avr\variants\standard" -I"D:\Dropbox\Dropbox\Apps\ArduinoDroid\libraries\VirtualWireTxShrunk" -I"D:\Dropbox\Dropbox\Apps\ArduinoDroid\libraries\VirtualWireTxShrunk\utility" -I"D:\Program Files (x86)\Arduino\hardware\MyCustomBoards\avr\libraries\EEPROM" -I"D:\Program Files (x86)\Arduino\hardware\MyCustomBoards\avr\libraries\EEPROM\utility" -I"D:\Dropbox\Dropbox\Apps\ArduinoDroid\libraries\DHTlib" -I"D:\Dropbox\Dropbox\Apps\ArduinoDroid\libraries\DHTlib\utility" -I"D:\Program Files (x86)\Arduino\libraries" -I"D:\Program Files (x86)\Arduino\hardware\MyCustomBoards\avr\libraries" -I"D:\Program Files (x86)\Visual Micro\Visual Micro for Arduino\Micro Platforms\default\debuggers" -I"D:\Dropbox\Dropbox\Apps\ArduinoDroid\libraries" -I"d:\program files (x86)\arduino\hardware\tools\avr\avr\include" -I"d:\program files (x86)\arduino\hardware\tools\avr\avr\include\avr" -I"d:\program files (x86)\arduino\hardware\tools\avr\avr" -I"d:\program files (x86)\arduino\hardware\tools\avr\lib\gcc\avr\4.3.2\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega8 -c -include=arduino.h -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP)
	@echo Building target: $@
	@echo Invoking: AVR8/GNU Linker : 4.8.1
	$(QUOTE)D:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="SensorCLusterTransmitter.map" -Wl,--start-group -Wl,-lVirtualWireTxShrunk.h -Wl,-ldht.h  -Wl,--end-group -Wl,-L"D:\Dropbox\Dropbox\Apps\ArduinoDroid\Libraries\VirtualWire" -Wl,-L"D:\Copy jacob.k.pagel@gmail.com\Arduino\Arduino Libraries\DHTlib" -Wl,-L"D:\Dropbox\Dropbox\Apps\ArduinoDroid\Libraries\VirtualWireTxShrunk" -Wl,-L"D:\Program Files (x86)\Arduino\libraries\DHTlib" -Wl,-L"D:\Dropbox\Dropbox\Apps\ArduinoDroid\Libraries\DHTlib"  -Wl,--gc-sections -mmcu=atmega8  
	@echo Finished building target: $@
	"D:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "SensorCLusterTransmitter.elf" "SensorCLusterTransmitter.hex"
	"D:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "SensorCLusterTransmitter.elf" "SensorCLusterTransmitter.eep" || exit 0
	"D:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "SensorCLusterTransmitter.elf" > "SensorCLusterTransmitter.lss"
	"D:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "SensorCLusterTransmitter.elf" "SensorCLusterTransmitter.srec"
	"D:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1056\avr8-gnu-toolchain\bin\avr-size.exe" "SensorCLusterTransmitter.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "SensorCLusterTransmitter.elf" "SensorCLusterTransmitter.a" "SensorCLusterTransmitter.hex" "SensorCLusterTransmitter.lss" "SensorCLusterTransmitter.eep" "SensorCLusterTransmitter.map" "SensorCLusterTransmitter.srec" "SensorCLusterTransmitter.usersignatures"
	
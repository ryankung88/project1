################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
..\src/ascii.c \
..\src/flashled.c \
..\src/lcd.c \
..\src/main.c \
..\src/r_cg_cgc.c \
..\src/r_cg_cgc_user.c \
..\src/r_cg_cmt.c \
..\src/r_cg_cmt_user.c \
..\src/r_cg_dbsct.c \
..\src/r_cg_hardware_setup.c \
..\src/r_cg_icu.c \
..\src/r_cg_icu_user.c \
..\src/r_cg_intprg.c \
..\src/r_cg_mtu2.c \
..\src/r_cg_mtu2_user.c \
..\src/r_cg_port.c \
..\src/r_cg_port_user.c \
..\src/r_cg_resetprg.c \
..\src/r_cg_s12adb.c \
..\src/r_cg_s12adb_user.c \
..\src/r_cg_sbrk.c \
..\src/r_cg_sci.c \
..\src/r_cg_sci_user.c \
..\src/r_cg_vecttbl.c \
..\src/utility.c 

OBJS += \
./src/ascii.obj \
./src/flashled.obj \
./src/lcd.obj \
./src/main.obj \
./src/r_cg_cgc.obj \
./src/r_cg_cgc_user.obj \
./src/r_cg_cmt.obj \
./src/r_cg_cmt_user.obj \
./src/r_cg_dbsct.obj \
./src/r_cg_hardware_setup.obj \
./src/r_cg_icu.obj \
./src/r_cg_icu_user.obj \
./src/r_cg_intprg.obj \
./src/r_cg_mtu2.obj \
./src/r_cg_mtu2_user.obj \
./src/r_cg_port.obj \
./src/r_cg_port_user.obj \
./src/r_cg_resetprg.obj \
./src/r_cg_s12adb.obj \
./src/r_cg_s12adb_user.obj \
./src/r_cg_sbrk.obj \
./src/r_cg_sci.obj \
./src/r_cg_sci_user.obj \
./src/r_cg_vecttbl.obj \
./src/utility.obj 

C_DEPS += \
./src/ascii.d \
./src/flashled.d \
./src/lcd.d \
./src/main.d \
./src/r_cg_cgc.d \
./src/r_cg_cgc_user.d \
./src/r_cg_cmt.d \
./src/r_cg_cmt_user.d \
./src/r_cg_dbsct.d \
./src/r_cg_hardware_setup.d \
./src/r_cg_icu.d \
./src/r_cg_icu_user.d \
./src/r_cg_intprg.d \
./src/r_cg_mtu2.d \
./src/r_cg_mtu2_user.d \
./src/r_cg_port.d \
./src/r_cg_port_user.d \
./src/r_cg_resetprg.d \
./src/r_cg_s12adb.d \
./src/r_cg_s12adb_user.d \
./src/r_cg_sbrk.d \
./src/r_cg_sci.d \
./src/r_cg_sci_user.d \
./src/r_cg_vecttbl.d \
./src/utility.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.obj src/%.d: ../src/%.c
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	scandep1 -MM -MP -MF "$(@:%.obj=%.d)" -MT "$(@:%.obj=%.d)"    -I"C:/Users/220038362/My Documents/e2studio/workspace/Tutorial" -I"C:\Renesas\e2studio\Tools\Renesas\RX\1_2_1\include" -D_SYS_INT_TYPES_H -D__RX   -D__RX200=1  -D__LIT=1 -D__NOFPU=1 -D__RON=1 -D__UCHAR=1 -D__DBL4=1 -D__UBIT=1 -D__BITRIGHT=1 -D__DOFF=1 -D__STDC_VERSION__=199409L   -D__RENESAS__=1 -D__RENESAS_VERSION__=0x01020100 -D__RX=1 -D__STDC__=1   -E -quiet -I. -C "$<"
	ccrx -output=obj="$(@:%.d=%.obj)"  -include="C:\Renesas\e2studio\Tools\Renesas\RX\1_2_1\include"  -debug -nologo -change_message=warning -cpu=rx200 -optimize=0  -define=_SYS_INT_TYPES_H,__RX   -lang=c "$<"
	@echo 'Finished scanning and building: $<'
	@echo.


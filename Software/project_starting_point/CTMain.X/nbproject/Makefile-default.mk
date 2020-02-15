#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/CTMain.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/CTMain.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../DisplayEVE.c ../DisplayMCU.c ../I2CLib.c ../main.c ../DisplayAPP.c ../DisplayAPI.c ../potentiometer.c ../motors.c ../accelerometer.c ../temp_humidity.c ../GPS.c ../hardware.c ../screen.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/DisplayEVE.o ${OBJECTDIR}/_ext/1472/DisplayMCU.o ${OBJECTDIR}/_ext/1472/I2CLib.o ${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/1472/DisplayAPP.o ${OBJECTDIR}/_ext/1472/DisplayAPI.o ${OBJECTDIR}/_ext/1472/potentiometer.o ${OBJECTDIR}/_ext/1472/motors.o ${OBJECTDIR}/_ext/1472/accelerometer.o ${OBJECTDIR}/_ext/1472/temp_humidity.o ${OBJECTDIR}/_ext/1472/GPS.o ${OBJECTDIR}/_ext/1472/hardware.o ${OBJECTDIR}/_ext/1472/screen.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/DisplayEVE.o.d ${OBJECTDIR}/_ext/1472/DisplayMCU.o.d ${OBJECTDIR}/_ext/1472/I2CLib.o.d ${OBJECTDIR}/_ext/1472/main.o.d ${OBJECTDIR}/_ext/1472/DisplayAPP.o.d ${OBJECTDIR}/_ext/1472/DisplayAPI.o.d ${OBJECTDIR}/_ext/1472/potentiometer.o.d ${OBJECTDIR}/_ext/1472/motors.o.d ${OBJECTDIR}/_ext/1472/accelerometer.o.d ${OBJECTDIR}/_ext/1472/temp_humidity.o.d ${OBJECTDIR}/_ext/1472/GPS.o.d ${OBJECTDIR}/_ext/1472/hardware.o.d ${OBJECTDIR}/_ext/1472/screen.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/DisplayEVE.o ${OBJECTDIR}/_ext/1472/DisplayMCU.o ${OBJECTDIR}/_ext/1472/I2CLib.o ${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/1472/DisplayAPP.o ${OBJECTDIR}/_ext/1472/DisplayAPI.o ${OBJECTDIR}/_ext/1472/potentiometer.o ${OBJECTDIR}/_ext/1472/motors.o ${OBJECTDIR}/_ext/1472/accelerometer.o ${OBJECTDIR}/_ext/1472/temp_humidity.o ${OBJECTDIR}/_ext/1472/GPS.o ${OBJECTDIR}/_ext/1472/hardware.o ${OBJECTDIR}/_ext/1472/screen.o

# Source Files
SOURCEFILES=../DisplayEVE.c ../DisplayMCU.c ../I2CLib.c ../main.c ../DisplayAPP.c ../DisplayAPI.c ../potentiometer.c ../motors.c ../accelerometer.c ../temp_humidity.c ../GPS.c ../hardware.c ../screen.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/CTMain.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX795F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/DisplayEVE.o: ../DisplayEVE.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/DisplayEVE.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/DisplayEVE.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/DisplayEVE.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/DisplayEVE.o.d" -o ${OBJECTDIR}/_ext/1472/DisplayEVE.o ../DisplayEVE.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/DisplayMCU.o: ../DisplayMCU.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/DisplayMCU.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/DisplayMCU.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/DisplayMCU.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/DisplayMCU.o.d" -o ${OBJECTDIR}/_ext/1472/DisplayMCU.o ../DisplayMCU.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/I2CLib.o: ../I2CLib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/I2CLib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/I2CLib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/I2CLib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/I2CLib.o.d" -o ${OBJECTDIR}/_ext/1472/I2CLib.o ../I2CLib.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/main.o.d" -o ${OBJECTDIR}/_ext/1472/main.o ../main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/DisplayAPP.o: ../DisplayAPP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/DisplayAPP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/DisplayAPP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/DisplayAPP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/DisplayAPP.o.d" -o ${OBJECTDIR}/_ext/1472/DisplayAPP.o ../DisplayAPP.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/DisplayAPI.o: ../DisplayAPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/DisplayAPI.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/DisplayAPI.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/DisplayAPI.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/DisplayAPI.o.d" -o ${OBJECTDIR}/_ext/1472/DisplayAPI.o ../DisplayAPI.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/potentiometer.o: ../potentiometer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/potentiometer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/potentiometer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/potentiometer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/potentiometer.o.d" -o ${OBJECTDIR}/_ext/1472/potentiometer.o ../potentiometer.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/motors.o: ../motors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/motors.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/motors.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/motors.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/motors.o.d" -o ${OBJECTDIR}/_ext/1472/motors.o ../motors.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/accelerometer.o: ../accelerometer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/accelerometer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/accelerometer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/accelerometer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/accelerometer.o.d" -o ${OBJECTDIR}/_ext/1472/accelerometer.o ../accelerometer.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/temp_humidity.o: ../temp_humidity.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/temp_humidity.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/temp_humidity.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/temp_humidity.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/temp_humidity.o.d" -o ${OBJECTDIR}/_ext/1472/temp_humidity.o ../temp_humidity.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/GPS.o: ../GPS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/GPS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/GPS.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/GPS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/GPS.o.d" -o ${OBJECTDIR}/_ext/1472/GPS.o ../GPS.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/hardware.o: ../hardware.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/hardware.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/hardware.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/hardware.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/hardware.o.d" -o ${OBJECTDIR}/_ext/1472/hardware.o ../hardware.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/screen.o: ../screen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/screen.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/screen.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/screen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/screen.o.d" -o ${OBJECTDIR}/_ext/1472/screen.o ../screen.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/_ext/1472/DisplayEVE.o: ../DisplayEVE.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/DisplayEVE.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/DisplayEVE.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/DisplayEVE.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/DisplayEVE.o.d" -o ${OBJECTDIR}/_ext/1472/DisplayEVE.o ../DisplayEVE.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/DisplayMCU.o: ../DisplayMCU.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/DisplayMCU.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/DisplayMCU.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/DisplayMCU.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/DisplayMCU.o.d" -o ${OBJECTDIR}/_ext/1472/DisplayMCU.o ../DisplayMCU.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/I2CLib.o: ../I2CLib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/I2CLib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/I2CLib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/I2CLib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/I2CLib.o.d" -o ${OBJECTDIR}/_ext/1472/I2CLib.o ../I2CLib.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/main.o.d" -o ${OBJECTDIR}/_ext/1472/main.o ../main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/DisplayAPP.o: ../DisplayAPP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/DisplayAPP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/DisplayAPP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/DisplayAPP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/DisplayAPP.o.d" -o ${OBJECTDIR}/_ext/1472/DisplayAPP.o ../DisplayAPP.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/DisplayAPI.o: ../DisplayAPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/DisplayAPI.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/DisplayAPI.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/DisplayAPI.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/DisplayAPI.o.d" -o ${OBJECTDIR}/_ext/1472/DisplayAPI.o ../DisplayAPI.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/potentiometer.o: ../potentiometer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/potentiometer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/potentiometer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/potentiometer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/potentiometer.o.d" -o ${OBJECTDIR}/_ext/1472/potentiometer.o ../potentiometer.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/motors.o: ../motors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/motors.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/motors.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/motors.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/motors.o.d" -o ${OBJECTDIR}/_ext/1472/motors.o ../motors.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/accelerometer.o: ../accelerometer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/accelerometer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/accelerometer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/accelerometer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/accelerometer.o.d" -o ${OBJECTDIR}/_ext/1472/accelerometer.o ../accelerometer.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/temp_humidity.o: ../temp_humidity.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/temp_humidity.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/temp_humidity.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/temp_humidity.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/temp_humidity.o.d" -o ${OBJECTDIR}/_ext/1472/temp_humidity.o ../temp_humidity.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/GPS.o: ../GPS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/GPS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/GPS.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/GPS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/GPS.o.d" -o ${OBJECTDIR}/_ext/1472/GPS.o ../GPS.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/hardware.o: ../hardware.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/hardware.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/hardware.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/hardware.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/hardware.o.d" -o ${OBJECTDIR}/_ext/1472/hardware.o ../hardware.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1472/screen.o: ../screen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/screen.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/screen.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/screen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/screen.o.d" -o ${OBJECTDIR}/_ext/1472/screen.o ../screen.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/CTMain.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/CTMain.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/CTMain.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/CTMain.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/CTMain.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif

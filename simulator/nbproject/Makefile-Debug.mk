#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Cell.o \
	${OBJECTDIR}/Marker.o \
	${OBJECTDIR}/Program.o \
	${OBJECTDIR}/bug.o \
	${OBJECTDIR}/exception.o \
	${OBJECTDIR}/instruction.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/world.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/CellTest.o \
	${TESTDIR}/tests/MarkerTest.o \
	${TESTDIR}/tests/bugtest.o \
	${TESTDIR}/tests/instrtest.o \
	${TESTDIR}/tests/martialarttest.o \
	${TESTDIR}/tests/programtest.o \
	${TESTDIR}/tests/worldtest.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/simulator

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/simulator: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/simulator ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Cell.o: Cell.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../googletest-master/googletest -I../../googletest-master/googletest/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cell.o Cell.cpp

${OBJECTDIR}/Marker.o: Marker.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../googletest-master/googletest -I../../googletest-master/googletest/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Marker.o Marker.cpp

${OBJECTDIR}/Program.o: Program.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../googletest-master/googletest -I../../googletest-master/googletest/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Program.o Program.cpp

${OBJECTDIR}/bug.o: bug.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../googletest-master/googletest -I../../googletest-master/googletest/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/bug.o bug.cpp

${OBJECTDIR}/exception.o: exception.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../googletest-master/googletest -I../../googletest-master/googletest/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exception.o exception.cpp

${OBJECTDIR}/instruction.o: instruction.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../googletest-master/googletest -I../../googletest-master/googletest/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/instruction.o instruction.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../googletest-master/googletest -I../../googletest-master/googletest/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/world.o: world.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../googletest-master/googletest -I../../googletest-master/googletest/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/world.o world.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:
	cd ../../../../NetBeansProjects/googletest && ${MAKE}  -f Makefile CONF=Debug
	cd ../../../../NetBeansProjects/googletest && ${MAKE}  -f Makefile CONF=Debug

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/CellTest.o ${TESTDIR}/tests/MarkerTest.o ${TESTDIR}/tests/bugtest.o ${TESTDIR}/tests/instrtest.o ${TESTDIR}/tests/martialarttest.o ${TESTDIR}/tests/programtest.o ${TESTDIR}/tests/worldtest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} -pthread  ../../../../NetBeansProjects/googletest/dist/Debug/GNU-Linux/libgoogletest.a ../../../../NetBeansProjects/googletest/dist/Debug/GNU-Linux/libgoogletest.a 


${TESTDIR}/tests/CellTest.o: tests/CellTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../googletest-master/googletest -I../../googletest-master/googletest/include -I../../googletest-master/googletest -I../../googletest-master/googletest/include -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/CellTest.o tests/CellTest.cpp


${TESTDIR}/tests/MarkerTest.o: tests/MarkerTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../googletest-master/googletest -I../../googletest-master/googletest/include -I../../googletest-master/googletest -I../../googletest-master/googletest/include -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/MarkerTest.o tests/MarkerTest.cpp


${TESTDIR}/tests/bugtest.o: tests/bugtest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../googletest-master/googletest -I../../googletest-master/googletest/include -I../../googletest-master/googletest -I../../googletest-master/googletest/include -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/bugtest.o tests/bugtest.cpp


${TESTDIR}/tests/instrtest.o: tests/instrtest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../googletest-master/googletest -I../../googletest-master/googletest/include -I../../googletest-master/googletest -I../../googletest-master/googletest/include -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/instrtest.o tests/instrtest.cpp


${TESTDIR}/tests/martialarttest.o: tests/martialarttest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../googletest-master/googletest -I../../googletest-master/googletest/include -I../../googletest-master/googletest -I../../googletest-master/googletest/include -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/martialarttest.o tests/martialarttest.cpp


${TESTDIR}/tests/programtest.o: tests/programtest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../googletest-master/googletest -I../../googletest-master/googletest/include -I../../googletest-master/googletest -I../../googletest-master/googletest/include -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/programtest.o tests/programtest.cpp


${TESTDIR}/tests/worldtest.o: tests/worldtest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../googletest-master/googletest -I../../googletest-master/googletest/include -I../../googletest-master/googletest -I../../googletest-master/googletest/include -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/worldtest.o tests/worldtest.cpp


${OBJECTDIR}/Cell_nomain.o: ${OBJECTDIR}/Cell.o Cell.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Cell.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../../googletest-master/googletest -I../../googletest-master/googletest/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cell_nomain.o Cell.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Cell.o ${OBJECTDIR}/Cell_nomain.o;\
	fi

${OBJECTDIR}/Marker_nomain.o: ${OBJECTDIR}/Marker.o Marker.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Marker.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../../googletest-master/googletest -I../../googletest-master/googletest/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Marker_nomain.o Marker.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Marker.o ${OBJECTDIR}/Marker_nomain.o;\
	fi

${OBJECTDIR}/Program_nomain.o: ${OBJECTDIR}/Program.o Program.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Program.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../../googletest-master/googletest -I../../googletest-master/googletest/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Program_nomain.o Program.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Program.o ${OBJECTDIR}/Program_nomain.o;\
	fi

${OBJECTDIR}/bug_nomain.o: ${OBJECTDIR}/bug.o bug.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/bug.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../../googletest-master/googletest -I../../googletest-master/googletest/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/bug_nomain.o bug.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/bug.o ${OBJECTDIR}/bug_nomain.o;\
	fi

${OBJECTDIR}/exception_nomain.o: ${OBJECTDIR}/exception.o exception.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/exception.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../../googletest-master/googletest -I../../googletest-master/googletest/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exception_nomain.o exception.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/exception.o ${OBJECTDIR}/exception_nomain.o;\
	fi

${OBJECTDIR}/instruction_nomain.o: ${OBJECTDIR}/instruction.o instruction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/instruction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../../googletest-master/googletest -I../../googletest-master/googletest/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/instruction_nomain.o instruction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/instruction.o ${OBJECTDIR}/instruction_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../../googletest-master/googletest -I../../googletest-master/googletest/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/world_nomain.o: ${OBJECTDIR}/world.o world.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/world.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../../googletest-master/googletest -I../../googletest-master/googletest/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/world_nomain.o world.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/world.o ${OBJECTDIR}/world_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

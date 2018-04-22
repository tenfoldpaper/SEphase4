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
	${OBJECTDIR}/_ext/b6201e23/Bug.o \
	${OBJECTDIR}/_ext/b6201e23/Cell.o \
	${OBJECTDIR}/_ext/b6201e23/Marker.o \
	${OBJECTDIR}/_ext/b6201e23/World.o \
	${OBJECTDIR}/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/newtestclass.o \
	${TESTDIR}/tests/newtestclass1.o \
	${TESTDIR}/tests/newtestclass2.o \
	${TESTDIR}/tests/newtestclass3.o \
	${TESTDIR}/tests/newtestrunner.o \
	${TESTDIR}/tests/newtestrunner1.o \
	${TESTDIR}/tests/newtestrunner2.o \
	${TESTDIR}/tests/newtestrunner3.o

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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/phase2se

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/phase2se: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/phase2se ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/b6201e23/Bug.o: ../../Documents/phase2/Simulator/Bug.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/b6201e23
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/b6201e23/Bug.o ../../Documents/phase2/Simulator/Bug.cpp

${OBJECTDIR}/_ext/b6201e23/Cell.o: ../../Documents/phase2/Simulator/Cell.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/b6201e23
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/b6201e23/Cell.o ../../Documents/phase2/Simulator/Cell.cpp

${OBJECTDIR}/_ext/b6201e23/Marker.o: ../../Documents/phase2/Simulator/Marker.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/b6201e23
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/b6201e23/Marker.o ../../Documents/phase2/Simulator/Marker.cpp

${OBJECTDIR}/_ext/b6201e23/World.o: ../../Documents/phase2/Simulator/World.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/b6201e23
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/b6201e23/World.o ../../Documents/phase2/Simulator/World.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/newtestclass2.o ${TESTDIR}/tests/newtestrunner2.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS}   `cppunit-config --libs`   

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/newtestclass1.o ${TESTDIR}/tests/newtestrunner1.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS}   `cppunit-config --libs`   

${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/newtestclass3.o ${TESTDIR}/tests/newtestrunner3.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS}   `cppunit-config --libs`   

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/newtestclass.o ${TESTDIR}/tests/newtestrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   `cppunit-config --libs`   


${TESTDIR}/tests/newtestclass2.o: tests/newtestclass2.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newtestclass2.o tests/newtestclass2.cpp


${TESTDIR}/tests/newtestrunner2.o: tests/newtestrunner2.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newtestrunner2.o tests/newtestrunner2.cpp


${TESTDIR}/tests/newtestclass1.o: tests/newtestclass1.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newtestclass1.o tests/newtestclass1.cpp


${TESTDIR}/tests/newtestrunner1.o: tests/newtestrunner1.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newtestrunner1.o tests/newtestrunner1.cpp


${TESTDIR}/tests/newtestclass3.o: tests/newtestclass3.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newtestclass3.o tests/newtestclass3.cpp


${TESTDIR}/tests/newtestrunner3.o: tests/newtestrunner3.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newtestrunner3.o tests/newtestrunner3.cpp


${TESTDIR}/tests/newtestclass.o: tests/newtestclass.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newtestclass.o tests/newtestclass.cpp


${TESTDIR}/tests/newtestrunner.o: tests/newtestrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newtestrunner.o tests/newtestrunner.cpp


${OBJECTDIR}/_ext/b6201e23/Bug_nomain.o: ${OBJECTDIR}/_ext/b6201e23/Bug.o ../../Documents/phase2/Simulator/Bug.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/b6201e23
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/b6201e23/Bug.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/b6201e23/Bug_nomain.o ../../Documents/phase2/Simulator/Bug.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/b6201e23/Bug.o ${OBJECTDIR}/_ext/b6201e23/Bug_nomain.o;\
	fi

${OBJECTDIR}/_ext/b6201e23/Cell_nomain.o: ${OBJECTDIR}/_ext/b6201e23/Cell.o ../../Documents/phase2/Simulator/Cell.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/b6201e23
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/b6201e23/Cell.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/b6201e23/Cell_nomain.o ../../Documents/phase2/Simulator/Cell.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/b6201e23/Cell.o ${OBJECTDIR}/_ext/b6201e23/Cell_nomain.o;\
	fi

${OBJECTDIR}/_ext/b6201e23/Marker_nomain.o: ${OBJECTDIR}/_ext/b6201e23/Marker.o ../../Documents/phase2/Simulator/Marker.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/b6201e23
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/b6201e23/Marker.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/b6201e23/Marker_nomain.o ../../Documents/phase2/Simulator/Marker.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/b6201e23/Marker.o ${OBJECTDIR}/_ext/b6201e23/Marker_nomain.o;\
	fi

${OBJECTDIR}/_ext/b6201e23/World_nomain.o: ${OBJECTDIR}/_ext/b6201e23/World.o ../../Documents/phase2/Simulator/World.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/b6201e23
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/b6201e23/World.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/b6201e23/World_nomain.o ../../Documents/phase2/Simulator/World.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/b6201e23/World.o ${OBJECTDIR}/_ext/b6201e23/World_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
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

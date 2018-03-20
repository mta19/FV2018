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
	${OBJECTDIR}/Arena.o \
	${OBJECTDIR}/Arma.o \
	${OBJECTDIR}/Ensamblador.o \
	${OBJECTDIR}/Estado.o \
	${OBJECTDIR}/Nivel.o \
	${OBJECTDIR}/Partida.o \
	${OBJECTDIR}/Personaje.o \
	${OBJECTDIR}/SpawnerMonstruo.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/motor2D.o


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
LDLIBSOPTIONS=-L/usr/lib/gcc/x86_64-pc-linux-gnu /usr/lib/libBox2D.so /usr/lib/libsfml-audio.so /usr/lib/libsfml-graphics.so /usr/lib/libsfml-network.so /usr/lib/libsfml-system.so /usr/lib/libsfml-window.so

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/kittygames

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/kittygames: /usr/lib/libBox2D.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/kittygames: /usr/lib/libsfml-audio.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/kittygames: /usr/lib/libsfml-graphics.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/kittygames: /usr/lib/libsfml-network.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/kittygames: /usr/lib/libsfml-system.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/kittygames: /usr/lib/libsfml-window.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/kittygames: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/kittygames ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Arena.o: Arena.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Arena.o Arena.cpp

${OBJECTDIR}/Arma.o: Arma.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Arma.o Arma.cpp

${OBJECTDIR}/Ensamblador.o: Ensamblador.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Ensamblador.o Ensamblador.cpp

${OBJECTDIR}/Estado.o: Estado.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Estado.o Estado.cpp

${OBJECTDIR}/Nivel.o: Nivel.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Nivel.o Nivel.cpp

${OBJECTDIR}/Partida.o: Partida.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Partida.o Partida.cpp

${OBJECTDIR}/Personaje.o: Personaje.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Personaje.o Personaje.cpp

${OBJECTDIR}/SpawnerMonstruo.o: SpawnerMonstruo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SpawnerMonstruo.o SpawnerMonstruo.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/motor2D.o: motor2D.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/motor2D.o motor2D.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} -r ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsfml-system.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libBox2D.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsfml-network.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsfml-window.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsfml-audio.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsfml-graphics.so
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/kittygames

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

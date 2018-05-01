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
	${OBJECTDIR}/Alien.o \
	${OBJECTDIR}/AlienRojo.o \
	${OBJECTDIR}/Animacion.o \
	${OBJECTDIR}/Bala.o \
	${OBJECTDIR}/BalaEscopeta.o \
	${OBJECTDIR}/BalaM4.o \
	${OBJECTDIR}/BalaPistola.o \
	${OBJECTDIR}/Caja.o \
	${OBJECTDIR}/Collision.o \
	${OBJECTDIR}/Ensamblador.o \
	${OBJECTDIR}/Entidad.o \
	${OBJECTDIR}/Escalera.o \
	${OBJECTDIR}/Escopeta.o \
	${OBJECTDIR}/Estado.o \
	${OBJECTDIR}/EstadoJumping.o \
	${OBJECTDIR}/EstadoMoving.o \
	${OBJECTDIR}/EstadoPersonaje.o \
	${OBJECTDIR}/EstadoStanding.o \
	${OBJECTDIR}/Evento.o \
	${OBJECTDIR}/LanzaCohetes.o \
	${OBJECTDIR}/M4.o \
	${OBJECTDIR}/Menu.o \
	${OBJECTDIR}/Nivel.o \
	${OBJECTDIR}/Opciones.o \
	${OBJECTDIR}/Partida.o \
	${OBJECTDIR}/Personaje.o \
	${OBJECTDIR}/Pistola.o \
	${OBJECTDIR}/Plataforma.o \
	${OBJECTDIR}/SpawnerMonstruo.o \
	${OBJECTDIR}/Sprite2D.o \
	${OBJECTDIR}/Ventana.o \
	${OBJECTDIR}/Weapon.o \
	${OBJECTDIR}/balaLC.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/map.o \
	${OBJECTDIR}/tinyxml2-master/tinyxml2.o


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

${OBJECTDIR}/Alien.o: Alien.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Alien.o Alien.cpp

${OBJECTDIR}/AlienRojo.o: AlienRojo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AlienRojo.o AlienRojo.cpp

${OBJECTDIR}/Animacion.o: Animacion.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Animacion.o Animacion.cpp

${OBJECTDIR}/Bala.o: Bala.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Bala.o Bala.cpp

${OBJECTDIR}/BalaEscopeta.o: BalaEscopeta.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BalaEscopeta.o BalaEscopeta.cpp

${OBJECTDIR}/BalaM4.o: BalaM4.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BalaM4.o BalaM4.cpp

${OBJECTDIR}/BalaPistola.o: BalaPistola.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BalaPistola.o BalaPistola.cpp

${OBJECTDIR}/Caja.o: Caja.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Caja.o Caja.cpp

${OBJECTDIR}/Collision.o: Collision.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Collision.o Collision.cpp

${OBJECTDIR}/Ensamblador.o: Ensamblador.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Ensamblador.o Ensamblador.cpp

${OBJECTDIR}/Entidad.o: Entidad.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Entidad.o Entidad.cpp

${OBJECTDIR}/Escalera.o: Escalera.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Escalera.o Escalera.cpp

${OBJECTDIR}/Escopeta.o: Escopeta.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Escopeta.o Escopeta.cpp

${OBJECTDIR}/Estado.o: Estado.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Estado.o Estado.cpp

${OBJECTDIR}/EstadoJumping.o: EstadoJumping.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EstadoJumping.o EstadoJumping.cpp

${OBJECTDIR}/EstadoMoving.o: EstadoMoving.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EstadoMoving.o EstadoMoving.cpp

${OBJECTDIR}/EstadoPersonaje.o: EstadoPersonaje.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EstadoPersonaje.o EstadoPersonaje.cpp

${OBJECTDIR}/EstadoStanding.o: EstadoStanding.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EstadoStanding.o EstadoStanding.cpp

${OBJECTDIR}/Evento.o: Evento.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Evento.o Evento.cpp

${OBJECTDIR}/LanzaCohetes.o: LanzaCohetes.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LanzaCohetes.o LanzaCohetes.cpp

${OBJECTDIR}/M4.o: M4.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/M4.o M4.cpp

${OBJECTDIR}/Menu.o: Menu.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Menu.o Menu.cpp

${OBJECTDIR}/Nivel.o: Nivel.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Nivel.o Nivel.cpp

${OBJECTDIR}/Opciones.o: Opciones.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Opciones.o Opciones.cpp

${OBJECTDIR}/Partida.o: Partida.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Partida.o Partida.cpp

${OBJECTDIR}/Personaje.o: Personaje.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Personaje.o Personaje.cpp

${OBJECTDIR}/Pistola.o: Pistola.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Pistola.o Pistola.cpp

${OBJECTDIR}/Plataforma.o: Plataforma.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Plataforma.o Plataforma.cpp

${OBJECTDIR}/SpawnerMonstruo.o: SpawnerMonstruo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SpawnerMonstruo.o SpawnerMonstruo.cpp

${OBJECTDIR}/Sprite2D.o: Sprite2D.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sprite2D.o Sprite2D.cpp

${OBJECTDIR}/Ventana.o: Ventana.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Ventana.o Ventana.cpp

${OBJECTDIR}/Weapon.o: Weapon.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Weapon.o Weapon.cpp

${OBJECTDIR}/balaLC.o: balaLC.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/balaLC.o balaLC.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/map.o: map.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/map.o map.cpp

${OBJECTDIR}/tinyxml2-master/tinyxml2.o: tinyxml2-master/tinyxml2.cpp
	${MKDIR} -p ${OBJECTDIR}/tinyxml2-master
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/Box2D -I/usr/include/SFML -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tinyxml2-master/tinyxml2.o tinyxml2-master/tinyxml2.cpp

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

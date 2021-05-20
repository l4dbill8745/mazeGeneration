# Generalized Makefile for any project

PROJ = main
XTRA = cell.cpp grid.cpp
BDIR = bin
IDIR = include
LDIR = lib
SDIR = src
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
EXE = ${BDIR}/${PROJ}
SRCS = $(patsubst %, ${SDIR}/%, ${XTRA})
DEPS = $(patsubst ${SDIR}/%.cpp, ${IDIR}/%.hpp, ${SRCS})
OBJS = $(patsubst %, ${BDIR}/%.o, ${PROJ}) $(patsubst ${SDIR}/%.cpp, ${BDIR}/%.o, $(SRCS))

${EXE}: ${OBJS}
	g++ -g3 $^ -I${IDIR} -o ${EXE} -L${LDIR} ${LIBS}

${BDIR}/%.o: ${SDIR}/%.cpp ${DEPS}
	g++ -g3 -c -o $@ $<

run: ${EXE}
	./${EXE}

clean:
	rm -r ${BDIR}/*
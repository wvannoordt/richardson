CC := g++
LIBFLAGS := -fPIC -shared
OFLAGS := -fPIC -c

OBJ_DIR := ../obj
LIB_DIR := ../lib
SRC_DIR := ../src

LIB := ${LIB_DIR}/librichardson.a
EXE := richexample

SOURCE_FILES := $(wildcard ${SRC_DIR}/*.cpp)
OBJ_FILES := $(patsubst ${SRC_DIR}/%.cpp,$(OBJ_DIR)/%.o,$(SOURCE_FILES))

INCLUDE := -I${SRC_DIR}
LINK := -L${LIB_DIR} -lrichardson

OPTIONS := -DEXPENSE_LEVEL=0
OPTIONS += -DPRECISION=2

main: setup lib
	${CC} ${INCLUDE} ${OPTIONS} main.cc ${LINK} -o ${EXE}

lib: setup ${OBJ_FILES}
	${CC} ${INCLUDE} ${LIBFLAGS} ${OPTIONS} ${OBJ_FILES} -o ${LIB}
	
${OBJ_FILES}: ${OBJ_DIR}/%.o : ${SRC_DIR}/%.cpp
	${CC} ${INCLUDE} ${OFLAGS} ${OPTIONS} $< -o $@	

setup:
	mkdir -p ${OBJ_DIR}
	mkdir -p ${LIB_DIR}

clean:
	-rm -r ${OBJ_DIR}
	-rm -r ${LIB_DIR}
	-rm ${EXE}


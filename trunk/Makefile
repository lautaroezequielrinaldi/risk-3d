###############################################################################
# Autores: Pablo Martìn Viva
#          Carlos Pantelides
#          Analìa Hojman
# Descripciòn: Makefile que permite compilar el proyecto RISK-3D estableciendo
# build targets para compilar los diversos modulos (Client Editor -
# Client Player - Server - Common) y compilar ademas los test unitarios.
###############################################################################
# NOMBRE DE TARGETS A COMPILAR
###############################

# Nombre del ejecutable del cliente
target_client = risk3d-client

# Nombre del ejecutable del editor
target_editor = risk3d-editor

# Nombre del ejecutable del server
target_server = risk3d-server

# Nombre del ejecutable de los test unitarios
target_unit_test = risk3d-unit-test

# DIRECTORIOS DE MODULOS A COMPILAR
####################################
# Directorio del mòdulo cliente
CLIENT_DIR = source/client/player
CLIENT_DIRS = $(shell find $(CLIENT_DIR) -type d -print)

# Directorio del mòdulo editor
EDITOR_DIR = source/client/editor
EDITOR_DIRS = $(shell find $(EDITOR_DIR) -type d -print)

# Directorio del mòdulo common-ui
COMMON_UI_DIR = source/client/common-ui
COMMON_UI_DIRS = $(shell find $(COMMON_UI_DIR) -type d -print)

# Directorio del mòdulo server
SERVER_DIR = source/server
SERVER_DIRS = $(shell find $(SERVER_DIR) -type d -print)

# Directorio del mòdulo common
COMMON_DIR = source/common
COMMON_DIRS = $(shell find $(COMMON_DIR) -type d -print)

# Directorio del mòdulo protocols
PROTOCOLS_DIR = source/protocols
PROTOCOLS_DIRS = $(shell find $(PROTOCOLS_DIR) -type d -print)

# Directorio de mòdulo test unitarios.
UNITTEST_DIR  = test
UNITTEST_DIRS = $(shell find $(UNITTEST_DIR) -type d -print)

# EXTENSIÒN DE FICHEROS A COMPILAR
###################################
FILE_EXTENSION = cpp

# FLAGS DE COMPIACIÒN DE TARGETS A CONSTRUIR
#############################################
# Flags de compilaciòn para modo ANSI
CFLAGS = -Wall -pedantic -pedantic-errors

# Flags de compilaciòn para VALGRIND y DEBUG 
CFLAGS += -ggdb -DDEBUG -fno-inline

# Flags de compilaciòn de C++ igual a las de C
CXXFLAGS += $(CFLAGS)

# Flags de compilaciòn usadas por common
COMMONCFLAGS = $(shell xml2-config --cflags)
 
# Flags de compilacìn usadas por el cliente
CLIENTCFLAGS = $(COMMONCFLAGS)

# Flags de compilaciòn usadas por el editor
EDITORCFLAGS = $(COMMONCFLAGS)

# Flags de compilaciòn usadas por el server
SERVERCFLAGS = $(COMMONCFLAGS)

# Flags de compilaciòn usadas por los test unitarios
UNITTESTCFLAGS = $(COMMONCFLAGS)
UNITTESTCFLAGS += $(CLIENTCFLAGS)
UNITTESTCFLAGS += $(EDITORCFLAGS)
UNITTESTCFLAGS += $(SERVERCFLAGS)

# LIBRERÌAS DE TARGETS A CONSTRUIR
###################################
# Librerias usadas por common
COMMONLIB = $(shell xml2-config --libs)
COMMONLIB += -lpthread

# Librerìas usadas por el cliente
CLIENTLIB = $(COMMONLIB)
CLIENTLIB += $(shell  pkg-config --libs sdl) -lGL -lGLU

# Librerìas usadas por el editor
EDITORLIB = $(COMMONLIB)
EDITORLIB += $(shell  pkg-config --libs sdl) -lGL -lGLU

# Librerìas usadas por el server
SERVERLIB = $(COMMONLIB)

# Librerìas usadas por los test unitarios
UNITTESTLIB = $(COMMONLIB)
UNITTESTLIB += $(CLIENTLIB)
UNITTESTLIB += $(SERVERLIB)
UNITTESTLIB += -lcppunit

# ESTANDARD A USAR
###################
# Estandard C++ 98
CXXSTD = c++98

# ARCHIVOS FUENTE A COMPILAR
#############################
# Directiva para buscar source files en un directorio parametrizado
FIND_SOURCES_DIRECTIVE = $(wildcard $(DIR)/*.$(FILE_EXTENSION))

# Archivos fuente del cliente
CLIENT_SOURCES = $(foreach DIR,$(CLIENT_DIRS),$(FIND_SOURCES_DIRECTIVE))

# Archivos fuente del editor
EDITOR_SOURCES = $(foreach DIR,$(EDITOR_DIRS),$(FIND_SOURCES_DIRECTIVE))

# Archivos fuente de common-ui
COMMON_UI_SOURCES = $(foreach DIR,$(COMMON_UI_DIRS),$(FIND_SOURCES_DIRECTIVE))

# Archivos fuente del server
SERVER_SOURCES = $(foreach DIR,$(SERVER_DIRS),$(FIND_SOURCES_DIRECTIVE))

# Archivos fuentes de common
COMMON_SOURCES = $(foreach DIR, $(COMMON_DIRS),$(FIND_SOURCES_DIRECTIVE))

# Archivos fuentes de protocols
PROTOCOLS_SOURCES = $(foreach DIR,$(PROTOCOLS_DIRS),$(FIND_SOURCES_DIRECTIVE))

# Archivos fuentes de test unitarios
ALL_UNITTEST_SOURCES = $(CLIENT_SOURCES) $(EDITOR_SOURCES) $(SERVER_SOURCES) $(COMMON_SOURCES) $(PROTOCOLS_SOURCES) $(foreach DIR,$(UNITTEST_DIRS),$(FIND_SOURCES_DIRECTIVE))

UNITTEST_SOURCES_AUX1 ?= $(filter-out $(CLIENT_DIR)/main.$(FILE_EXTENSION),$(ALL_UNITTEST_SOURCES))

UNITTEST_SOURCES_AUX2 ?= $(filter-out $(EDITOR_DIR)/main.$(FILE_EXTENSION),$(UNITTEST_SOURCES_AUX1))

UNITTEST_SOURCES ?= $(filter-out $(SERVER_DIR)/main.$(FILE_EXTENSION),$(UNITTEST_SOURCES_AUX2))

# ARCHIVOS OBJETO USADOS PARA CREAR TARGETS
############################################
# Archivos objeto de common
OBJECT_COMMON_FILES = $(patsubst %.$(FILE_EXTENSION),%.o,$(COMMON_SOURCES))

# Archivos objeto de common-ui
OBJECT_COMMON_UI_FILES = $(patsubst %.$(FILE_EXTENSION),%.o,$(COMMON_UI_SOURCES))

# Archivos objeto de protocols
OBJECT_PROTOCOLS_FILES = $(patsubst %.$(FILE_EXTENSION),%.o,$(PROTOCOLS_SOURCES))

# Archivos objeto de client
OBJECT_CLIENT_FILES = $(patsubst %.$(FILE_EXTENSION),%.o,$(CLIENT_SOURCES)) $(OBJECT_COMMON_FILES) $(OBJECT_COMMON_UI_FILES) $(OBJECT_PROTOCOLS_FILES)

# Archivos objeto de editor
OBJECT_EDITOR_FILES = $(patsubst %.$(FILE_EXTENSION),%.o,$(EDITOR_SOURCES)) $(OBJECT_COMMON_FILES) $(OBJECT_COMMON_UI_FILES)

# Archivos objeto de server
OBJECT_SERVER_FILES = $(patsubst %.$(FILE_EXTENSION),%.o,$(SERVER_SOURCES)) $(OBJECT_COMMON_FILES) $(OBJECT_PROTOCOlS_FILES)

# Archivos objeto de unit tests
OBJECT_UNITTEST_FILES = $(patsubst %.$(FILE_EXTENSION),%.o,$(UNITTEST_SOURCES))

# REGLAS DE COMPILACION
########################
.PHONY: all clean

all: CLIENT_TARGET EDITOR_TARGET SERVER_TARGET

CLIENT_TARGET: CXXFLAGS += $(CLIENTCFLAGS)
CLIENT_TARGET: LDFLAGS += $(CLIENTLIB)
CLIENT_TARGET: $(OBJECT_CLIENT_FILES)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECT_CLIENT_FILES) $(LOADLIBS) $(LDLIBS) -o $(CLIENT_DIR)/$(target_client)

EDITOR_TARGET: CXXFLAGS += $(EDITORCFLAGS)
EDITOR_TARGET: LDFLAGS += $(EDITORLIB)
EDITOR_TARGET: $(OBJECT_EDITOR_FILES)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECT_EDITOR_FILES) $(LOADLIBS) $(LDLIBS) -o $(EDITOR_DIR)/$(target_editor)

SERVER_TARGET: CXXFLAGS += $(SERVERCFLAGS)
SERVER_TARGET: LDFLAGS += $(SERVERLIB)
SERVER_TARGET: $(OBJECT_SERVER_FILES)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECT_SERVER_FILES) $(LOADLIBS) $(LDLIBS) -o $(SERVER_DIR)/$(target_server)

clean:

	@$(RM) -fv $(OBJECT_CLIENT_FILES) \
	$(OBJECT_EDITOR_FILES) \
	$(OBJECT_SERVER_FILES) \
	$(OBJECT_UNITTEST_FILES) \
	$(CLIENT_DIR)/$(target_client) \
	$(EDITOR_DIR)/$(target_editor) \
	$(SERVER_DIR)/$(target_server) \
	$(UNITTEST_DIR)/$(target_unit_test)

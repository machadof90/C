# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -I.

# Diretórios
SRC_DIR = funcao
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin

# Arquivos
SRC = $(wildcard $(SRC_DIR)/*/*.c) main.c
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))
TARGET = $(BIN_DIR)/program

# Regras
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJ) -o $@

# Regra para compilar objetos
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)/$(dir $<)
	$(CC) $(CFLAGS) -c $< -o $@

# Executar arquivo principal main.c
run: $(TARGET)
	$(TARGET)

# Limpeza
clean:
	rm -rf $(BUILD_DIR)

# Utilitário para listar os arquivos de origem
list:
	@echo "Sources: $(SRC)"

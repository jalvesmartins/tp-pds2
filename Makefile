# Nome do executável
EXEC = bin/meu_programa

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include
TEST_DIR = tests

# Arquivos de código-fonte (incluindo subpastas)
SRC = $(wildcard $(SRC_DIR)/games/*.cpp) \
      $(wildcard $(SRC_DIR)/player/*.cpp) \
      $(SRC_DIR)/main.cpp \
      $(SRC_DIR)/system_operations.cpp

# Arquivos objetos gerados
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Compilador e flags
CXX = g++
CXXFLAGS = -I$(INCLUDE_DIR)/games -I$(INCLUDE_DIR)/player -I$(INCLUDE_DIR) -std=c++17 -Wall

# Arquivos de teste
TEST_SRC = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ = $(TEST_SRC:$(TEST_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Nome do executável de testes
TEST_EXEC = $(OBJ_DIR)/test_exec

# Diretivas do Makefile
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

# Compilar os arquivos .cpp para .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar arquivos compilados
clean:
	rm -rf $(OBJ_DIR)/*.o $(EXEC) $(TEST_EXEC)
	rm -rf $(OBJ_DIR)/games/*.o $(EXEC) $(TEST_EXEC)
	rm -rf $(OBJ_DIR)/player/*.o $(EXEC) $(TEST_EXEC)

# Instruções para rodar os testes
tests: $(TEST_EXEC)
	./$(TEST_EXEC)

$(TEST_EXEC): $(TEST_OBJ)
	$(CXX) $(TEST_OBJ) -o $(TEST_EXEC)

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -Iinclude
TARGET = program

# Директории
SRCDIR = src
INCDIR = include
BUILDDIR = build

# Исходные файлы
SOURCES = $(SRCDIR)/node.c $(SRCDIR)/deque.c $(SRCDIR)/main.c
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)

# Создаем структуру папок в build
$(shell mkdir -p $(BUILDDIR))

# Основная цель
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

# Правило компиляции .c файлов в .o
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка
clean:
	rm -rf $(BUILDDIR) $(TARGET)

# Запуск программы
run: $(TARGET)
	./$(TARGET)

# Отладочная информация (показывает переменные)
debug:
	@echo "SOURCES: $(SOURCES)"
	@echo "OBJECTS: $(OBJECTS)"

.PHONY: clean run debug
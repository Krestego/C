CC = gcc 
WFLAG = -Wall -Wextra -Werror -std=c11
# Список исходных файлов
SOURCES = ../data_libs/data_io.c ../data_libs/data_stat.c ../data_module/data_process.c ../yet_another_decision_module/decision.c main_executable_module.c
# Список объектных файлов
OBJECTS = $(SOURCES:.c=.o)
IO_PROC_DEC = ../data_libs/data_io.o ../data_module/data_process.o ../yet_another_decision_module/decision.o
MAIN = main_executable_module.o 
STAT_PROC = ../data_libs/data_stat.o ../data_module/data_process.o
IO_DEC = ../data_libs/data_io.o ../yet_another_decision_module/decision.o
# Исполняемый файл
DIRECTORY = ../../build/
EXECUTABLE_3 = Quest_3
EXECUTABLE_5 = Quest_5
EXECUTABLE_6 = Quest_6
# Статическая библиотека
STLIB = data_stat.a
# Удалание
DEL = rm -rf

all: $(SOURCES) $(DIRECTORY)$(EXECUTABLE_3)

$(DIRECTORY)$(EXECUTABLE_3): $(OBJECTS)
	$(CC) $(WFLAG) $(OBJECTS) -o $@

# Создание исполняемого файла со статической библиотекой
build_with_static: data_stat.a $(IO_PROC_DEC) $(MAIN)
	$(CC) $(WFLAG) -L. data_stat.a $(IO_PROC_DEC) $(MAIN) -o $(DIRECTORY)$(EXECUTABLE_5) 
	$(DEL) $(OBJECTS)

# Создание статической библиотеки
data_stat.a: ../data_libs/data_stat.o
	ar r $(STLIB) ../data_libs/data_stat.o

clean:
	$(DEL) $(OBJECTS)
	$(DEL) $(STLIB)
	$(DEL) $(DLIB)
	$(DEL) $(DIRECTORY)$(EXECUTABLE_3)
	$(DEL) $(DIRECTORY)$(EXECUTABLE_5)
	$(DEL) $(DIRECTORY)$(EXECUTABLE_6)
	$(DEL) ../main_executable_module/data_process.o

rebuild:
	make clean
	make

rebuild_stlib:
	make clean
	make build_with_static

rebuild_dlib:
	make clean
	build_with_dynamic


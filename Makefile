#===============================================================================
#
#         File: Makefile
#        Usage: make              (generate executable(s)                    )
#               make clean        (remove objects, executables, prerequisits )
#                                  
#         Memo: $@ : Cible, $< : 1er dep, $^ : Liste des dep
#         Pour lanser une comande shell $(shell <cmd>)
#         Si on veux séparé les includes il faut rajouter ça a la 
#         compilation. INC = -I./include
#===============================================================================


#Compilateur :
CC              = g++

#Options 
# -c : Compile but don't link
# -g : Info de debug
# -Wall : Tous les warning
# -o <outputFile>
CXXFLAGS          = -c -g -Wall -o  #Compilation
LFLAGS          = -g #Liaison

#Executable a construir
EXEC=testPoint

$(shell mkdir -p bin)

all:	$(EXEC)

bin/%.o: src/%.cpp src/%.h
		$(CC) $(CXXFLAGS) $@ $<

bin/%.o: src/%.cpp
		$(CC) $(CXXFLAGS) $@ $<

#Liaison :
testPoint: bin/testPoint.o bin/Point.o bin/Triangle.o bin/Maillage.o
	$(CC) $(LFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -fr bin/ > /dev/null 2>&1
	rm $(EXEC) > /dev/null 2>&1

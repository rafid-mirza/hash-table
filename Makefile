# Rafid Mirza
# rm2jgk
# 10/07/21
# Makefile

CXX=clang++

test: wordPuzzle.o timer.o hashTable.o
	$(CXX) wordPuzzle.o timer.o hashTable.o
	@echo "Done!"
	
hashTable.o: hashTable.cpp hashTable.h
timer.o: timer.cpp timer.h
wordPuzzle.o: wordPuzzle.cpp hashTable.h




.PHONY: clean
clean:
	-rm -f *.o



CC=g++
LD=g++
CC_FLAGS=-g -std=c++11
OBJECTS=  dictionary.o main.o DictEntry.o exception.o housekeeping.o
TEST= test.o DictEntry.o dictionary.o exception.o
OB= kaest_CSCI2421_Assignment5
BINARY=dictionary

all: $(OBJECTS) #docs
	$(LD) -o $(BINARY) $(OBJECTS)

test: $(TEST) test.o
	$(LD) -o test $(TEST) test.o

clean:
	rm -rf $(OBJECTS) $(TEST) $(BINARY) html latex $(OB).zip test test.o def docbook man rtf revsorted.txt

%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

docs:
	doxygen doxygen.cfg

zip:
	zip -r $(OB).zip *.cpp *.h *.txt *.csv *.pdf README makefile
	cp $(OB).zip ~/Desktop/
	cp -f $(OB).zip ~/kaest/CSCI2421/completeZips

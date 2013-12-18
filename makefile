CC =  g++ -std=c++0x

all: TemplateList.h
	$(CC) -c TemplateList.cpp
test: all
	$(CC) -o UnitTest UnitTest.cpp && ./UnitTest
clean:
	rm -rf *.o core && rm -rf *.exe UnitTest
zip:
	zip -r TemplateLinkedList TemplateList.cpp TemplateList.h include UnitTest.cpp makefile README.txt
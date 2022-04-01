CC = g++

TESTERS = printEnergy showEnergy printSeams showSeams resizeDemo

all: picture.o $(TESTERS)

picture.o: picture.h picture.cpp jpgd.cpp jpgd.h
	$(CC) -std=c++11 picture.cpp -c
#$(CC) -std=c++11 -Wno-shadow -Wno-unused-const-variable -Wno-unreachable-code picture.cpp -c

SeamCarver.o: picture.h SeamCarver.h SeamCarver.cpp
	$(CC) -std=c++11 SeamCarver.cpp -c

SCUtility.o: picture.h SeamCarver.h SCUtility.h SCUtility.cpp
	$(CC) -std=c++11 SCUtility.cpp -c

%: %.cpp picture.o picture.h SeamCarver.o SeamCarver.h SCUtility.o SCUtility.h
	$(CC) -std=c++11 $@.cpp picture.o SeamCarver.o SCUtility.o -o $@

clean:
	rm -f picture.o SeamCarver.o SCUtility.o $(TESTERS)

UtPod:	UtPod.o	UTpod_Driver.o	Song.o
	g++	-o	UtPod	UtPod.o	UtPod_Driver.o	Song.o

UtPod.o:	UtPod.cpp
	g++	-c	UtPod.cpp

Song.o:	Song.cpp
	g++	-c	Song.cpp

UTpod_Driver.o:	UtPod_Driver.cpp
	g++	-c	UtPod_Driver.cpp

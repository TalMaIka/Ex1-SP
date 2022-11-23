CC=gcc
FLAGS= -Wall -g
FLAGSD = -Wall -fPIC
AR = ar



all : mains maindloop maindrec loops

mains:  main.o libclassrec.a
	${CC} ${FLAGS} main.c -L. libclassrec.a -o mains

maindloop : main.o libclassloops.so
	${CC} ${FLAGSD} main.c ./libclassloops.so -o maindloop

maindrec : main.o libclassrec.so
	${CC} ${FLAGSD} main.c ./libclassrec.so -o maindrec	

loopd : libclassloops.so
recursived : libclassrec.so
recursives : libclassrec.a
loops : libclassloops.a

libclassloops.a : basicClassification.o advancedClassificationLoop.o
	${AR} -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o

libclassrec.so : basicClassification.o advancedClassificationRecursion.o
	${CC} -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o	

libclassloops.so : basicClassification.o advancedClassificationLoop.o
	${CC} -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o

libclassrec.a : basicClassification.o advancedClassificationRecursion.o
	${AR} -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o

basicClassification.o : basicClassification.c NumClass.h
	${CC} ${FLAGS} -c basicClassification.c

advancedClassificationLoop.o : 	advancedClassificationLoop.c NumClass.h
	${CC} ${FLAGS} -c advancedClassificationLoop.c

advancedClassificationRecursion.o : advancedClassificationRecursion.c NumClass.h
	${CC} ${FLAGS} -c advancedClassificationRecursion.c

main.o : main.c NumClass.h
	${CC} ${FLAGS} -c main.c	

.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maindloop maindrec

hw3 : hw3interface.o hw3database.o
        cc -o hw3 hw3interface.o hw3database.o

hw3interface.o : hw3interface.c hw3interface.h
        cc -c hw3interface.c

hw3database.o : hw3database.c hw3database.h record.h
        cc -c hw3database.c

clean :
        rm hw3 hw3database.o hw3interface.o
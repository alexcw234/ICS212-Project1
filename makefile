project1 : project1interface.o project1database.o
        cc -o project1 project1interface.o project1database.o

project1interface.o : project1interface.c project1interface.h
        cc -c project1interface.c

project1database.o : project1database.c project1database.h record.h
        cc -c project1database.c

clean :
        rm project1 project1database.o project1interface.o

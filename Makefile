# 
#测试状态机、fsmcrater自动生成状态机，测试OK
#

cc = gcc -g


all: cfsm_core.o fsmapp_door.o main.o
	$(cc) cfsm_core.o fsmapp_door.o main.o -o main -g

cfsm_core.o: cfsm_core.c cfsm_core.h
	$(cc) -c cfsm_core.c
fsmapp_door.o:fsmapp_door.c fsmapp_door.h
	$(cc) -c fsmapp_door.c
main.o:main.c fsmapp_door.h
	$(cc) -c main.c 

.PHONY :clean

clean:
	@echo "****clean project*********"
	rm *.o *.exe
	@echo "****clean completed*******"


edit: $(object)
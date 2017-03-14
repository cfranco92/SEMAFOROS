CPPFLAGS=
LDFLAGS=-pthread

all: createSemPosix signalProcessPosix waitProcessPosix deleteSemPosix \
		 crearSemaforoIPC waitProcessIPC signalProcessIPC

createSemPosix: createSemPosix.o
	$(CXX) -o $@ $< ${LDFLAGS}

signalProcessPosix: signalProcessPosix.o
	$(CXX) -o $@ $< ${LDFLAGS}

waitProcessPosix: waitProcessPosix.o
	$(CXX) -o $@ $< ${LDFLAGS}

clean:
	rm -f *.o
	rm -f createSemPosix signalProcessPosix waitProcessPosix deleteSemPosix

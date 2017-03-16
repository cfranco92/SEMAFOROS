/*
 * fichero: waitProcessPosix.cpp
 *
 * compilar: $ g++ -o waitProcessPosix waitProcessPosix.cpp -pthread
 * ejecutar: $ ./waitProcessPosix <nombre>
 */
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <cstdlib>
#include <cerrno>
#include <iostream>

using namespace std;

void usage(const char* progname) {
  cerr << progname << " sem_key " << endl;
  exit(1);
}

int
main(int argc, const char* argv[]) {
  sem_t *sem;

  if (argc != 2) {
    usage(argv[0]);
  }

// APERTURA COMO UN FICHERO --> COMO SE MANEJA EN POSIX
  if ((sem = sem_open(argv[1], 0)) == SEM_FAILED) {
    cerr << "Error: " << errno << endl;
    exit(1);
  }

  cout << "This process is waiting for a signal" << endl;

  sem_wait(sem);

  cout << "signal has been received" << endl;

  sem_close(sem);

  return 0;
}

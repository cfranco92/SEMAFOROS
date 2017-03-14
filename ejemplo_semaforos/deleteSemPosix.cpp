/*
 * fichero: deleteSemPosix.cpp
 *
 * compilar: $ g++ -o deleteSemPosix deleteSemPosix.cpp -pthread
 * ejecutar: $ ./deleteSemPosix <nombre>
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

  if (sem_unlink(argv[1]) == -1) {
    cerr << "Error: " << errno << endl;
  }
  
  return 0;
}

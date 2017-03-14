//CREAR SEMAFOROS
  // $ ./createSemPosix semaforo 

//PARA VER LOS SEMAFOROS CREADOS
  // ls -l /dev/shm/sem.

// SE PUEDEN BORRAR COMO FICHEROS
  //rm /dev/shm/[nombreDelSemaforo]

/*
 * fichero: createSemPosix.cpp
 *
 * compilar: $ g++ -o createSemPosix createSemPosix.cpp -pthread
 * ejecutar: $ ./createSemPosix <nombre>
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

  if ((sem = sem_open(argv[1], O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 0))
      == SEM_FAILED) {
    cerr << "Error: " << errno << endl;
    exit(1);
  }

  sem_close(sem);
  return 0;
}

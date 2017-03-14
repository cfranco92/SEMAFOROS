//ES POSIBLE TENER UN ARREGLO DE SEMÁFOROS

// $ ./crearSemaforoIPC 1968

// $ ipcs -s  --> Obtenemos identificador
// $ ipcs
// Error 17 --> file exists --> ermo (lin)

//BORRAMOS SEMÁFOROS
  // $  ipcrm sem 98304  --> obtenido el identificador

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
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
  key_t keysem;

  if (argc != 2) {
    usage(argv[0]);
  }

  keysem = atoi(argv[1]);
  int sem;

  if ((sem = semget(keysem, 1, IPC_CREAT | IPC_EXCL | 0660 )) == -1) {
    cerr << "Error: " << errno << endl;
    exit(1);
  }

  union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                (Linux-specific) */
  } semval;

  semval.val = 1;

  semctl(sem, 0, SETVAL, semval);

  cout << "Semaforo key: " << keysem << " id: " << sem << endl;
  return 0;
}

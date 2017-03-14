
#include <sys/types.h>
#include <sys/stat.h>
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

  if ((sem = semget(keysem, 0, S_IRUSR | S_IWUSR ))  == -1) {
    cerr << "Error: " << errno << endl;
    exit(1);
  }

  cout << "Ready to send signal" << endl;

  sembuf sembf;

  sembf.sem_num = 0;
  sembf.sem_op = 1;  // -1 Wait

  if ((semop(sem, &sembf, 1)) == -1) {
    cerr << "Error: " << errno << endl;
    exit(1);
  }

  cout << "signal has been sent" << endl;

  return 0;
}

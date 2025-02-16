#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

/* create thread argument struct for thr_func() */
typedef struct _thread_data_t {
  int tid;
  double stuff;
} thread_data_t;
 
/* thread function */
void *thr_func(void *arg) {
  thread_data_t *data = (thread_data_t *)arg;
 
  printf("hello from thr_func, thread id: %d, stuff: %f\n", data->tid, data->stuff);
 
  pthread_exit(NULL);
}
 
int main(int argc, char **argv) {
  pthread_t thr[NUM_THREADS];
  int i, rc;
  /* create a thread_data_t argument array */
  thread_data_t thr_data[NUM_THREADS];
 
  /* create threads */
    thr_data[0].tid   = 0;
    thr_data[0].stuff = 0;
    (void) pthread_create(&thr[0], NULL, thr_func, &thr_data[0]);
    
    thr_data[1].tid   = 1;
    thr_data[1].stuff = 1;
    (void) pthread_create(&thr[1], NULL, thr_func, &thr_data[1]);
    
    thr_data[2].tid   = 2;
    thr_data[2].stuff = 2;
    (void) pthread_create(&thr[2], NULL, thr_func, &thr_data[2]);

  /* block until all threads complete */
    (void) pthread_join(thr[0], NULL);
    (void) pthread_join(thr[1], NULL);
    (void) pthread_join(thr[2], NULL);
    
  return EXIT_SUCCESS;
}

//CSCI4061 P3
//GROUP96
//GUANGYU YAN
//ZIQIAN QIU

#ifndef WEBSERVER_THREAD_POOL_H
#define WEBSERVER_THREAD_POOL_H

#define THREAD_JOB_READY 0
#define THREAD_JOB_RUNNING 1
#define THREAD_JOB_FINISHED 2

typedef struct {
  int id;
  unsigned int jobs_counter;
  int* is_hope_to_exit;
} thread_info;

typedef struct job_s {
  void* (*func)(void* arg, thread_info* info);
  void* job_arg;
  void (*finished_callback)(void* arg);
  void* finished_cb_arg;
  int status;
  int is_auto_destroy;
} job;

// define the thread pool here
typedef struct thread_pool_s {
  // Destructor function here
  void (*destroy)(struct thread_pool_s* self);

  // This function is trying to set default job for threads
  void (*set_default_job)(struct thread_pool_s* self, job* default_job);
  // adding another job to the thread pool
  void (*push_job)(struct thread_pool_s* self, job* new_job);

  // This function is trying to get all the threads number in the pool.
  int (*get_total_thread_num)(struct thread_pool_s* self);
  // This function is trying to get all the working threads in the
  // thread pool
  int (*get_working_thread_num)(struct thread_pool_s* self);

  // add new threads to the thread pool
  void (*add_threads)(struct thread_pool_s* self, int num);
  // move a specific threads from a thread pool
  void (*reduce_threads)(struct thread_pool_s* self, int num);
} thread_pool;

// Initialize a thread pool here
thread_pool* thread_pool_init();

// Create a job here
// the function is intended to do things for work
// and the infor here means the thread infor where arg is a input parameter
// arg is the parameter you want to pass
// is_auto_destroy destroy here determines whether
// we should destroy the job automatically after the job has been done
job* job_create(void* (*func)(void* arg, thread_info* info), void* arg, int is_auto_destroy);

// destroy a job here
void job_destroy(job* finished_job);

#endif //WEBSERVER_THREAD_POOL_H

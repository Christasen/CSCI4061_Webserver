//CSCI4061 P3
//GROUP96
//GUANGYU YAN
//ZIQIAN QIU


#ifndef WEBSERVER_QUEUE_H
#define WEBSERVER_QUEUE_H
// definded a queue struct here
typedef struct queue_s {
  // push the data to the top of the queue
  void (*push)(struct queue_s* self, void* payload);
  // pop the data from the tail of the queue
  void* (*pop)(struct queue_s* self);
  // get the length of the queue
  int (*len)(struct queue_s* self);
  // Destructor
  void (*destroy)(struct queue_s* self);
} queue;

// initialize a queue by having the input length max_len
queue* init_queue(int max_len);

#endif //WEBSERVER_QUEUE_H

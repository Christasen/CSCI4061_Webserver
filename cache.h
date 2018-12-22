//CSCI4061 P3
//GROUP96
//GUANGYU YAN
//ZIQIAN QIU

#ifndef WEBSERVER_CACHE_H
#define WEBSERVER_CACHE_H

// Define a cache struct here to realize the cache part
typedef struct cache_s{
  // Destructor here
  void (*destroy)(struct cache_s* self);

  // According to the key to find data from cache
  // if found, return the input pointer
  // if not found, return NULL
  void* (*get)(struct cache_s* self, void* key);

  // save the data val into cache according to the input key
  void (*push)(struct cache_s* self, void* key, void* val);
} cache;

// cache* cache_lfu_init(unsigned int cache_size, void (*free_func)(void* target), int (*cmp)(void* key1, void* key2));
// Define the LRU cache function here
// the free_func is to free the data memory
// cmp is the comparison function to compare the two keys here.
cache* cache_lru_init(unsigned int cache_size, void (*free_func)(void* target), int (*cmp)(void* key1, void* key2));

#endif //WEBSERVER_CACHE_H

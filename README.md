# CSCI4061 F2018 web_server
* date: 12/10/2018
* name: Guangyu Yan,  Ziqian Qiu

## How to compile and run your program.

### Compile:

    Step 1. make clean

    Step 2. make

### Run:
./web_server <port> <path_to_testing>/testing <num_dispatch> <num_worker> <dynamic_flag> <queue_len> <cache_entries>


## A brief explanation on how your program works.

Our program has been separated into several parts

      Thread pool: thread_pool.c thread_pool.h
      Cache: cache.c cache.h
      Logger: logger.c logger.h
      Queue: queue.c queue.h
      Sever: sever.c

All the parts have been implemented as thread safe.
For the convenience of extension, we use structures and function pointers for
the encapsulation of functions and instances, which is similar to
object-oriented programming (OOP). The details are as follows:

    The structure is defined in the header file. All the fields in the structure are
    function pointers.They are the public functions of the object.The external can
    treat this structure as an interface.Another structure is used in the source file.
    The first field is the interface in the header file, and then the other private
    fields (private member) are extended. The corresponding function in the
    interface is implemented in the source file.In the constructor, we completed
    the application of the structure memory, assign all function pointers,
    assign the corresponding function to the implementation, and completed the
    construction of the implementation structures. Since the implementation function
    cannot get the data of its own instance, all interface methods have a self
    parameter, and you can pass your own instance when you call it, thus accessing
    other members of the class.

Thus, when the program runs, there will

    1. Initialize a queue for the use of saving request

    2. Initialize two threads pool, one for receiving links and requests.
    The other one will corresponding WITH THE requests and take the request from
    the queue. Then it will read resource from cache or disk. Then it will return
    back to the user.

    3. Initialize a cache.

    4. If there is a request about changing the threads number dynamically
    there will be a manager threads to monitoring the current load.

    5. After all the previous steps, the program will start all the threads and
    provide all the services to the user.



## Explanation of caching mechanism used.

In the cache module, two scheduling policies of LRU and LFU are implemented.
We will use different initializing functions to determine which strategy is used
by the cache.

LRU is adopted in server program.

The LRU discards the least recently used items first. This algorithm requires
keeping track of what was used when, which is expensive if one wants to make
sure the algorithm always discards the least recently used item.
Every time a cache-line is used, the age of all other cache-lines changes.



## Explanation of your policy to dynamically change the worker thread pool size.

We have the following policy for dynamically changing worker thread pool size:

A. If the current number of worker threads / total number of threads > 0.8,
that is, 80% of the threads are working, indicating that the load is heavy,
there may be a higher load. The program will double the number of threads

B. If the current number of worker threads / total number of threads < 0.2,
that is, 80% of the threads are idle, the load is lighter. Then we reduce the number
of threads to half of the original. But there will still be have at least 10
threads working.


## Contributions of each team member towards the project development.
We did all the algorithms, coding work, documentation work and
most of our coding and debugging work during our meeting.

* Guangyu Yan

    Guangyu finished the main server program part and contributes ideas of the whole framework algorithms design.

* Ziqian Qiu

    Ziqian finished the structs files and contributes ideas of the whole framework algorithms design.

//CSCI4061 P3
//GROUP96
//GUANGYU YAN
//ZIQIAN QIU

#ifndef WEBSERVER_LOGGER_H
#define WEBSERVER_LOGGER_H

#define LOGGER_DEBUG 0
#define LOGGER_INFO 1
#define LOGGER_WARNING 2
#define LOGGER_ERROR 3

// Initialize logger here
void logger_init(const char* filename);
// Setting the level
void logger_set_level(int level);

// Four output functiond of the logger
void logger_debug(const char* msg, ...);
void logger_info(const char* msg, ...);
void logger_warning(const char* msg, ...);
void logger_error(const char* msg, ...);


#endif //WEBSERVER_LOGGER_H

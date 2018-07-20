//Sentry Public API
#ifndef SENTRYLIB_H_
#define SENTRYLIB_H_
#include "list.h"
struct sentry_dsn {
  long project_id;
  char * hostname;
  char * key;
  long port;
};

struct sentry_client {
  struct sentry_dsn * dsn;  
};

struct sentry_stacktrace {
    list_t * frames;
};

struct sentry_breadcrumbs {
    list_t * crumbs;
};


struct sentry_payload {
  struct sentry_stacktrace * stacktrace;
  struct sentry_breadcrumbs * breadcrumbs;
};


//Client
extern struct sentry_client * sentry_create_client();
extern int sentry_set_dsn(struct sentry_client * c, char * dsn);
extern int sentry_destroy_client(struct sentry_client * c);

//DSN

extern int sentry_destroy_dsn(struct sentry_dsn * d);
extern struct sentry_dsn * sentry_create_dsn();

/*
sentry_client * c;
sentry_payload * sp;
sentry_stacktrace * st;
sentry_stacktrace_frame * frame;

sentry_breadcrumbs * sb;
sentry_crumb *sc;

//Create a Client
sentry_create_client(c);
//Initialize a Payload
sentry_create_payload(sp);

//Set a DSN
sentry_set_dsn(c, "https://b97e9a0427ca49e2872840c857a369ac@sentry.krone.at/2");


//Set Message
sentry_payload_set_message(p, "Error");


//Create a frame
sentry_create_frame(frame);
//Set how many lines should be read around error line
sentry_frame_set_extended_context(5); 

//Specify where error happend
sentry_frame_set_info(frame, "message", "/path/to/file/1.php", 1);

//Add Frame to Stacktrace
sentry_stacktrace_add_frame(st,frame); //copies frame - should be freed afterwards

//Destroy the frame
sentry_destroy_frame(frame);

//Add Stacktrace to the payload
sentry_set_stacktrace(p, st); 


//Init Breadcrumbs
sentry_create_breadcrumbs(sb);
//Init Crumb
sentry_create_crumb(sc);
sentry_crumb_info("Category", "Message", array_of_data);

//Add Crumb to the breadcrumbs - clones crumb
sentry_breadcrumb_add_crumb(sb, sc);
//Destryo it
sentry_destroy_crumb(sc);

//Add Crumbs to the payload

sentry_set_breadcrumbs(p, sb);


//Submit Payload - to the sentry server
sentry_submit(c, p);


//Cleanup and destroy all whats left
sentry_destroy_payload(sp);
sentry_destroy_stacktrace(st);
sentry_destroy_client(c);



*/

extern int demo_func(int a);

#endif


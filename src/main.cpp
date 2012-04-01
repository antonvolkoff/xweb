//
//  main.cpp
//  XWeb
//
//  Created by Anton Volkov on 01.04.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "main.h"

static void ajax_datarefs(struct mg_connection *conn,
                          const struct mg_request_info *request_info) 
{
  if (strcmp(request_info->request_method, "GET") == 0) {
    
    mg_printf(conn, "HTTP/1.1 200 OK\r\n"
              "Content-Type: application/json\r\n\r\n"
              "GET %s", request_info->query_string);
  }
  if (strcmp(request_info->request_method, "POST") == 0) {
    mg_printf(conn, "HTTP/1.1 200 OK\r\n"
              "Content-Type: application/json\r\n\r\n"
              "POST %s", request_info->query_string);
  }
}

static void *callback(enum mg_event event,
                      struct mg_connection *conn,
                      const struct mg_request_info *request_info) 
{
  void *result = (void*)"yes";
  
  if (event == MG_NEW_REQUEST) {
    if (strcmp(request_info->uri, "/api/datarefs") == 0) {
      ajax_datarefs(conn, request_info);
    }
    else {
      return NULL;
    }
  } else {
    return NULL;
  }
  
  return result;
}


PLUGIN_API int XPluginStart(char *name, char *sign, char *desc)
{
  strcpy(name, "XWeb");
  strcpy(sign, "choixer.xweb.server");
  strcpy(desc, "XWeb Plugin v.0.1 by Anton Volkov");
  
  return 1;
}

PLUGIN_API void XPluginStop() {}


PLUGIN_API void XPluginEnable() 
{
  ctx = mg_start(&callback, NULL, options);
}

PLUGIN_API void XPluginDisable() 
{
  mg_stop(ctx);
}

PLUGIN_API void XPluginReceiveMessage(XPLMPluginID id, long msg, void *prm) 
{}

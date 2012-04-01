//
//  main.h
//  XWeb
//
//  Created by Anton Volkov on 01.04.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef XWeb_main_h
#define XWeb_main_h

#include <iostream>
#include <XPLMPlugin.h>
#include <XPLMUtilities.h>
#include "mongoose/mongoose.h"

//
// Variables
///////////////////////////////////////////////////////////////////////////////////////////////////////

struct mg_context *ctx;
const char *options[] = {
  "document_root", "/Users/anton/Documents/X-Plane9/Resources/html",
  "listening_ports", "8080", 
  NULL
};

//
// Prototype
///////////////////////////////////////////////////////////////////////////////////////////////////////

PLUGIN_API int XPluginStart(char *name, char *sign, char *desc);
PLUGIN_API void XPluginStop();
PLUGIN_API void XPluginEnable();
PLUGIN_API void XPluginDisable();
PLUGIN_API void XPluginReceiveMessage(XPLMPluginID id, long msg, void *prm);


#endif

//
//  ApplicationController.h
//  XWeb
//
//  Created by Anton Volkov on 01.04.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef XWeb_ApplicationController_h
#define XWeb_ApplicationController_h

class ApplicationController {
public:
  ApplicationController();
  ~ApplicationController();
  
  void index_method();
  void new_method();
  void show_method();
  void create_method();
  void update_method();
  void delete_method();
};

#endif

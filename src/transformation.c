#include "context.h"
#include "transformation.h"

int _cairo_translate(lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, ContextName, cairo_t *);
    double tx = (double) luaL_checknumber(L, 2);
    double ty = (double) luaL_checknumber(L, 3);
    cairo_translate(cr, tx, ty);
    return 0;
}


int _cairo_scale(lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, ContextName, cairo_t *);
    double sx = (double) luaL_checknumber(L, 2);
    double sy = (double) luaL_checknumber(L, 3);
    cairo_scale(cr, sx, sy);
    return 0;
}

int _cairo_rotate(lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, ContextName, cairo_t *);
    double deg = (double) luaL_checknumber(L, 2);
    cairo_rotate(cr, deg);
    return 0;
}


/*static int _cairo_transform(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_matrix_t *arg2 = (cairo_matrix_t *) 0 ;
  
  SWIG_check_num_args("cairo_transform",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_transform",1,"cairo_t *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("cairo_transform",2,"cairo_matrix_t const *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_transform",1,SWIGTYPE_p__cairo);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p__cairo_matrix,0))){
    SWIG_fail_ptr("cairo_transform",2,SWIGTYPE_p__cairo_matrix);
  }
  
  cairo_transform(arg1,(struct _cairo_matrix const *)arg2);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_set_matrix(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_matrix_t *arg2 = (cairo_matrix_t *) 0 ;
  
  SWIG_check_num_args("cairo_set_matrix",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_set_matrix",1,"cairo_t *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("cairo_set_matrix",2,"cairo_matrix_t const *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_set_matrix",1,SWIGTYPE_p__cairo);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p__cairo_matrix,0))){
    SWIG_fail_ptr("cairo_set_matrix",2,SWIGTYPE_p__cairo_matrix);
  }
  
  cairo_set_matrix(arg1,(struct _cairo_matrix const *)arg2);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_identity_matrix(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  
  SWIG_check_num_args("cairo_identity_matrix",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_identity_matrix",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_identity_matrix",1,SWIGTYPE_p__cairo);
  }
  
  cairo_identity_matrix(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_user_to_device(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  double *arg2 = (double *) 0 ;
  double *arg3 = (double *) 0 ;
  
  SWIG_check_num_args("cairo_user_to_device",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_user_to_device",1,"cairo_t *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("cairo_user_to_device",2,"double *");
  if(!SWIG_isptrtype(L,3)) SWIG_fail_arg("cairo_user_to_device",3,"double *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_user_to_device",1,SWIGTYPE_p__cairo);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_user_to_device",2,SWIGTYPE_p_double);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,3,(void**)&arg3,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_user_to_device",3,SWIGTYPE_p_double);
  }
  
  cairo_user_to_device(arg1,arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_user_to_device_distance(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  double *arg2 = (double *) 0 ;
  double *arg3 = (double *) 0 ;
  
  SWIG_check_num_args("cairo_user_to_device_distance",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_user_to_device_distance",1,"cairo_t *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("cairo_user_to_device_distance",2,"double *");
  if(!SWIG_isptrtype(L,3)) SWIG_fail_arg("cairo_user_to_device_distance",3,"double *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_user_to_device_distance",1,SWIGTYPE_p__cairo);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_user_to_device_distance",2,SWIGTYPE_p_double);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,3,(void**)&arg3,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_user_to_device_distance",3,SWIGTYPE_p_double);
  }
  
  cairo_user_to_device_distance(arg1,arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_device_to_user(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  double *arg2 = (double *) 0 ;
  double *arg3 = (double *) 0 ;
  
  SWIG_check_num_args("cairo_device_to_user",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_device_to_user",1,"cairo_t *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("cairo_device_to_user",2,"double *");
  if(!SWIG_isptrtype(L,3)) SWIG_fail_arg("cairo_device_to_user",3,"double *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_device_to_user",1,SWIGTYPE_p__cairo);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_device_to_user",2,SWIGTYPE_p_double);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,3,(void**)&arg3,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_device_to_user",3,SWIGTYPE_p_double);
  }
  
  cairo_device_to_user(arg1,arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_device_to_user_distance(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  double *arg2 = (double *) 0 ;
  double *arg3 = (double *) 0 ;
  
  SWIG_check_num_args("cairo_device_to_user_distance",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_device_to_user_distance",1,"cairo_t *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("cairo_device_to_user_distance",2,"double *");
  if(!SWIG_isptrtype(L,3)) SWIG_fail_arg("cairo_device_to_user_distance",3,"double *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_device_to_user_distance",1,SWIGTYPE_p__cairo);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_device_to_user_distance",2,SWIGTYPE_p_double);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,3,(void**)&arg3,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_device_to_user_distance",3,SWIGTYPE_p_double);
  }
  
  cairo_device_to_user_distance(arg1,arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_get_matrix(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_matrix_t *arg2 = (cairo_matrix_t *) 0 ;
  
  SWIG_check_num_args("cairo_get_matrix",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_get_matrix",1,"cairo_t *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("cairo_get_matrix",2,"cairo_matrix_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_get_matrix",1,SWIGTYPE_p__cairo);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p__cairo_matrix,0))){
    SWIG_fail_ptr("cairo_get_matrix",2,SWIGTYPE_p__cairo_matrix);
  }
  
  cairo_get_matrix(arg1,arg2);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/

#include <stdio.h>
#include <stdlib.h>

#include <config.h>

#include <cairo.h>
#include "common/common.h"
#include "common/table.h"

#include "context.h"
#include "path.h"

const CommonEnum CairoPath[] = {
    { "Move_to", CAIRO_PATH_MOVE_TO },
    { "Line_to", CAIRO_PATH_LINE_TO },
    { "Curve_to", CAIRO_PATH_CURVE_TO },
    { "Close_path", CAIRO_PATH_CLOSE_PATH },
    { NULL, -1 }
};

/*static int _cairo_copy_path(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_path_t *result = 0 ;
  
  SWIG_check_num_args("cairo_copy_path",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_copy_path",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_copy_path",1,SWIGTYPE_p__cairo);
  }
  
  result = (cairo_path_t *)cairo_copy_path(arg1);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_cairo_path,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_copy_path_flat(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_path_t *result = 0 ;
  
  SWIG_check_num_args("cairo_copy_path_flat",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_copy_path_flat",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_copy_path_flat",1,SWIGTYPE_p__cairo);
  }
  
  result = (cairo_path_t *)cairo_copy_path_flat(arg1);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_cairo_path,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_append_path(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_path_t *arg2 = (cairo_path_t *) 0 ;
  
  SWIG_check_num_args("cairo_append_path",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_append_path",1,"cairo_t *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("cairo_append_path",2,"cairo_path_t const *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_append_path",1,SWIGTYPE_p__cairo);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_cairo_path,0))){
    SWIG_fail_ptr("cairo_append_path",2,SWIGTYPE_p_cairo_path);
  }
  
  cairo_append_path(arg1,(struct cairo_path const *)arg2);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_has_current_point(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_bool_t result;
  
  SWIG_check_num_args("cairo_has_current_point",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_has_current_point",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_has_current_point",1,SWIGTYPE_p__cairo);
  }
  
  result = (cairo_bool_t)cairo_has_current_point(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_get_current_point(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  double *arg2 = (double *) 0 ;
  double *arg3 = (double *) 0 ;
  
  SWIG_check_num_args("cairo_get_current_point",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_get_current_point",1,"cairo_t *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("cairo_get_current_point",2,"double *");
  if(!SWIG_isptrtype(L,3)) SWIG_fail_arg("cairo_get_current_point",3,"double *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_get_current_point",1,SWIGTYPE_p__cairo);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_get_current_point",2,SWIGTYPE_p_double);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,3,(void**)&arg3,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_get_current_point",3,SWIGTYPE_p_double);
  }
  
  cairo_get_current_point(arg1,arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/

/*static int _cairo_new_path(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  
  SWIG_check_num_args("cairo_new_path",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_new_path",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_new_path",1,SWIGTYPE_p__cairo);
  }
  
  cairo_new_path(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*TODO: verison that takes map*/
int _cairo_move_to(lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
    double x = (double) luaL_checknumber(L, 2);
    double y = (double) luaL_checknumber(L, 3);
    cairo_move_to(cr, x, y);
    return commonPush(L, "b", 1);
}


/*static int _cairo_new_sub_path(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  
  SWIG_check_num_args("cairo_new_sub_path",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_new_sub_path",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_new_sub_path",1,SWIGTYPE_p__cairo);
  }
  
  cairo_new_sub_path(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


int _cairo_line_to(lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
    double x = (double) luaL_checknumber(L, 2);
    double y = (double) luaL_checknumber(L, 3);
    cairo_line_to(cr, x, y);
    return commonPush(L, "b", 1);
}


/*static int _cairo_curve_to(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  double arg2 ;
  double arg3 ;
  double arg4 ;
  double arg5 ;
  double arg6 ;
  double arg7 ;
  
  SWIG_check_num_args("cairo_curve_to",7,7)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_curve_to",1,"cairo_t *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("cairo_curve_to",2,"double");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("cairo_curve_to",3,"double");
  if(!lua_isnumber(L,4)) SWIG_fail_arg("cairo_curve_to",4,"double");
  if(!lua_isnumber(L,5)) SWIG_fail_arg("cairo_curve_to",5,"double");
  if(!lua_isnumber(L,6)) SWIG_fail_arg("cairo_curve_to",6,"double");
  if(!lua_isnumber(L,7)) SWIG_fail_arg("cairo_curve_to",7,"double");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_curve_to",1,SWIGTYPE_p__cairo);
  }
  
  arg2 = (double)lua_tonumber(L, 2);
  arg3 = (double)lua_tonumber(L, 3);
  arg4 = (double)lua_tonumber(L, 4);
  arg5 = (double)lua_tonumber(L, 5);
  arg6 = (double)lua_tonumber(L, 6);
  arg7 = (double)lua_tonumber(L, 7);
  cairo_curve_to(arg1,arg2,arg3,arg4,arg5,arg6,arg7);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*TODO: verison that takes map*/
int _cairo_arc(lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
    double xc = (double) luaL_checknumber(L, 2);
    double yc = (double) luaL_checknumber(L, 3);
    double radius = (double) luaL_checknumber(L, 4);
    double angle1 = (double) luaL_checknumber(L, 5);
    double angle2 = (double) luaL_checknumber(L, 6);
    cairo_arc(cr, xc, yc, radius, angle1, angle2);
    return commonPush(L, "b", 1);
}


/*static int _cairo_arc_negative(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  double arg2 ;
  double arg3 ;
  double arg4 ;
  double arg5 ;
  double arg6 ;
  
  SWIG_check_num_args("cairo_arc_negative",6,6)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_arc_negative",1,"cairo_t *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("cairo_arc_negative",2,"double");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("cairo_arc_negative",3,"double");
  if(!lua_isnumber(L,4)) SWIG_fail_arg("cairo_arc_negative",4,"double");
  if(!lua_isnumber(L,5)) SWIG_fail_arg("cairo_arc_negative",5,"double");
  if(!lua_isnumber(L,6)) SWIG_fail_arg("cairo_arc_negative",6,"double");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_arc_negative",1,SWIGTYPE_p__cairo);
  }
  
  arg2 = (double)lua_tonumber(L, 2);
  arg3 = (double)lua_tonumber(L, 3);
  arg4 = (double)lua_tonumber(L, 4);
  arg5 = (double)lua_tonumber(L, 5);
  arg6 = (double)lua_tonumber(L, 6);
  cairo_arc_negative(arg1,arg2,arg3,arg4,arg5,arg6);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_rel_move_to(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  double arg2 ;
  double arg3 ;
  
  SWIG_check_num_args("cairo_rel_move_to",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_rel_move_to",1,"cairo_t *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("cairo_rel_move_to",2,"double");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("cairo_rel_move_to",3,"double");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_rel_move_to",1,SWIGTYPE_p__cairo);
  }
  
  arg2 = (double)lua_tonumber(L, 2);
  arg3 = (double)lua_tonumber(L, 3);
  cairo_rel_move_to(arg1,arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_rel_line_to(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  double arg2 ;
  double arg3 ;
  
  SWIG_check_num_args("cairo_rel_line_to",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_rel_line_to",1,"cairo_t *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("cairo_rel_line_to",2,"double");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("cairo_rel_line_to",3,"double");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_rel_line_to",1,SWIGTYPE_p__cairo);
  }
  
  arg2 = (double)lua_tonumber(L, 2);
  arg3 = (double)lua_tonumber(L, 3);
  cairo_rel_line_to(arg1,arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_rel_curve_to(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  double arg2 ;
  double arg3 ;
  double arg4 ;
  double arg5 ;
  double arg6 ;
  double arg7 ;
  
  SWIG_check_num_args("cairo_rel_curve_to",7,7)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_rel_curve_to",1,"cairo_t *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("cairo_rel_curve_to",2,"double");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("cairo_rel_curve_to",3,"double");
  if(!lua_isnumber(L,4)) SWIG_fail_arg("cairo_rel_curve_to",4,"double");
  if(!lua_isnumber(L,5)) SWIG_fail_arg("cairo_rel_curve_to",5,"double");
  if(!lua_isnumber(L,6)) SWIG_fail_arg("cairo_rel_curve_to",6,"double");
  if(!lua_isnumber(L,7)) SWIG_fail_arg("cairo_rel_curve_to",7,"double");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_rel_curve_to",1,SWIGTYPE_p__cairo);
  }
  
  arg2 = (double)lua_tonumber(L, 2);
  arg3 = (double)lua_tonumber(L, 3);
  arg4 = (double)lua_tonumber(L, 4);
  arg5 = (double)lua_tonumber(L, 5);
  arg6 = (double)lua_tonumber(L, 6);
  arg7 = (double)lua_tonumber(L, 7);
  cairo_rel_curve_to(arg1,arg2,arg3,arg4,arg5,arg6,arg7);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_rectangle(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  double arg2 ;
  double arg3 ;
  double arg4 ;
  double arg5 ;
  
  SWIG_check_num_args("cairo_rectangle",5,5)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_rectangle",1,"cairo_t *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("cairo_rectangle",2,"double");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("cairo_rectangle",3,"double");
  if(!lua_isnumber(L,4)) SWIG_fail_arg("cairo_rectangle",4,"double");
  if(!lua_isnumber(L,5)) SWIG_fail_arg("cairo_rectangle",5,"double");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_rectangle",1,SWIGTYPE_p__cairo);
  }
  
  arg2 = (double)lua_tonumber(L, 2);
  arg3 = (double)lua_tonumber(L, 3);
  arg4 = (double)lua_tonumber(L, 4);
  arg5 = (double)lua_tonumber(L, 5);
  cairo_rectangle(arg1,arg2,arg3,arg4,arg5);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_close_path(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  
  SWIG_check_num_args("cairo_close_path",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_close_path",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_close_path",1,SWIGTYPE_p__cairo);
  }
  
  cairo_close_path(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/

/*static int _cairo_path_extents(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  double *arg2 = (double *) 0 ;
  double *arg3 = (double *) 0 ;
  double *arg4 = (double *) 0 ;
  double *arg5 = (double *) 0 ;
  
  SWIG_check_num_args("cairo_path_extents",5,5)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_path_extents",1,"cairo_t *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("cairo_path_extents",2,"double *");
  if(!SWIG_isptrtype(L,3)) SWIG_fail_arg("cairo_path_extents",3,"double *");
  if(!SWIG_isptrtype(L,4)) SWIG_fail_arg("cairo_path_extents",4,"double *");
  if(!SWIG_isptrtype(L,5)) SWIG_fail_arg("cairo_path_extents",5,"double *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_path_extents",1,SWIGTYPE_p__cairo);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_path_extents",2,SWIGTYPE_p_double);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,3,(void**)&arg3,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_path_extents",3,SWIGTYPE_p_double);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,4,(void**)&arg4,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_path_extents",4,SWIGTYPE_p_double);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,5,(void**)&arg5,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_path_extents",5,SWIGTYPE_p_double);
  }
  
  cairo_path_extents(arg1,arg2,arg3,arg4,arg5);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/

/*static int _cairo_text_path(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  char *arg2 = (char *) 0 ;
  
  SWIG_check_num_args("cairo_text_path",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_text_path",1,"cairo_t *");
  if(!SWIG_lua_isnilstring(L,2)) SWIG_fail_arg("cairo_text_path",2,"char const *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_text_path",1,SWIGTYPE_p__cairo);
  }
  
  arg2 = (char *)lua_tostring(L, 2);
  cairo_text_path(arg1,(char const *)arg2);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_glyph_path(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_glyph_t *arg2 = (cairo_glyph_t *) 0 ;
  int arg3 ;
  
  SWIG_check_num_args("cairo_glyph_path",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_glyph_path",1,"cairo_t *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("cairo_glyph_path",2,"cairo_glyph_t const *");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("cairo_glyph_path",3,"int");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_glyph_path",1,SWIGTYPE_p__cairo);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_cairo_glyph_t,0))){
    SWIG_fail_ptr("cairo_glyph_path",2,SWIGTYPE_p_cairo_glyph_t);
  }
  
  arg3 = (int)lua_tonumber(L, 3);
  cairo_glyph_path(arg1,(cairo_glyph_t const *)arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


static int _cairo_path_destroy(lua_State* L) {
    CommonUserdata *path = commonGetUserdata(L, 1, PathName);
    /*if (path->mustdelete) {*/
    cairo_path_destroy(path->data);
    /*}*/

    return 0;
}

const luaL_Reg PathFunctions[] = {
    { NULL, NULL }
};


static const luaL_Reg methods[] = {
    { NULL, NULL }
};


static const luaL_Reg metamethods[] = {
    { "__gc", _cairo_path_destroy },
    { NULL, NULL }
};


const CommonObject Path = {
    "CairoPath",
    methods,
    metamethods
};

#include <stdio.h>
#include <stdlib.h>

#include <config.h>

#include <cairo.h>
#include "common/common.h"
#include "common/table.h"

#include "context.h"

const CommonEnum CairoAntialias[] = {
    { "Default", CAIRO_ANTIALIAS_DEFAULT },
    { "None", CAIRO_ANTIALIAS_NONE },
    { "Gray", CAIRO_ANTIALIAS_GRAY },
    { "Subpixel", CAIRO_ANTIALIAS_SUBPIXEL },
    { "Fast", CAIRO_ANTIALIAS_FAST },
    { "Good", CAIRO_ANTIALIAS_GOOD },
    { "Best", CAIRO_ANTIALIAS_BEST },
    { NULL, -1 }
};

const CommonEnum CairoFillRule[] = {
    { "Winding", CAIRO_FILL_RULE_WINDING },
    { "Even_odd", CAIRO_FILL_RULE_EVEN_ODD },
    { NULL, -1 }
};
const CommonEnum CairoLineCap[] = {
    { "Butt", CAIRO_LINE_CAP_BUTT },
    { "Round", CAIRO_LINE_CAP_ROUND },
    { "Square", CAIRO_LINE_CAP_SQUARE },
    { NULL, -1 }
};
const CommonEnum CairoLineJoin[] = {
    { "Miter", CAIRO_LINE_JOIN_MITER },
    { "Round", CAIRO_LINE_JOIN_ROUND },
    { "Bevel", CAIRO_LINE_JOIN_BEVEL },
    { NULL, -1 }
};
const CommonEnum CairoOperator[] = {
    { "Clear", CAIRO_OPERATOR_CLEAR },
    { "Source", CAIRO_OPERATOR_SOURCE },
    { "Over", CAIRO_OPERATOR_OVER },
    { "In", CAIRO_OPERATOR_IN },
    { "Out", CAIRO_OPERATOR_OUT },
    { "Atop", CAIRO_OPERATOR_ATOP },
    { "Dest", CAIRO_OPERATOR_DEST },
    { "Dest_over", CAIRO_OPERATOR_DEST_OVER },
    { "Dest_in", CAIRO_OPERATOR_DEST_IN },
    { "Dest_out", CAIRO_OPERATOR_DEST_OUT },
    { "Dest_atop", CAIRO_OPERATOR_DEST_ATOP },
    { "Xor", CAIRO_OPERATOR_XOR },
    { "Add", CAIRO_OPERATOR_ADD },
    { "Saturate", CAIRO_OPERATOR_SATURATE },
    { "Multiply", CAIRO_OPERATOR_MULTIPLY },
    { "Screen", CAIRO_OPERATOR_SCREEN },
    { "Overlay", CAIRO_OPERATOR_OVERLAY },
    { "Darken", CAIRO_OPERATOR_DARKEN },
    { "Lighten", CAIRO_OPERATOR_LIGHTEN },
    { "Color_dodge", CAIRO_OPERATOR_COLOR_DODGE },
    { "Color_burn", CAIRO_OPERATOR_COLOR_BURN },
    { "Hard_light", CAIRO_OPERATOR_HARD_LIGHT },
    { "Soft_light", CAIRO_OPERATOR_SOFT_LIGHT },
    { "Difference", CAIRO_OPERATOR_DIFFERENCE },
    { "Exclusion", CAIRO_OPERATOR_EXCLUSION },
    { "Hsl_hue", CAIRO_OPERATOR_HSL_HUE },
    { "Hsl_saturation", CAIRO_OPERATOR_HSL_SATURATION },
    { "Hsl_color", CAIRO_OPERATOR_HSL_COLOR },
    { "Hsl_luminosity", CAIRO_OPERATOR_HSL_LUMINOSITY },
    { NULL, -1 }
};

/*move to surface*/
/*static int _cairo_create(lua_State* L) {
  int SWIG_arg = 0;
  cairo_surface_t *arg1 = (cairo_surface_t *) 0 ;
  cairo_t *result = 0 ;
  
  SWIG_check_num_args("cairo_create",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_create",1,"cairo_surface_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo_surface,0))){
    SWIG_fail_ptr("cairo_create",1,SWIGTYPE_p__cairo_surface);
  }
  
  result = (cairo_t *)cairo_create(arg1);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p__cairo,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_reference(lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
    cairo_t* result = cairo_reference(cr);
    return commonPush(L, "p", Context.name, result);
}*/


/*static int _cairo_destroy(lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
    cairo_destroy(cr);
    return commonPush(L, "b", 1);
}*/

/*static int _cairo_status(lua_State* L) {*/
  /*int SWIG_arg = 0;*/
  /*cairo_t *arg1 = (cairo_t *) 0 ;*/
  /*cairo_status_t result;*/
  
  /*SWIG_check_num_args("cairo_status",1,1)*/
  /*if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_status",1,"cairo_t *");*/
  
  /*if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){*/
    /*SWIG_fail_ptr("cairo_status",1,SWIGTYPE_p__cairo);*/
  /*}*/
  
  /*result = (cairo_status_t)cairo_status(arg1);*/
  /*lua_pushnumber(L, (lua_Number)(int)(result)); SWIG_arg++;*/
  /*return SWIG_arg;*/
  
  /*if(0) SWIG_fail;*/
  
/*fail:*/
  /*lua_error(L);*/
  /*return SWIG_arg;*/
/*}*/

static int _cairo_save(lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
    cairo_save(cr);
    return commonPush(L, "b", 1);
}


static int _cairo_restore(lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
    cairo_restore(cr);
    return commonPush(L, "b", 1);
}


/*static int _cairo_push_group(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  
  SWIG_check_num_args("cairo_push_group",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_push_group",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_push_group",1,SWIGTYPE_p__cairo);
  }
  
  cairo_push_group(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_push_group_with_content(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_content_t arg2 ;
  
  SWIG_check_num_args("cairo_push_group_with_content",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_push_group_with_content",1,"cairo_t *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("cairo_push_group_with_content",2,"cairo_content_t");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_push_group_with_content",1,SWIGTYPE_p__cairo);
  }
  
  arg2 = (cairo_content_t)(int)lua_tonumber(L, 2);
  cairo_push_group_with_content(arg1,arg2);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_pop_group(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_pattern_t *result = 0 ;
  
  SWIG_check_num_args("cairo_pop_group",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_pop_group",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_pop_group",1,SWIGTYPE_p__cairo);
  }
  
  result = (cairo_pattern_t *)cairo_pop_group(arg1);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p__cairo_pattern,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_pop_group_to_source(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  
  SWIG_check_num_args("cairo_pop_group_to_source",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_pop_group_to_source",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_pop_group_to_source",1,SWIGTYPE_p__cairo);
  }
  
  cairo_pop_group_to_source(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/

/*static int _cairo_get_target(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_surface_t *result = 0 ;
  
  SWIG_check_num_args("cairo_get_target",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_get_target",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_get_target",1,SWIGTYPE_p__cairo);
  }
  
  result = (cairo_surface_t *)cairo_get_target(arg1);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p__cairo_surface,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_get_group_target(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_surface_t *result = 0 ;
  
  SWIG_check_num_args("cairo_get_group_target",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_get_group_target",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_get_group_target",1,SWIGTYPE_p__cairo);
  }
  
  result = (cairo_surface_t *)cairo_get_group_target(arg1);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p__cairo_surface,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/

/*static int _cairo_set_source(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_pattern_t *arg2 = (cairo_pattern_t *) 0 ;
  
  SWIG_check_num_args("cairo_set_source",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_set_source",1,"cairo_t *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("cairo_set_source",2,"cairo_pattern_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_set_source",1,SWIGTYPE_p__cairo);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p__cairo_pattern,0))){
    SWIG_fail_ptr("cairo_set_source",2,SWIGTYPE_p__cairo_pattern);
  }
  
  cairo_set_source(arg1,arg2);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*TODO: version that takes a map*/
static int _cairo_set_source_rgb(lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
    double r = (double) luaL_checknumber(L, 2);
    double g = (double) luaL_checknumber(L, 3);
    double b = (double) luaL_checknumber(L, 4);

    cairo_set_source_rgb(cr, r, g, b);
    return commonPush(L, "b", 1);
}


/*TODO: version that takes a map*/
static int _cairo_set_source_rgba(lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
    double r = (double) luaL_checknumber(L, 2);
    double g = (double) luaL_checknumber(L, 3);
    double b = (double) luaL_checknumber(L, 4);
    double a = (double) luaL_checknumber(L, 5);

    cairo_set_source_rgba(cr, r, g, b, a);
    return commonPush(L, "b", 1);
}


/*static int _cairo_set_source_surface(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_surface_t *arg2 = (cairo_surface_t *) 0 ;
  double arg3 ;
  double arg4 ;
  
  SWIG_check_num_args("cairo_set_source_surface",4,4)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_set_source_surface",1,"cairo_t *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("cairo_set_source_surface",2,"cairo_surface_t *");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("cairo_set_source_surface",3,"double");
  if(!lua_isnumber(L,4)) SWIG_fail_arg("cairo_set_source_surface",4,"double");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_set_source_surface",1,SWIGTYPE_p__cairo);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p__cairo_surface,0))){
    SWIG_fail_ptr("cairo_set_source_surface",2,SWIGTYPE_p__cairo_surface);
  }
  
  arg3 = (double)lua_tonumber(L, 3);
  arg4 = (double)lua_tonumber(L, 4);
  cairo_set_source_surface(arg1,arg2,arg3,arg4);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/

/*static int _cairo_get_source(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_pattern_t *result = 0 ;
  
  SWIG_check_num_args("cairo_get_source",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_get_source",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_get_source",1,SWIGTYPE_p__cairo);
  }
  
  result = (cairo_pattern_t *)cairo_get_source(arg1);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p__cairo_pattern,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_set_antialias(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_antialias_t arg2 ;
  
  SWIG_check_num_args("cairo_set_antialias",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_set_antialias",1,"cairo_t *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("cairo_set_antialias",2,"cairo_antialias_t");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_set_antialias",1,SWIGTYPE_p__cairo);
  }
  
  arg2 = (cairo_antialias_t)(int)lua_tonumber(L, 2);
  cairo_set_antialias(arg1,arg2);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_set_fill_rule(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_fill_rule_t arg2 ;
  
  SWIG_check_num_args("cairo_set_fill_rule",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_set_fill_rule",1,"cairo_t *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("cairo_set_fill_rule",2,"cairo_fill_rule_t");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_set_fill_rule",1,SWIGTYPE_p__cairo);
  }
  
  arg2 = (cairo_fill_rule_t)(int)lua_tonumber(L, 2);
  cairo_set_fill_rule(arg1,arg2);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


static int _cairo_set_line_width(lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
    double width = (double) luaL_checknumber(L, 2);
    cairo_set_line_width(cr, width);
    return commonPush(L, "b", 1);
}


static int _cairo_set_line_cap(lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
    int cap = commonGetEnum(L, 2);
    cairo_set_line_cap(cr, cap);
    return commonPush(L, "b", 1);
}


/*static int _cairo_set_line_join(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_line_join_t arg2 ;
  
  SWIG_check_num_args("cairo_set_line_join",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_set_line_join",1,"cairo_t *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("cairo_set_line_join",2,"cairo_line_join_t");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_set_line_join",1,SWIGTYPE_p__cairo);
  }
  
  arg2 = (cairo_line_join_t)(int)lua_tonumber(L, 2);
  cairo_set_line_join(arg1,arg2);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_set_dash(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  double *arg2 = (double *) 0 ;
  int arg3 ;
  double arg4 ;
  
  SWIG_check_num_args("cairo_set_dash",4,4)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_set_dash",1,"cairo_t *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("cairo_set_dash",2,"double const *");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("cairo_set_dash",3,"int");
  if(!lua_isnumber(L,4)) SWIG_fail_arg("cairo_set_dash",4,"double");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_set_dash",1,SWIGTYPE_p__cairo);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_set_dash",2,SWIGTYPE_p_double);
  }
  
  arg3 = (int)lua_tonumber(L, 3);
  arg4 = (double)lua_tonumber(L, 4);
  cairo_set_dash(arg1,(double const *)arg2,arg3,arg4);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_set_miter_limit(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  double arg2 ;
  
  SWIG_check_num_args("cairo_set_miter_limit",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_set_miter_limit",1,"cairo_t *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("cairo_set_miter_limit",2,"double");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_set_miter_limit",1,SWIGTYPE_p__cairo);
  }
  
  arg2 = (double)lua_tonumber(L, 2);
  cairo_set_miter_limit(arg1,arg2);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/
/*static int _cairo_set_operator(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_operator_t arg2 ;
  
  SWIG_check_num_args("cairo_set_operator",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_set_operator",1,"cairo_t *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("cairo_set_operator",2,"cairo_operator_t");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_set_operator",1,SWIGTYPE_p__cairo);
  }
  
  arg2 = (cairo_operator_t)(int)lua_tonumber(L, 2);
  cairo_set_operator(arg1,arg2);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_set_tolerance(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  double arg2 ;
  
  SWIG_check_num_args("cairo_set_tolerance",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_set_tolerance",1,"cairo_t *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("cairo_set_tolerance",2,"double");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_set_tolerance",1,SWIGTYPE_p__cairo);
  }
  
  arg2 = (double)lua_tonumber(L, 2);
  cairo_set_tolerance(arg1,arg2);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/

/*static int _cairo_set_user_data(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_user_data_key_t *arg2 = (cairo_user_data_key_t *) 0 ;
  void *arg3 = (void *) 0 ;
  cairo_destroy_func_t arg4 = (cairo_destroy_func_t) 0 ;
  cairo_status_t result;
  
  SWIG_check_num_args("cairo_set_user_data",4,4)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_set_user_data",1,"cairo_t *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("cairo_set_user_data",2,"cairo_user_data_key_t const *");
  if(!SWIG_isptrtype(L,3)) SWIG_fail_arg("cairo_set_user_data",3,"void *");
  if(!SWIG_isptrtype(L,4)) SWIG_fail_arg("cairo_set_user_data",4,"cairo_destroy_func_t");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_set_user_data",1,SWIGTYPE_p__cairo);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p__cairo_user_data_key,0))){
    SWIG_fail_ptr("cairo_set_user_data",2,SWIGTYPE_p__cairo_user_data_key);
  }
  
  arg3=(void *)SWIG_MustGetPtr(L,3,0,0,3,"cairo_set_user_data");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,4,(void**)&arg4,SWIGTYPE_p_f_p_void__void,0))){
    SWIG_fail_ptr("cairo_set_user_data",4,SWIGTYPE_p_f_p_void__void);
  }
  
  result = (cairo_status_t)cairo_set_user_data(arg1,(struct _cairo_user_data_key const *)arg2,arg3,arg4);
  lua_pushnumber(L, (lua_Number)(int)(result)); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_get_reference_count(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  unsigned int result;
  
  SWIG_check_num_args("cairo_get_reference_count",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_get_reference_count",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_get_reference_count",1,SWIGTYPE_p__cairo);
  }
  
  result = (unsigned int)cairo_get_reference_count(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_get_user_data(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_user_data_key_t *arg2 = (cairo_user_data_key_t *) 0 ;
  void *result = 0 ;
  
  SWIG_check_num_args("cairo_get_user_data",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_get_user_data",1,"cairo_t *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("cairo_get_user_data",2,"cairo_user_data_key_t const *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_get_user_data",1,SWIGTYPE_p__cairo);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p__cairo_user_data_key,0))){
    SWIG_fail_ptr("cairo_get_user_data",2,SWIGTYPE_p__cairo_user_data_key);
  }
  
  result = (void *)cairo_get_user_data(arg1,(struct _cairo_user_data_key const *)arg2);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p_void,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_get_fill_rule(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_fill_rule_t result;
  
  SWIG_check_num_args("cairo_get_fill_rule",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_get_fill_rule",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_get_fill_rule",1,SWIGTYPE_p__cairo);
  }
  
  result = (cairo_fill_rule_t)cairo_get_fill_rule(arg1);
  lua_pushnumber(L, (lua_Number)(int)(result)); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_get_line_width(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  double result;
  
  SWIG_check_num_args("cairo_get_line_width",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_get_line_width",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_get_line_width",1,SWIGTYPE_p__cairo);
  }
  
  result = (double)cairo_get_line_width(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_get_line_cap(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_line_cap_t result;
  
  SWIG_check_num_args("cairo_get_line_cap",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_get_line_cap",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_get_line_cap",1,SWIGTYPE_p__cairo);
  }
  
  result = (cairo_line_cap_t)cairo_get_line_cap(arg1);
  lua_pushnumber(L, (lua_Number)(int)(result)); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_get_line_join(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_line_join_t result;
  
  SWIG_check_num_args("cairo_get_line_join",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_get_line_join",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_get_line_join",1,SWIGTYPE_p__cairo);
  }
  
  result = (cairo_line_join_t)cairo_get_line_join(arg1);
  lua_pushnumber(L, (lua_Number)(int)(result)); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_get_miter_limit(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  double result;
  
  SWIG_check_num_args("cairo_get_miter_limit",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_get_miter_limit",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_get_miter_limit",1,SWIGTYPE_p__cairo);
  }
  
  result = (double)cairo_get_miter_limit(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_get_dash_count(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  int result;
  
  SWIG_check_num_args("cairo_get_dash_count",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_get_dash_count",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_get_dash_count",1,SWIGTYPE_p__cairo);
  }
  
  result = (int)cairo_get_dash_count(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_get_dash(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  double *arg2 = (double *) 0 ;
  double *arg3 = (double *) 0 ;
  
  SWIG_check_num_args("cairo_get_dash",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_get_dash",1,"cairo_t *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("cairo_get_dash",2,"double *");
  if(!SWIG_isptrtype(L,3)) SWIG_fail_arg("cairo_get_dash",3,"double *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_get_dash",1,SWIGTYPE_p__cairo);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_get_dash",2,SWIGTYPE_p_double);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,3,(void**)&arg3,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_get_dash",3,SWIGTYPE_p_double);
  }
  
  cairo_get_dash(arg1,arg2,arg3);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/

/*static int _cairo_get_tolerance(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  double result;
  
  SWIG_check_num_args("cairo_get_tolerance",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_get_tolerance",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_get_tolerance",1,SWIGTYPE_p__cairo);
  }
  
  result = (double)cairo_get_tolerance(arg1);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_get_antialias(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_antialias_t result;
  
  SWIG_check_num_args("cairo_get_antialias",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_get_antialias",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_get_antialias",1,SWIGTYPE_p__cairo);
  }
  
  result = (cairo_antialias_t)cairo_get_antialias(arg1);
  lua_pushnumber(L, (lua_Number)(int)(result)); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/

/*static int _cairo_get_operator(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_operator_t result;
  
  SWIG_check_num_args("cairo_get_operator",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_get_operator",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_get_operator",1,SWIGTYPE_p__cairo);
  }
  
  result = (cairo_operator_t)cairo_get_operator(arg1);
  lua_pushnumber(L, (lua_Number)(int)(result)); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/

/*static int _cairo_reset_clip(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  
  SWIG_check_num_args("cairo_reset_clip",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_reset_clip",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_reset_clip",1,SWIGTYPE_p__cairo);
  }
  
  cairo_reset_clip(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_clip(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  
  SWIG_check_num_args("cairo_clip",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_clip",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_clip",1,SWIGTYPE_p__cairo);
  }
  
  cairo_clip(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_clip_preserve(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  
  SWIG_check_num_args("cairo_clip_preserve",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_clip_preserve",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_clip_preserve",1,SWIGTYPE_p__cairo);
  }
  
  cairo_clip_preserve(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_clip_extents(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  double *arg2 = (double *) 0 ;
  double *arg3 = (double *) 0 ;
  double *arg4 = (double *) 0 ;
  double *arg5 = (double *) 0 ;
  
  SWIG_check_num_args("cairo_clip_extents",5,5)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_clip_extents",1,"cairo_t *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("cairo_clip_extents",2,"double *");
  if(!SWIG_isptrtype(L,3)) SWIG_fail_arg("cairo_clip_extents",3,"double *");
  if(!SWIG_isptrtype(L,4)) SWIG_fail_arg("cairo_clip_extents",4,"double *");
  if(!SWIG_isptrtype(L,5)) SWIG_fail_arg("cairo_clip_extents",5,"double *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_clip_extents",1,SWIGTYPE_p__cairo);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_clip_extents",2,SWIGTYPE_p_double);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,3,(void**)&arg3,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_clip_extents",3,SWIGTYPE_p_double);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,4,(void**)&arg4,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_clip_extents",4,SWIGTYPE_p_double);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,5,(void**)&arg5,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_clip_extents",5,SWIGTYPE_p_double);
  }
  
  cairo_clip_extents(arg1,arg2,arg3,arg4,arg5);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/

/*static int _cairo_in_clip(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  double arg2 ;
  double arg3 ;
  cairo_bool_t result;
  
  SWIG_check_num_args("cairo_in_clip",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_in_clip",1,"cairo_t *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("cairo_in_clip",2,"double");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("cairo_in_clip",3,"double");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_in_clip",1,SWIGTYPE_p__cairo);
  }
  
  arg2 = (double)lua_tonumber(L, 2);
  arg3 = (double)lua_tonumber(L, 3);
  result = (cairo_bool_t)cairo_in_clip(arg1,arg2,arg3);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_stroke_extents(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  double *arg2 = (double *) 0 ;
  double *arg3 = (double *) 0 ;
  double *arg4 = (double *) 0 ;
  double *arg5 = (double *) 0 ;
  
  SWIG_check_num_args("cairo_stroke_extents",5,5)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_stroke_extents",1,"cairo_t *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("cairo_stroke_extents",2,"double *");
  if(!SWIG_isptrtype(L,3)) SWIG_fail_arg("cairo_stroke_extents",3,"double *");
  if(!SWIG_isptrtype(L,4)) SWIG_fail_arg("cairo_stroke_extents",4,"double *");
  if(!SWIG_isptrtype(L,5)) SWIG_fail_arg("cairo_stroke_extents",5,"double *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_stroke_extents",1,SWIGTYPE_p__cairo);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_stroke_extents",2,SWIGTYPE_p_double);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,3,(void**)&arg3,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_stroke_extents",3,SWIGTYPE_p_double);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,4,(void**)&arg4,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_stroke_extents",4,SWIGTYPE_p_double);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,5,(void**)&arg5,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_stroke_extents",5,SWIGTYPE_p_double);
  }
  
  cairo_stroke_extents(arg1,arg2,arg3,arg4,arg5);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_fill_extents(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  double *arg2 = (double *) 0 ;
  double *arg3 = (double *) 0 ;
  double *arg4 = (double *) 0 ;
  double *arg5 = (double *) 0 ;
  
  SWIG_check_num_args("cairo_fill_extents",5,5)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_fill_extents",1,"cairo_t *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("cairo_fill_extents",2,"double *");
  if(!SWIG_isptrtype(L,3)) SWIG_fail_arg("cairo_fill_extents",3,"double *");
  if(!SWIG_isptrtype(L,4)) SWIG_fail_arg("cairo_fill_extents",4,"double *");
  if(!SWIG_isptrtype(L,5)) SWIG_fail_arg("cairo_fill_extents",5,"double *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_fill_extents",1,SWIGTYPE_p__cairo);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_fill_extents",2,SWIGTYPE_p_double);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,3,(void**)&arg3,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_fill_extents",3,SWIGTYPE_p_double);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,4,(void**)&arg4,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_fill_extents",4,SWIGTYPE_p_double);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,5,(void**)&arg5,SWIGTYPE_p_double,0))){
    SWIG_fail_ptr("cairo_fill_extents",5,SWIGTYPE_p_double);
  }
  
  cairo_fill_extents(arg1,arg2,arg3,arg4,arg5);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/

/*static int _cairo_in_fill(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  double arg2 ;
  double arg3 ;
  cairo_bool_t result;
  
  SWIG_check_num_args("cairo_in_fill",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_in_fill",1,"cairo_t *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("cairo_in_fill",2,"double");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("cairo_in_fill",3,"double");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_in_fill",1,SWIGTYPE_p__cairo);
  }
  
  arg2 = (double)lua_tonumber(L, 2);
  arg3 = (double)lua_tonumber(L, 3);
  result = (cairo_bool_t)cairo_in_fill(arg1,arg2,arg3);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/

/*static int _cairo_rectangle_list_destroy(lua_State* L) {
  int SWIG_arg = 0;
  cairo_rectangle_list_t *arg1 = (cairo_rectangle_list_t *) 0 ;
  
  SWIG_check_num_args("cairo_rectangle_list_destroy",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_rectangle_list_destroy",1,"cairo_rectangle_list_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo_rectangle_list,0))){
    SWIG_fail_ptr("cairo_rectangle_list_destroy",1,SWIGTYPE_p__cairo_rectangle_list);
  }
  
  cairo_rectangle_list_destroy(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_copy_clip_rectangle_list(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_rectangle_list_t *result = 0 ;
  
  SWIG_check_num_args("cairo_copy_clip_rectangle_list",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_copy_clip_rectangle_list",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_copy_clip_rectangle_list",1,SWIGTYPE_p__cairo);
  }
  
  result = (cairo_rectangle_list_t *)cairo_copy_clip_rectangle_list(arg1);
  SWIG_NewPointerObj(L,result,SWIGTYPE_p__cairo_rectangle_list,0); SWIG_arg++; 
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/

/*static int _cairo_copy_page(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  
  SWIG_check_num_args("cairo_copy_page",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_copy_page",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_copy_page",1,SWIGTYPE_p__cairo);
  }
  
  cairo_copy_page(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_show_page(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  
  SWIG_check_num_args("cairo_show_page",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_show_page",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_show_page",1,SWIGTYPE_p__cairo);
  }
  
  cairo_show_page(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_in_stroke(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  double arg2 ;
  double arg3 ;
  cairo_bool_t result;
  
  SWIG_check_num_args("cairo_in_stroke",3,3)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_in_stroke",1,"cairo_t *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("cairo_in_stroke",2,"double");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("cairo_in_stroke",3,"double");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_in_stroke",1,SWIGTYPE_p__cairo);
  }
  
  arg2 = (double)lua_tonumber(L, 2);
  arg3 = (double)lua_tonumber(L, 3);
  result = (cairo_bool_t)cairo_in_stroke(arg1,arg2,arg3);
  lua_pushnumber(L, (lua_Number) result); SWIG_arg++;
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


static int _cairo_stroke(lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
    cairo_stroke(cr);
    return commonPush(L, "b", 1);
}


/*static int _cairo_stroke_preserve(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  
  SWIG_check_num_args("cairo_stroke_preserve",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_stroke_preserve",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_stroke_preserve",1,SWIGTYPE_p__cairo);
  }
  
  cairo_stroke_preserve(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


static int _cairo_fill(lua_State* L) {
    cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
    cairo_fill(cr);
    return commonPush(L, "b", 1);
}


/*static int _cairo_fill_preserve(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  
  SWIG_check_num_args("cairo_fill_preserve",1,1)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_fill_preserve",1,"cairo_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_fill_preserve",1,SWIGTYPE_p__cairo);
  }
  
  cairo_fill_preserve(arg1);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/

/*static int _cairo_mask(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_pattern_t *arg2 = (cairo_pattern_t *) 0 ;
  
  SWIG_check_num_args("cairo_mask",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_mask",1,"cairo_t *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("cairo_mask",2,"cairo_pattern_t *");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_mask",1,SWIGTYPE_p__cairo);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p__cairo_pattern,0))){
    SWIG_fail_ptr("cairo_mask",2,SWIGTYPE_p__cairo_pattern);
  }
  
  cairo_mask(arg1,arg2);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


/*static int _cairo_mask_surface(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  cairo_surface_t *arg2 = (cairo_surface_t *) 0 ;
  double arg3 ;
  double arg4 ;
  
  SWIG_check_num_args("cairo_mask_surface",4,4)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_mask_surface",1,"cairo_t *");
  if(!SWIG_isptrtype(L,2)) SWIG_fail_arg("cairo_mask_surface",2,"cairo_surface_t *");
  if(!lua_isnumber(L,3)) SWIG_fail_arg("cairo_mask_surface",3,"double");
  if(!lua_isnumber(L,4)) SWIG_fail_arg("cairo_mask_surface",4,"double");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_mask_surface",1,SWIGTYPE_p__cairo);
  }
  
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,2,(void**)&arg2,SWIGTYPE_p__cairo_surface,0))){
    SWIG_fail_ptr("cairo_mask_surface",2,SWIGTYPE_p__cairo_surface);
  }
  
  arg3 = (double)lua_tonumber(L, 3);
  arg4 = (double)lua_tonumber(L, 4);
  cairo_mask_surface(arg1,arg2,arg3,arg4);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/


static int _cairo_paint(lua_State* L) {
	cairo_t *cr = commonGetAs(L, 1, Context.name, cairo_t *);
	cairo_paint(cr);
	return commonPush(L, "b", 1);
}


/*static int _cairo_paint_with_alpha(lua_State* L) {
  int SWIG_arg = 0;
  cairo_t *arg1 = (cairo_t *) 0 ;
  double arg2 ;
  
  SWIG_check_num_args("cairo_paint_with_alpha",2,2)
  if(!SWIG_isptrtype(L,1)) SWIG_fail_arg("cairo_paint_with_alpha",1,"cairo_t *");
  if(!lua_isnumber(L,2)) SWIG_fail_arg("cairo_paint_with_alpha",2,"double");
  
  if (!SWIG_IsOK(SWIG_ConvertPtr(L,1,(void**)&arg1,SWIGTYPE_p__cairo,0))){
    SWIG_fail_ptr("cairo_paint_with_alpha",1,SWIGTYPE_p__cairo);
  }
  
  arg2 = (double)lua_tonumber(L, 2);
  cairo_paint_with_alpha(arg1,arg2);
  
  return SWIG_arg;
  
  if(0) SWIG_fail;
  
fail:
  lua_error(L);
  return SWIG_arg;
}*/

static int l_context_gc(lua_State *L) {
	CommonUserdata *udata = commonGetUserdata(L, 1, ContextName);
	/*if (udata->mustdelete)*/
	cairo_destroy(udata->data);

	return 0;
}

#include "transformation.c"
#include "path.c"

const luaL_Reg ContextMethods[] = {
	{ "save", _cairo_save },
	{ "restore", _cairo_restore },
	{ "setSourceRgb", _cairo_set_source_rgb },
	{ "setSourceRgba", _cairo_set_source_rgba },
	{ "setLineWidth", _cairo_set_line_width },
	{ "setLineCap", _cairo_set_line_cap },
	{ "setFill", _cairo_fill },
	{ "setPaint", _cairo_paint },
	/*path.c*/
	{ "moveTo", _cairo_move_to },
	{ "lineTo", _cairo_line_to },
	{ "arc", _cairo_arc },
	/*transformation.c*/
	{ "translate", _cairo_translate },
	{ "scale", _cairo_scale },
	{ NULL, NULL }
};

const luaL_Reg ContextMetamethods[] = {
	/*{ "__eq", l_texture_eq },*/
	{ "__gc", l_context_gc },
	/*{ "__tostring", l_texture_tostring },*/
	{ NULL, NULL }
};

const CommonObject Context = {
	"CairoContext",
	ContextMethods,
	ContextMetamethods
};

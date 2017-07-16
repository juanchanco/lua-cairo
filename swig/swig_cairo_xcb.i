%module swig_cairo_xcb
%{
 #include <cairo.h>
 #include <cairo-features.h>
 #include <cairo-xcb.h>
 #include <xcb/xcb.h>
%}
%import <cairo.h>
%import <cairo-features.h>
%typemap(in) xcb_drawable_t {
  $1 = (uint32_t) lua_tointeger(L, $input);
}
%typemap(in) xcb_visualid_t {
  $1 = (uint32_t) lua_tointeger(L, $input);
}
%include <cairo-xcb.h>
%inline %{
xcb_visualtype_t *find_visual(xcb_connection_t *c, xcb_visualid_t visual) {
    xcb_screen_iterator_t screen_iter = xcb_setup_roots_iterator(xcb_get_setup(c));

    for (; screen_iter.rem; xcb_screen_next(&screen_iter)) {
        xcb_depth_iterator_t depth_iter = xcb_screen_allowed_depths_iterator(screen_iter.data);
        for (; depth_iter.rem; xcb_depth_next(&depth_iter)) {
            xcb_visualtype_iterator_t visual_iter = xcb_depth_visuals_iterator(depth_iter.data);
            for (; visual_iter.rem; xcb_visualtype_next(&visual_iter))
                if (visual == visual_iter.data->visual_id)
                    return visual_iter.data;
        }
    }

    return NULL;
}
%}

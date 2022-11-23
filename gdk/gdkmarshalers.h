/* This file is generated by glib-genmarshal, do not modify it. This code is licensed under the same license as the containing project. Note that it links to GLib, so must comply with the LGPL linking clauses. */
#ifndef ___GDK_MARSHAL_MARSHAL_H__
#define ___GDK_MARSHAL_MARSHAL_H__

#include <glib-object.h>

G_BEGIN_DECLS

/* VOID:OBJECT (./gdkmarshalers.list:1) */
#define _gdk_marshal_VOID__OBJECT	g_cclosure_marshal_VOID__OBJECT
#define _gdk_marshal_VOID__OBJECTv	g_cclosure_marshal_VOID__OBJECTv

/* VOID:BOOLEAN (./gdkmarshalers.list:2) */
#define _gdk_marshal_VOID__BOOLEAN	g_cclosure_marshal_VOID__BOOLEAN
#define _gdk_marshal_VOID__BOOLEANv	g_cclosure_marshal_VOID__BOOLEANv

/* VOID:POINTER,POINTER,POINTER (./gdkmarshalers.list:3) */
extern
void _gdk_marshal_VOID__POINTER_POINTER_POINTER (GClosure     *closure,
                                                 GValue       *return_value,
                                                 guint         n_param_values,
                                                 const GValue *param_values,
                                                 gpointer      invocation_hint,
                                                 gpointer      marshal_data);
extern
void _gdk_marshal_VOID__POINTER_POINTER_POINTERv (GClosure *closure,
                                                  GValue   *return_value,
                                                  gpointer  instance,
                                                  va_list   args,
                                                  gpointer  marshal_data,
                                                  int       n_params,
                                                  GType    *param_types);

/* OBJECT:VOID (./gdkmarshalers.list:4) */
extern
void _gdk_marshal_OBJECT__VOID (GClosure     *closure,
                                GValue       *return_value,
                                guint         n_param_values,
                                const GValue *param_values,
                                gpointer      invocation_hint,
                                gpointer      marshal_data);
extern
void _gdk_marshal_OBJECT__VOIDv (GClosure *closure,
                                 GValue   *return_value,
                                 gpointer  instance,
                                 va_list   args,
                                 gpointer  marshal_data,
                                 int       n_params,
                                 GType    *param_types);

/* OBJECT:DOUBLE,DOUBLE (./gdkmarshalers.list:5) */
extern
void _gdk_marshal_OBJECT__DOUBLE_DOUBLE (GClosure     *closure,
                                         GValue       *return_value,
                                         guint         n_param_values,
                                         const GValue *param_values,
                                         gpointer      invocation_hint,
                                         gpointer      marshal_data);
extern
void _gdk_marshal_OBJECT__DOUBLE_DOUBLEv (GClosure *closure,
                                          GValue   *return_value,
                                          gpointer  instance,
                                          va_list   args,
                                          gpointer  marshal_data,
                                          int       n_params,
                                          GType    *param_types);

/* BOXED:INT,INT (./gdkmarshalers.list:6) */
extern
void _gdk_marshal_BOXED__INT_INT (GClosure     *closure,
                                  GValue       *return_value,
                                  guint         n_param_values,
                                  const GValue *param_values,
                                  gpointer      invocation_hint,
                                  gpointer      marshal_data);
extern
void _gdk_marshal_BOXED__INT_INTv (GClosure *closure,
                                   GValue   *return_value,
                                   gpointer  instance,
                                   va_list   args,
                                   gpointer  marshal_data,
                                   int       n_params,
                                   GType    *param_types);

/* VOID:DOUBLE,DOUBLE,POINTER,POINTER (./gdkmarshalers.list:7) */
extern
void _gdk_marshal_VOID__DOUBLE_DOUBLE_POINTER_POINTER (GClosure     *closure,
                                                       GValue       *return_value,
                                                       guint         n_param_values,
                                                       const GValue *param_values,
                                                       gpointer      invocation_hint,
                                                       gpointer      marshal_data);
extern
void _gdk_marshal_VOID__DOUBLE_DOUBLE_POINTER_POINTERv (GClosure *closure,
                                                        GValue   *return_value,
                                                        gpointer  instance,
                                                        va_list   args,
                                                        gpointer  marshal_data,
                                                        int       n_params,
                                                        GType    *param_types);

/* VOID:POINTER,POINTER,BOOLEAN,BOOLEAN (./gdkmarshalers.list:8) */
extern
void _gdk_marshal_VOID__POINTER_POINTER_BOOLEAN_BOOLEAN (GClosure     *closure,
                                                         GValue       *return_value,
                                                         guint         n_param_values,
                                                         const GValue *param_values,
                                                         gpointer      invocation_hint,
                                                         gpointer      marshal_data);
extern
void _gdk_marshal_VOID__POINTER_POINTER_BOOLEAN_BOOLEANv (GClosure *closure,
                                                          GValue   *return_value,
                                                          gpointer  instance,
                                                          va_list   args,
                                                          gpointer  marshal_data,
                                                          int       n_params,
                                                          GType    *param_types);


G_END_DECLS

#endif /* ___GDK_MARSHAL_MARSHAL_H__ */

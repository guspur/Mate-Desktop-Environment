#ifndef MATECORBA_IDL_C_BACKEND_H
#define MATECORBA_IDL_C_BACKEND_H

#include "matecorba-idl2.h"

#define OIDL_C_WARNING "/*\n * This file was generated by matecorba-idl-2 - DO NOT EDIT!\n */\n\n"

typedef struct {
	char     *base_name;
	char     *c_base_name;
	FILE     *fh;
	GString  *ext_dcls;
	gboolean  do_impl_hack;
	gboolean  do_skel_defs;
} OIDL_C_Info;

gboolean  matecorba_idl_output_c       (IDL_tree       tree,
			            OIDL_Run_Info *rinfo);
void  matecorba_idl_output_c_headers   (IDL_tree       tree,
				    OIDL_Run_Info *rinfo,
				    OIDL_C_Info   *ci);
void  matecorba_idl_output_c_stubs     (IDL_tree       tree,
				    OIDL_Run_Info *rinfo,
				    OIDL_C_Info   *ci);
void  matecorba_idl_output_c_skeletons (IDL_tree       tree,
				    OIDL_Run_Info *rinfo,
				    OIDL_C_Info   *ci);
void  matecorba_idl_output_c_common    (IDL_tree       tree,
				    OIDL_Run_Info *rinfo,
				    OIDL_C_Info   *ci);
void  matecorba_idl_output_c_skelimpl  (IDL_tree       tree,
				    OIDL_Run_Info *rinfo,
				    OIDL_C_Info   *ci);
void  matecorba_idl_output_c_imodule   (IDL_tree       tree,
				    OIDL_Run_Info *rinfo,
				    OIDL_C_Info   *ci);
void  matecorba_idl_output_c_deps      (IDL_tree       tree,
				    OIDL_Run_Info *rinfo,
				    OIDL_C_Info   *ci);

void matecorba_output_typecode (OIDL_C_Info *ci, IDL_tree ts);

char *matecorba_idl_c_filename_for_pass (const char *input_filename, int pass);

/* utils */
char    *matecorba_cbe_get_typespec_str     (IDL_tree    tree);
void     matecorba_cbe_write_typespec       (FILE       *of,
					 IDL_tree    tree);
void     matecorba_cbe_write_param_typespec (FILE       *of,
					 IDL_tree    tree);
void     matecorba_cbe_op_write_proto       (FILE       *of,
					 IDL_tree    op,
					 const char *nom_prefix,
					 gboolean    for_epv);
IDL_tree matecorba_cbe_get_typespec         (IDL_tree    tree);
void     matecorba_cbe_write_const          (FILE       *of,
					 IDL_tree    tree);
gboolean matecorba_cbe_type_is_fixed_length (IDL_tree    ts);
gboolean matecorba_cbe_type_is_builtin      (IDL_tree    tree);
void     matecorba_cbe_id_define_hack       (FILE       *fh,
					 const char *def_prefix,
					 const char *def_name,
					 const char *def_value);
void     matecorba_cbe_id_cond_hack         (FILE       *fh,
					 const char *def_prefix,
					 const char *def_name,
					 const char *def_value);
char    *matecorba_cbe_get_typecode_name    (IDL_tree    tree);
void     matecorba_cbe_flatten_args         (IDL_tree    tree,
					 FILE       *of,
					 const char *name);
void     matecorba_cbe_unflatten_args       (IDL_tree    tree,
					 FILE       *of,
					 const char *name);
#endif

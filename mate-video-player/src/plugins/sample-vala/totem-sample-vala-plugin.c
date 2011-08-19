/* totem-sample-vala-plugin.c generated by valac, the Vala compiler
 * generated from totem-sample-vala-plugin.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <totem-plugin.h>
#include <stdio.h>
#include <totem.h>


#define TYPE_SAMPLE_VALA_PLUGIN (sample_vala_plugin_get_type ())
#define SAMPLE_VALA_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_SAMPLE_VALA_PLUGIN, SampleValaPlugin))
#define SAMPLE_VALA_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_SAMPLE_VALA_PLUGIN, SampleValaPluginClass))
#define IS_SAMPLE_VALA_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_SAMPLE_VALA_PLUGIN))
#define IS_SAMPLE_VALA_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_SAMPLE_VALA_PLUGIN))
#define SAMPLE_VALA_PLUGIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_SAMPLE_VALA_PLUGIN, SampleValaPluginClass))

typedef struct _SampleValaPlugin SampleValaPlugin;
typedef struct _SampleValaPluginClass SampleValaPluginClass;
typedef struct _SampleValaPluginPrivate SampleValaPluginPrivate;

struct _SampleValaPlugin {
	TotemPlugin parent_instance;
	SampleValaPluginPrivate * priv;
};

struct _SampleValaPluginClass {
	TotemPluginClass parent_class;
};


static gpointer sample_vala_plugin_parent_class = NULL;
static GType sample_vala_plugin_type_id = 0;

GType sample_vala_plugin_get_type (void) G_GNUC_CONST;
GType sample_vala_plugin_register_type (GTypeModule * module);
enum  {
	SAMPLE_VALA_PLUGIN_DUMMY_PROPERTY
};
static gboolean sample_vala_plugin_real_activate (TotemPlugin* base, TotemObject* totem, GError** error);
static void sample_vala_plugin_real_deactivate (TotemPlugin* base, TotemObject* totem);
SampleValaPlugin* sample_vala_plugin_new (void);
SampleValaPlugin* sample_vala_plugin_construct (GType object_type);
GType register_totem_plugin (GTypeModule* module);



static gboolean sample_vala_plugin_real_activate (TotemPlugin* base, TotemObject* totem, GError** error) {
	SampleValaPlugin * self;
	gboolean result = FALSE;
	self = (SampleValaPlugin*) base;
	g_return_val_if_fail (totem != NULL, FALSE);
	fprintf (stdout, "Hello world\n");
	result = TRUE;
	return result;
}


static void sample_vala_plugin_real_deactivate (TotemPlugin* base, TotemObject* totem) {
	SampleValaPlugin * self;
	self = (SampleValaPlugin*) base;
	g_return_if_fail (totem != NULL);
	fprintf (stdout, "Goodbye world\n");
}


SampleValaPlugin* sample_vala_plugin_construct (GType object_type) {
	SampleValaPlugin * self;
	self = g_object_newv (object_type, 0, NULL);
	return self;
}


SampleValaPlugin* sample_vala_plugin_new (void) {
	return sample_vala_plugin_construct (TYPE_SAMPLE_VALA_PLUGIN);
}


static void sample_vala_plugin_class_init (SampleValaPluginClass * klass) {
	sample_vala_plugin_parent_class = g_type_class_peek_parent (klass);
	TOTEM_PLUGIN_CLASS (klass)->activate = sample_vala_plugin_real_activate;
	TOTEM_PLUGIN_CLASS (klass)->deactivate = sample_vala_plugin_real_deactivate;
}


static void sample_vala_plugin_instance_init (SampleValaPlugin * self) {
}


GType sample_vala_plugin_get_type (void) {
	return sample_vala_plugin_type_id;
}


GType sample_vala_plugin_register_type (GTypeModule * module) {
	static const GTypeInfo g_define_type_info = { sizeof (SampleValaPluginClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) sample_vala_plugin_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SampleValaPlugin), 0, (GInstanceInitFunc) sample_vala_plugin_instance_init, NULL };
	sample_vala_plugin_type_id = g_type_module_register_type (module, TOTEM_TYPE_PLUGIN, "SampleValaPlugin", &g_define_type_info, 0);
	return sample_vala_plugin_type_id;
}


GType register_totem_plugin (GTypeModule* module) {
	GType result = 0UL;
	g_return_val_if_fail (module != NULL, 0UL);
	sample_vala_plugin_register_type (module);
	fprintf (stdout, "Registering plugin %s\n", "SampleValaPlugin");
	result = TYPE_SAMPLE_VALA_PLUGIN;
	return result;
}





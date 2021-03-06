include $(top_srcdir)/Makefile.shared

SUBDIRS=file-manager

bin_PROGRAMS = \
	caja \
	caja-file-management-properties \
	caja-autorun-software \
	caja-connect-server \
	$(NULL)

libexec_PROGRAMS = \
	caja-convert-metadata \
	$(NULL)

INCLUDES = \
	-I$(top_srcdir) \
	-I$(top_srcdir)/cut-n-paste-code \
	-I$(top_builddir)/libcaja-private \
	$(CORE_CFLAGS) \
	$(WARNING_CFLAGS) \
	$(EXIF_CFLAGS) \
	$(EXEMPI_CFLAGS) \
	-DDATADIR=\""$(datadir)"\" \
	-DLIBDIR=\""$(libdir)"\" \
	-DLIBEXECDIR=\""$(libexecdir)"\" \
	-DCAJA_DATADIR=\""$(datadir)/caja"\" \
	-DUIDIR=\""$(datadir)/caja/ui"\" \
	-DCAJA_PIXMAPDIR=\""$(datadir)/pixmaps/caja"\" \
	-DPREFIX=\""$(prefix)"\" \
	-DSYSCONFDIR=\""$(sysconfdir)"\" \
	-DVERSION="\"$(VERSION)\"" \
	$(DISABLE_DEPRECATED_CFLAGS) \
	$(UNIQUE_CFLAGS) \
	$(NULL)

LDADD = \
	$(top_builddir)/src/file-manager/libcaja-file-manager.la \
	$(top_builddir)/libcaja-private/libcaja-private.la \
	$(CORE_LIBS) \
	$(EXIF_LIBS) \
	$(EXEMPI_LIBS) \
	$(POPT_LIBS) \
	$(NULL)

@INTLTOOL_DESKTOP_RULE@

desktop_in_files=mate-network-scheme.desktop.in
desktop_files=$(desktop_in_files:.desktop.in=.desktop)
desktopdir = $(datadir)/mate/network/

schemedir = $(datadir)/applications
scheme_DATA = mate-network-scheme.desktop

caja_SOURCES = \
	caja-actions.h \
	caja-application.c \
	caja-application.h \
	caja-bookmark-list.c \
	caja-bookmark-list.h \
	caja-bookmarks-window.c \
	caja-bookmarks-window.h \
	caja-connect-server-dialog.c \
	caja-connect-server-dialog.h \
	caja-connect-server-dialog-nonmain.c \
	caja-desktop-window.c \
	caja-desktop-window.h \
	caja-emblem-sidebar.c \
	caja-emblem-sidebar.h \
	caja-file-management-properties.c \
	caja-file-management-properties.h \
	caja-history-sidebar.c \
	caja-history-sidebar.h \
	caja-image-properties-page.c \
	caja-image-properties-page.h \
	caja-information-panel.c \
	caja-information-panel.h \
	caja-location-bar.c \
	caja-location-bar.h \
	caja-location-dialog.c \
	caja-location-dialog.h \
	caja-location-entry.c \
	caja-location-entry.h \
	caja-main.c \
	caja-main.h \
	caja-navigation-action.c \
	caja-navigation-action.h \
	caja-navigation-bar.c \
	caja-navigation-bar.h \
	caja-navigation-window-menus.c \
	caja-navigation-window.c \
	caja-navigation-window.h \
	caja-navigation-window-pane.c \
	caja-navigation-window-pane.h \
	caja-navigation-window-slot.c \
	caja-navigation-window-slot.h \
	caja-notebook.c \
	caja-notebook.h \
	caja-notes-viewer.c \
	caja-notes-viewer.h \
	caja-pathbar.c \
	caja-pathbar.h \
	caja-places-sidebar.c \
	caja-places-sidebar.h \
	caja-property-browser.c \
	caja-property-browser.h \
	caja-query-editor.c \
	caja-query-editor.h \
	caja-search-bar.c \
	caja-search-bar.h \
	caja-self-check-functions.c \
	caja-self-check-functions.h \
	caja-side-pane.c \
	caja-side-pane.h \
	caja-sidebar-title.c \
	caja-sidebar-title.h \
	caja-spatial-window.c \
	caja-spatial-window.h \
	caja-trash-bar.c \
	caja-trash-bar.h \
	caja-view-as-action.c \
	caja-view-as-action.h \
	caja-window-bookmarks.c \
	caja-window-bookmarks.h \
	caja-window-manage-views.c \
	caja-window-manage-views.h \
	caja-window-menus.c \
	caja-window-pane.c \
	caja-window-pane.h \
	caja-window-private.h \
	caja-window-slot.c \
	caja-window-slot.h \
	caja-window-toolbars.c \
	caja-window.c \
	caja-window.h \
	caja-x-content-bar.c \
	caja-x-content-bar.h \
	caja-zoom-action.c \
	caja-zoom-action.h \
	caja-zoom-control.c \
	caja-zoom-control.h \
	$(NULL)

caja_file_management_properties_SOURCES = \
	caja-file-management-properties.c \
	caja-file-management-properties.h \
	caja-file-management-properties-main.c \
	$(NULL)

caja_autorun_software_SOURCES = \
	caja-autorun-software.c \
	$(NULL)

caja_connect_server_SOURCES = \
	caja-bookmark-list.c \
	caja-bookmark-list.h \
	caja-connect-server-dialog.c \
	caja-connect-server-dialog.h \
	caja-connect-server-dialog-main.c \
	caja-location-entry.c \
	caja-location-entry.h \
	$(NULL)

caja_convert_metadata_SOURCES = \
	caja-convert-metadata.c \
	$(NULL)

TESTS=check-caja

@INTLTOOL_SERVER_RULE@

uidir = $(datadir)/caja/ui
ui_DATA = \
	caja-shell-ui.xml \
	caja-navigation-window-ui.xml \
	caja-spatial-window-ui.xml \
	caja-file-management-properties.ui \
	caja-bookmarks-window.ui \
	$(NULL)

CLEANFILES = \
	$(desktop_files) \
	$(server_DATA) \
	$(NULL)

EXTRA_DIST = \
	$(server_in_files) \
	$(ui_DATA) \
	check-caja \
	$(desktop_in_files) \
	$(NULL)

BUILT_SOURCES = \
	$(NULL)

dist-hook:
	cd $(distdir); rm -f $(CLEANFILES)

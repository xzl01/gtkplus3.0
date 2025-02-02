/* GTK - The GIMP Toolkit
 * gtkfilechooser.h: Abstract interface for file selector GUIs
 * Copyright (C) 2003, Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GTK_FILE_CHOOSER_H__
#define __GTK_FILE_CHOOSER_H__

#if !defined (__GTK_H_INSIDE__) && !defined (GTK_COMPILATION)
#error "Only <gtk/gtk.h> can be included directly."
#endif

#include <gtk/gtkfilefilter.h>
#include <gtk/gtkwidget.h>

G_BEGIN_DECLS

#define GTK_TYPE_FILE_CHOOSER             (gtk_file_chooser_get_type ())
#define GTK_FILE_CHOOSER(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), GTK_TYPE_FILE_CHOOSER, GtkFileChooser))
#define GTK_IS_FILE_CHOOSER(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GTK_TYPE_FILE_CHOOSER))

typedef struct _GtkFileChooser      GtkFileChooser;

/**
 * GtkFileChooserAction:
 * @GTK_FILE_CHOOSER_ACTION_OPEN: Indicates open mode.  The file chooser
 *  will only let the user pick an existing file.
 * @GTK_FILE_CHOOSER_ACTION_SAVE: Indicates save mode.  The file chooser
 *  will let the user pick an existing file, or type in a new
 *  filename.
 * @GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER: Indicates an Open mode for
 *  selecting folders.  The file chooser will let the user pick an
 *  existing folder.
 * @GTK_FILE_CHOOSER_ACTION_CREATE_FOLDER: Indicates a mode for creating a
 *  new folder.  The file chooser will let the user name an existing or
 *  new folder.
 *
 * Describes whether a #GtkFileChooser is being used to open existing files
 * or to save to a possibly new file.
 */
typedef enum
{
  GTK_FILE_CHOOSER_ACTION_OPEN,
  GTK_FILE_CHOOSER_ACTION_SAVE,
  GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER,
  GTK_FILE_CHOOSER_ACTION_CREATE_FOLDER
} GtkFileChooserAction;

/**
 * GtkFileChooserConfirmation:
 * @GTK_FILE_CHOOSER_CONFIRMATION_CONFIRM: The file chooser will present
 *  its stock dialog to confirm about overwriting an existing file.
 * @GTK_FILE_CHOOSER_CONFIRMATION_ACCEPT_FILENAME: The file chooser will
 *  terminate and accept the user’s choice of a file name.
 * @GTK_FILE_CHOOSER_CONFIRMATION_SELECT_AGAIN: The file chooser will
 *  continue running, so as to let the user select another file name.
 *
 * Used as a return value of handlers for the
 * #GtkFileChooser::confirm-overwrite signal of a #GtkFileChooser. This
 * value determines whether the file chooser will present the stock
 * confirmation dialog, accept the user’s choice of a filename, or
 * let the user choose another filename.
 *
 * Since: 2.8
 */
typedef enum
{
  GTK_FILE_CHOOSER_CONFIRMATION_CONFIRM,
  GTK_FILE_CHOOSER_CONFIRMATION_ACCEPT_FILENAME,
  GTK_FILE_CHOOSER_CONFIRMATION_SELECT_AGAIN
} GtkFileChooserConfirmation;

GDK_AVAILABLE_IN_ALL
GType gtk_file_chooser_get_type (void) G_GNUC_CONST;

/* GError enumeration for GtkFileChooser */
/**
 * GTK_FILE_CHOOSER_ERROR:
 *
 * Used to get the #GError quark for #GtkFileChooser errors.
 */
#define GTK_FILE_CHOOSER_ERROR (gtk_file_chooser_error_quark ())

/**
 * GtkFileChooserError:
 * @GTK_FILE_CHOOSER_ERROR_NONEXISTENT: Indicates that a file does not exist.
 * @GTK_FILE_CHOOSER_ERROR_BAD_FILENAME: Indicates a malformed filename.
 * @GTK_FILE_CHOOSER_ERROR_ALREADY_EXISTS: Indicates a duplicate path (e.g. when
 *  adding a bookmark).
 * @GTK_FILE_CHOOSER_ERROR_INCOMPLETE_HOSTNAME: Indicates an incomplete hostname (e.g. "http://foo" without a slash after that).
 *
 * These identify the various errors that can occur while calling
 * #GtkFileChooser functions.
 */
typedef enum {
  GTK_FILE_CHOOSER_ERROR_NONEXISTENT,
  GTK_FILE_CHOOSER_ERROR_BAD_FILENAME,
  GTK_FILE_CHOOSER_ERROR_ALREADY_EXISTS,
  GTK_FILE_CHOOSER_ERROR_INCOMPLETE_HOSTNAME
} GtkFileChooserError;

GDK_AVAILABLE_IN_ALL
GQuark gtk_file_chooser_error_quark (void);

/* Configuration
 */
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
void                 gtk_file_chooser_set_action          (GtkFileChooser       *chooser,
							   GtkFileChooserAction  action);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
GtkFileChooserAction gtk_file_chooser_get_action          (GtkFileChooser       *chooser);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
void                 gtk_file_chooser_set_local_only      (GtkFileChooser       *chooser,
							   gboolean              local_only);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
gboolean             gtk_file_chooser_get_local_only      (GtkFileChooser       *chooser);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
void                 gtk_file_chooser_set_select_multiple (GtkFileChooser       *chooser,
							   gboolean              select_multiple);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
gboolean             gtk_file_chooser_get_select_multiple (GtkFileChooser       *chooser);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
void                 gtk_file_chooser_set_show_hidden     (GtkFileChooser       *chooser,
							   gboolean              show_hidden);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
gboolean             gtk_file_chooser_get_show_hidden     (GtkFileChooser       *chooser);

__attribute__((weak))
GDK_AVAILABLE_IN_ALL
void                 gtk_file_chooser_set_do_overwrite_confirmation (GtkFileChooser *chooser,
								     gboolean        do_overwrite_confirmation);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
gboolean             gtk_file_chooser_get_do_overwrite_confirmation (GtkFileChooser *chooser);

__attribute__((weak))
GDK_AVAILABLE_IN_ALL
void                 gtk_file_chooser_set_create_folders  (GtkFileChooser       *chooser,
							  gboolean               create_folders);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
gboolean             gtk_file_chooser_get_create_folders (GtkFileChooser *chooser);

/* Suggested name for the Save-type actions
 */
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
void        gtk_file_chooser_set_current_name  (GtkFileChooser *chooser,
					        const gchar    *name);
__attribute__((weak))
GDK_AVAILABLE_IN_3_10
gchar *gtk_file_chooser_get_current_name (GtkFileChooser *chooser);

/* Filename manipulation
 */
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
gchar *  gtk_file_chooser_get_filename       (GtkFileChooser *chooser);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
gboolean gtk_file_chooser_set_filename       (GtkFileChooser *chooser,
					      const char     *filename);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
gboolean gtk_file_chooser_select_filename    (GtkFileChooser *chooser,
					      const char     *filename);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
void     gtk_file_chooser_unselect_filename  (GtkFileChooser *chooser,
					      const char     *filename);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
void     gtk_file_chooser_select_all         (GtkFileChooser *chooser);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
void     gtk_file_chooser_unselect_all       (GtkFileChooser *chooser);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
GSList * gtk_file_chooser_get_filenames      (GtkFileChooser *chooser);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
gboolean gtk_file_chooser_set_current_folder (GtkFileChooser *chooser,
					      const gchar    *filename);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
gchar *  gtk_file_chooser_get_current_folder (GtkFileChooser *chooser);


/* URI manipulation
 */
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
gchar *  gtk_file_chooser_get_uri                (GtkFileChooser *chooser);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
gboolean gtk_file_chooser_set_uri                (GtkFileChooser *chooser,
						  const char     *uri);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
gboolean gtk_file_chooser_select_uri             (GtkFileChooser *chooser,
						  const char     *uri);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
void     gtk_file_chooser_unselect_uri           (GtkFileChooser *chooser,
						  const char     *uri);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
GSList * gtk_file_chooser_get_uris               (GtkFileChooser *chooser);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
gboolean gtk_file_chooser_set_current_folder_uri (GtkFileChooser *chooser,
						  const gchar    *uri);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
gchar *  gtk_file_chooser_get_current_folder_uri (GtkFileChooser *chooser);

/* GFile manipulation */
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
GFile *  gtk_file_chooser_get_file                (GtkFileChooser  *chooser);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
gboolean gtk_file_chooser_set_file                (GtkFileChooser  *chooser,
                                                   GFile           *file,
                                                   GError         **error);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
gboolean gtk_file_chooser_select_file             (GtkFileChooser  *chooser,
                                                   GFile           *file,
                                                   GError         **error);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
void     gtk_file_chooser_unselect_file           (GtkFileChooser  *chooser,
                                                   GFile           *file);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
GSList * gtk_file_chooser_get_files               (GtkFileChooser  *chooser);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
gboolean gtk_file_chooser_set_current_folder_file (GtkFileChooser  *chooser,
                                                   GFile           *file,
                                                   GError         **error);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
GFile *  gtk_file_chooser_get_current_folder_file (GtkFileChooser  *chooser);

/* Preview widget
 */
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
void       gtk_file_chooser_set_preview_widget        (GtkFileChooser *chooser,
						       GtkWidget      *preview_widget);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
GtkWidget *gtk_file_chooser_get_preview_widget        (GtkFileChooser *chooser);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
void       gtk_file_chooser_set_preview_widget_active (GtkFileChooser *chooser,
						       gboolean        active);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
gboolean   gtk_file_chooser_get_preview_widget_active (GtkFileChooser *chooser);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
void       gtk_file_chooser_set_use_preview_label     (GtkFileChooser *chooser,
						       gboolean        use_label);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
gboolean   gtk_file_chooser_get_use_preview_label     (GtkFileChooser *chooser);

__attribute__((weak))
GDK_AVAILABLE_IN_ALL
char  *gtk_file_chooser_get_preview_filename (GtkFileChooser *chooser);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
char  *gtk_file_chooser_get_preview_uri      (GtkFileChooser *chooser);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
GFile *gtk_file_chooser_get_preview_file     (GtkFileChooser *chooser);

/* Extra widget
 */
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
void       gtk_file_chooser_set_extra_widget (GtkFileChooser *chooser,
					      GtkWidget      *extra_widget);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
GtkWidget *gtk_file_chooser_get_extra_widget (GtkFileChooser *chooser);

/* List of user selectable filters
 */
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
void    gtk_file_chooser_add_filter    (GtkFileChooser *chooser,
					GtkFileFilter  *filter);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
void    gtk_file_chooser_remove_filter (GtkFileChooser *chooser,
					GtkFileFilter  *filter);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
GSList *gtk_file_chooser_list_filters  (GtkFileChooser *chooser);

/* Current filter
 */
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
void           gtk_file_chooser_set_filter (GtkFileChooser *chooser,
					   GtkFileFilter  *filter);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
GtkFileFilter *gtk_file_chooser_get_filter (GtkFileChooser *chooser);

/* Per-application shortcut folders */

__attribute__((weak))
GDK_AVAILABLE_IN_ALL
gboolean gtk_file_chooser_add_shortcut_folder    (GtkFileChooser *chooser,
						  const char     *folder,
						  GError        **error);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
gboolean gtk_file_chooser_remove_shortcut_folder (GtkFileChooser *chooser,
						  const char     *folder,
						  GError        **error);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
GSList *gtk_file_chooser_list_shortcut_folders   (GtkFileChooser *chooser);

__attribute__((weak))
GDK_AVAILABLE_IN_ALL
gboolean gtk_file_chooser_add_shortcut_folder_uri    (GtkFileChooser *chooser,
						      const char     *uri,
						      GError        **error);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
gboolean gtk_file_chooser_remove_shortcut_folder_uri (GtkFileChooser *chooser,
						      const char     *uri,
						      GError        **error);
__attribute__((weak))
GDK_AVAILABLE_IN_ALL
GSList *gtk_file_chooser_list_shortcut_folder_uris   (GtkFileChooser *chooser);

__attribute__((weak))
GDK_AVAILABLE_IN_3_22
void        gtk_file_chooser_add_choice              (GtkFileChooser  *chooser,
                                                      const char      *id,
                                                      const char      *label,
                                                      const char     **options,
                                                      const char     **option_labels);
__attribute__((weak))
GDK_AVAILABLE_IN_3_22
void        gtk_file_chooser_remove_choice           (GtkFileChooser  *chooser,
                                                      const char      *id);
__attribute__((weak))
GDK_AVAILABLE_IN_3_22
void        gtk_file_chooser_set_choice              (GtkFileChooser  *chooser,
                                                      const char      *id,
                                                      const char      *option);
__attribute__((weak))
GDK_AVAILABLE_IN_3_22
const char *gtk_file_chooser_get_choice              (GtkFileChooser  *chooser,
                                                      const char      *id);

G_END_DECLS

#endif /* __GTK_FILE_CHOOSER_H__ */

#include <gtk/gtk.h>
#include "setup.h"

typedef struct app_widgets {
    GtkWidget* w_draw_acc;
    GtkWidget* w_draw_vel;
    GtkWidget* w_draw_pres;
    GtkWidget* w_label_data_acc;
    GtkWidget* w_label_data_vel;
    GtkWidget* w_label_data_pres;
    GtkWidget* w_label_data_alt;
    GtkWidget* w_label_data_temp;
    GtkWidget* w_progress_alt;
    GtkWidget* w_progress_temp;
    GtkWidget* w_button_launch;
    GtkWidget* w_label_timer;
} app_widgets;

void app_destroy() {
    printf("app_destroy\n");
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    auto glade_file = "src/gui/outline.glade";
    app_widgets* widgets = g_slice_new(app_widgets);
    
    // create application
    gtk_init(&argc, &argv);

    // get the refrence builder
    auto builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, glade_file, NULL);

    // add the glade window and widgets
    auto win = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    g_signal_connect(win, "destroy", G_CALLBACK(app_destroy), NULL);
    if (win) {
        // connect widgets
        widgets->w_draw_acc         = GTK_WIDGET(gtk_builder_get_object(builder, "draw_acc"));
        widgets->w_draw_vel         = GTK_WIDGET(gtk_builder_get_object(builder, "draw_vel"));
        widgets->w_draw_pres        = GTK_WIDGET(gtk_builder_get_object(builder, "draw_pres"));
        widgets->w_label_data_acc   = GTK_WIDGET(gtk_builder_get_object(builder, "label_data_acc"));
        widgets->w_label_data_vel   = GTK_WIDGET(gtk_builder_get_object(builder, "label_data_vel"));
        widgets->w_label_data_pres  = GTK_WIDGET(gtk_builder_get_object(builder, "label_data_pres"));
        widgets->w_label_data_alt   = GTK_WIDGET(gtk_builder_get_object(builder, "label_data_alt"));
        widgets->w_label_data_temp  = GTK_WIDGET(gtk_builder_get_object(builder, "label_data_temp"));
        widgets->w_progress_alt     = GTK_WIDGET(gtk_builder_get_object(builder, "progress_alt"));
        widgets->w_progress_temp    = GTK_WIDGET(gtk_builder_get_object(builder, "progress_temp"));
        widgets->w_button_launch    = GTK_WIDGET(gtk_builder_get_object(builder, "button_launch"));
        widgets->w_label_timer      = GTK_WIDGET(gtk_builder_get_object(builder, "label_timer"));\
        gtk_builder_connect_signals(builder, widgets);
        g_object_unref(builder);

        gtk_window_set_resizable(GTK_WINDOW(win), false);
        gtk_widget_show(win);
        gtk_main();
    }

    g_slice_free(app_widgets, widgets);
    return 0;
}

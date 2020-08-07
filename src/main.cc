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
    auto refBuilder = gtk_builder_new();
    gtk_builder_add_from_file(refBuilder, glade_file, NULL);

    // add the glade window and widgets
    auto win = GTK_WIDGET(gtk_builder_get_object(refBuilder, "window"));
    g_signal_connect(win, "destroy", G_CALLBACK(app_destroy), NULL);
    gtk_builder_connect_signals(refBuilder, widgets);
    if (win) {
        // setup and run app
        widgets->w_draw_acc;
        widgets->w_draw_vel;
        widgets->w_draw_pres;
        widgets->w_label_data_acc;
        widgets->w_label_data_vel;
        widgets->w_label_data_pres;
        widgets->w_label_data_alt;
        widgets->w_label_data_temp;
        widgets->w_progress_alt;
        widgets->w_progress_temp;
        widgets->w_button_launch;
        widgets->w_label_timer;

        gtk_window_set_resizable(GTK_WINDOW(win), false);
        gtk_widget_show(win);
        gtk_main();
    }

    g_object_unref(refBuilder);
    g_slice_free(app_widgets, widgets);
    return 0;
}

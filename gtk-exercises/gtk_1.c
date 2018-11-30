#include <gtk/gtk.h>

void on_destroy(GtkWidget*, gpointer);
void on_button_click(GtkButton*, gpointer);

int main(int argc, char *argv[])
{
	gtk_init(&argc, &argv);

	GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	GtkWidget* layout = gtk_table_new(1, 2, TRUE);
	GtkWidget* button = gtk_button_new_with_label("Hallo.");
	GtkWidget* button2 = gtk_button_new_with_label("Hallo 2.");

	gtk_window_set_title(GTK_WINDOW(window), "Fenster 1");
	gtk_window_set_default_size(GTK_WINDOW(window), 800, 400);
	
	g_signal_connect(window, "destroy", G_CALLBACK(on_destroy), NULL);
	g_signal_connect(button, "clicked", G_CALLBACK(on_button_click), NULL);
	g_signal_connect(button2, "clicked", G_CALLBACK(on_button_click), NULL);

	gtk_container_add(GTK_CONTAINER(window), layout);

	gtk_table_attach_defaults(GTK_TABLE(layout), button, 0, 1, 0, 1);
	gtk_table_attach_defaults(GTK_TABLE(layout), button2, 1, 2, 0, 1);

	gtk_table_set_col_spacings(GTK_TABLE(layout), 10);
	gtk_table_set_row_spacings(GTK_TABLE(layout), 10);

	gtk_widget_show(button);
	gtk_widget_show(button2);
	gtk_widget_show(layout);
	gtk_widget_show(window);

	gtk_main();
	return 0;
}

void on_destroy(GtkWidget* src, gpointer ptr)
{
	gtk_main_quit();
}

void on_button_click(GtkButton* src, gpointer ptr)
{
	gtk_button_set_label(src, "Yay.");
}

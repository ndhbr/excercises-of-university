#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

typedef struct _form {
	GtkWidget* label_summand_1;
	GtkWidget* label_summand_2;
	GtkWidget* label_ergebnis;
	GtkWidget* entry_summand_1;
	GtkWidget* entry_summand_2;
	GtkWidget* entry_ergebnis;	
	GtkWidget* button;
} Form;

Form f;

static void on_destroy(GtkWidget* widget, gpointer data) {
	printf("Schließe das Programm.\n");
	gtk_main_quit();
}

static void on_click(GtkWidget* widget, gpointer data) {
	int summand1 = atoi(gtk_entry_get_text(GTK_ENTRY(f.entry_summand_1)));
	int summand2 = atoi(gtk_entry_get_text(GTK_ENTRY(f.entry_summand_2)));
	char result[12];

	sprintf(result, "%d", (summand1+summand2));

	gtk_entry_set_text(GTK_ENTRY(f.entry_ergebnis), result);
}

int main(int argc, char* argv[]) {
	gtk_init(&argc, &argv);

	GtkWidget* window;
	GtkWidget* layout_table;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	layout_table = gtk_table_new(4, 2, TRUE);

	gtk_window_set_title(GTK_WINDOW(window), "Rechner");

	f.label_summand_1 = gtk_label_new("Summand 1:");
	f.label_summand_2 = gtk_label_new("Summand 2:");
	f.label_ergebnis = gtk_label_new("Ergebnis:");
	f.entry_summand_1 = gtk_entry_new();
	f.entry_summand_2 = gtk_entry_new();
	f.entry_ergebnis = gtk_entry_new();
	f.button = gtk_button_new_with_label("Berechnen");

	gtk_entry_set_max_length(GTK_ENTRY(f.entry_summand_1), 3);
	gtk_entry_set_max_length(GTK_ENTRY(f.entry_summand_2), 4);
	gtk_editable_set_editable(GTK_EDITABLE(f.entry_ergebnis), FALSE);

	g_signal_connect(window, "destroy", G_CALLBACK(on_destroy), NULL);
	g_signal_connect(f.button, "clicked", G_CALLBACK(on_click), NULL);

	gtk_container_add(GTK_CONTAINER(window), layout_table);

	gtk_table_attach_defaults(GTK_TABLE(layout_table), f.label_summand_1, 0, 1, 0, 1);
	gtk_table_attach_defaults(GTK_TABLE(layout_table), f.label_summand_2, 0, 1, 1, 2);
	gtk_table_attach_defaults(GTK_TABLE(layout_table), f.label_ergebnis, 0, 1, 2, 3);
	gtk_table_attach_defaults(GTK_TABLE(layout_table), f.entry_summand_1, 1, 2, 0, 1);
	gtk_table_attach_defaults(GTK_TABLE(layout_table), f.entry_summand_2, 1, 2, 1, 2);
	gtk_table_attach_defaults(GTK_TABLE(layout_table), f.entry_ergebnis, 1, 2, 2, 3);
	gtk_table_attach_defaults(GTK_TABLE(layout_table), f.button, 0, 1, 3, 4);

	gtk_widget_show(window);
	gtk_widget_show(layout_table);
	gtk_widget_show(f.label_summand_1);
	gtk_widget_show(f.label_summand_2);
	gtk_widget_show(f.label_ergebnis);
	gtk_widget_show(f.entry_summand_1);
	gtk_widget_show(f.entry_summand_2);
	gtk_widget_show(f.entry_ergebnis);
	gtk_widget_show(f.button);

	gtk_main();
	return 0;
}

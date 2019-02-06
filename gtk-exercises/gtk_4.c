#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#define CELL_NUM 9

typedef struct _elements {
	GtkWidget* window;
	GtkWidget* grid;

	GtkWidget* cells[CELL_NUM];
} Elements;

Elements e;

int main(int argc, char* argv[]) {
	int i;

	gtk_init(&argc, &argv);

	e.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	e.grid = gtk_grid_new();

	for(i = 0; i < CELL_NUM; i++) {
		char label[18] = "Btn ";
		char nr[12];
		sprintf(nr, "%d", i+1);
		strcat(label, nr);
		e.cells[i] = gtk_button_new_with_label(label);
	}

	gtk_grid_attach(GTK_GRID(e.grid), e.cells[0], 0, 0, 1, 1);
	gtk_grid_attach(GTK_GRID(e.grid), e.cells[1], 1, 0, 1, 1);
	gtk_grid_attach(GTK_GRID(e.grid), e.cells[2], 2, 0, 1, 1);
	gtk_grid_attach(GTK_GRID(e.grid), e.cells[3], 0, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(e.grid), e.cells[4], 1, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(e.grid), e.cells[5], 2, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(e.grid), e.cells[6], 0, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(e.grid), e.cells[7], 1, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(e.grid), e.cells[8], 2, 2, 1, 1);

	gtk_container_add(GTK_CONTAINER(e.window), e.grid);

	gtk_widget_show(e.window);
	gtk_widget_show_all(e.grid);

	gtk_main();
	return 0;	
}

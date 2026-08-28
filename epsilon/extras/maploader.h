#ifndef CSV_SEPARATOR
#define CSV_SEPARATOR ","
#endif


// they all have multi-inclusion protection.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {

	int rows, columns;
	int* data;
	size_t data_size;
} map;

map *selected_map = NULL;




map * create_map(char* path){

	map *output = malloc(sizeof(map));

	output->rows = 0;
	output->columns = 0;


	FILE *file = fopen(path, "r");

	if (file == NULL) {
		perror("Error opening file\n");

		output->data = 0;
		output->rows = 0;
		output->columns = 0;

	}

	// initial memory allocation, we don't like segfaults nor memory corruption here.

	long fields=0;
	char c=0;
	int in_field=0;

	while((c=fgetc(file)) != EOF){
		if(c==CSV_SEPARATOR[0] || c=='\n') fields++;

		if(c=='\n')output->rows++;

	}
	rewind(file);

	output->data_size = sizeof(int)*fields;
	output->data=malloc(sizeof(int)*fields);


	size_t length = 0;
	size_t read;

	long index=0;


	char *buffer = NULL;
	long size;

	fseek(file, 0, SEEK_END);
	size = ftell(file);

	rewind(file);

	buffer = malloc(size + 1);
	fread(buffer, 1, size, file);

	buffer[size] = '\0';


	char* cursor = buffer;

	while (cursor != NULL && *cursor != '\0') {

		char* newline = strchr(cursor, '\n');
		if (newline != NULL) {
			*newline = '\0';  /* terminate this line in place */
		}

		char* line = cursor;

		char* num = strtok(line, CSV_SEPARATOR);

		output->columns = 0;

		while (num != NULL) {
			output->columns++;
			output->data[index++] = atoi(num);
			num = strtok(NULL, CSV_SEPARATOR);

		}

		cursor = (newline != NULL) ? newline + 1 : NULL;
	}

	fclose(file);
	free(buffer);

	selected_map = output;

	return output;

}

int get_tile_map(int x, int y){
	if (selected_map != NULL)
		return selected_map->data[y * selected_map->columns + x];
	else
		return 0;
}


void destroy_map(){

	if (selected_map == NULL) return;

	free(selected_map);

	selected_map = NULL;

}

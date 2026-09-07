# API: EXTRAS/MAPLOADER.H

## Definitions:

```
typedef struct {

        int rows, columns;
        int* data;
        size_t data_size;
} map;

map *selected_map = NULL;

```

## map * create_map(char* path)
Creates and loads a map into memory, also setting the amount of rows and columns in order to easily parse it.

Usage:
```c
map * level1 = create_map("path/to/map.csv);
````


## int get_tile_map(int x, int y)
Gets the value of a specific tile on our 2d map.

Usage:
```c
int tile = get_tile_map(3,5); // gets value at the 3rd column, 5th row.
```


## void destroy_map()
Destroys `selected_map`, freeing it's space in memory.

Usage:
```c
selected_map = level1;
destroy_map();
```

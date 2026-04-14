typedef struct {
	int grid[2], tile[4];
	texture source;

} tilemap;

tilemap * selected_tilemap = NULL;


tilemap * create_tilemap(int t_x, int t_y, int t_w, int t_h, int grid_x, int grid_y){
	tilemap * tile;
	tile=SDL_malloc(sizeof(*tile));

	tile->tile[0] = t_x;
	tile->tile[1] = t_y;
	tile->tile[2] = t_w;
	tile->tile[3] = t_h;

	tile->grid[0] = grid_x;
	tile->grid[1] = grid_y;

	selected_tilemap = tile;
	return tile;

}

void load_texture_tilemap(char * path){

	texture * old_selected = selected_texture;

	selected_texture = &selected_tilemap->source;

	load_texture(path);

	selected_texture = old_selected;

}


void draw_tile(int x, int y, int selected) {

	int total = selected_tilemap->grid[0] * selected_tilemap->grid[1];
	selected = selected % total;  // wraps

	int tile_x = selected % selected_tilemap->grid[0];
	int tile_y = selected / selected_tilemap->grid[0];

	SDL_FRect src = {
		selected_tilemap->tile[0] + tile_x * selected_tilemap->tile[2],		// X start + column offset
		selected_tilemap->tile[1] + tile_y * selected_tilemap->tile[3],		// Y start + row offset
		selected_tilemap->tile[2],											// tile width
		selected_tilemap->tile[3]											// tile height
	};

	// Destination rect: where to draw on screen
	SDL_FRect dst = {
		(float)x,
		(float)y,
		(float)selected_tilemap->tile[2],
		(float)selected_tilemap->tile[3]
	};

	SDL_RenderTexture(selected_window->renderer, selected_tilemap->source.texture_data, &src, &dst);
}




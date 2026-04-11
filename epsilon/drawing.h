#ifndef EPSILON_DRAWING_H
#define EPSILON_DRAWING_H


typedef struct {
	SDL_Texture *texture_data;
	int x, y;
	int mask[4];
	int scale[2];
	int angle;
	int origin_x, origin_y;
	bool loaded;

} texture;

texture *selected_texture = NULL;



void create_texture(texture * tex){

	tex->x = 0;
	tex->y = 0;
	tex->scale[0] = 1; tex->scale[1] = 1;
	tex->mask[0] = 0; tex->mask[1] = 0;
	tex->angle = 0;
	tex->origin_x = 0;
	tex->origin_y = 0;
	tex->loaded = false;

	selected_texture = tex;

	return;
}



void load_texture(const char* path){

	if(!selected_texture->loaded){

		SDL_Surface* surf = IMG_Load(path);
		if (!surf) {
			SDL_Log("Failed to load image: %s | %s", path, SDL_GetError());
			return;
		}

		selected_texture->texture_data = SDL_CreateTextureFromSurface( selected_window->renderer, surf );
		SDL_DestroySurface(surf);

		if (!selected_texture->texture_data) {
			SDL_Log("Failed to create texture: %s", SDL_GetError());
			return;
		}


		// I don't know why SDL wants to use floats on textures...
		float tex_w, tex_h;
		SDL_GetTextureSize(selected_texture->texture_data, &tex_w, &tex_h);

		selected_texture->mask[2] = tex_w;
		selected_texture->mask[3] = tex_h;

		selected_texture->loaded=true;

	}

}



void set_scale(int x, int y){
	selected_texture->scale[0]=x;
	selected_texture->scale[1]=y;
}


void set_mask(int x, int y, int w, int h){
	selected_texture->mask[0]=x;
	selected_texture->mask[1]=y;
	selected_texture->mask[2]=w;
	selected_texture->mask[3]=h;
}



void set_origin(int x, int y){
	selected_texture->origin_x=x;
	selected_texture->origin_y=y;
}



void draw_texture(int x, int y){
	texture * t = selected_texture;

	t->x = x;
	t->y = y;

	SDL_FRect mask = { t->mask[0], t->mask[1], t->mask[2], t->mask[3] };

	SDL_FRect dst = {
		x - t->mask[0] * t->scale[0],
		y - t->mask[1] * t->scale[1],
		t->mask[2] * t->scale[0],
		t->mask[3] * t->scale[1]
	};


	SDL_FPoint origin = {t->origin_x, t->origin_y};


	SDL_RenderTextureRotated(selected_window->renderer, t->texture_data, &mask, &dst, t->angle, &origin, SDL_FLIP_NONE);

}



void select_window(window * win){

	selected_window = win;
}



void draw_line(int x1, int y1, int x2, int y2 ){


	SDL_RenderLine(selected_window->renderer, x1, y1, x2, y2);


}



void draw_rect(int x, int y, int w, int h){
	SDL_FRect r;
	r.x=x;
	r.y=y;
	r.w=w;
	r.h=h;
	SDL_RenderFillRect( selected_window->renderer, &r );

}



void draw_point(int x, int y){

	SDL_RenderPoint(selected_window->renderer, x, y);
}



void render(){
		SDL_RenderPresent(selected_window->renderer);
}



void end_frame(){
	SDL_Delay(1000/60);
}



void set_render_color(uint32_t rgba){


	SDL_SetRenderDrawColor(
		selected_window->renderer,
		0xFF & (rgba >> 24),
		0xFF & (rgba >> 16),
		0xFF & (rgba >> 8),
		0xFF & rgba
	);
}


void clear_screen(){

	SDL_RenderClear(selected_window->renderer);


}

#endif

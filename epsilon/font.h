#ifndef EPSILON_DRAWING_FONTS_H
#define EPSILON_DRAWING_FONTS_H


typedef struct {
	TTF_Font *font_data;
	SDL_Color color;
	float scale;
	bool loaded;
} font;

font *selected_font = NULL;



void load_font(const char *path, int size) {
	if (!selected_font->loaded) {

		selected_font->font_data = TTF_OpenFont(path, size);

		if (!selected_font->font_data) {
			SDL_Log("Failed to load font: %s | %s", path, SDL_GetError());
			return;
		}
		selected_font->loaded = true;
	}
}



font *create_font(const char *path, int size) {
	font *f = SDL_malloc(sizeof(*f));

	f->color = (SDL_Color){ 255, 255, 255, 255 };
	f->scale  = 1.0f;
	f->loaded = false;

	selected_font = f;

	load_font(path, size);

	return f;
}



void set_font_color(uint32_t rgba) {

	selected_font->color = (SDL_Color){
		0xFF & (rgba >> 24),
		0xFF & (rgba >> 16),
		0xFF & (rgba >> 8),
		0xFF & rgba
	};
}



void set_font_scale(float scale) {
	selected_font->scale = scale;
}



void draw_text(const char *text, int x, int y) {
	font *f = selected_font;

	SDL_Surface *surf = TTF_RenderText_Solid(f->font_data, text, 0, f->color);
	if (!surf) return;

	float w = (float)surf->w * f->scale;
	float h = (float)surf->h * f->scale;

	SDL_Texture *tex = SDL_CreateTextureFromSurface(selected_window->renderer, surf);
	SDL_DestroySurface(surf);
	if (!tex) return;

	SDL_SetTextureScaleMode(tex, SDL_SCALEMODE_NEAREST);

	SDL_FRect dst = { (float)x, (float)y, w, h };
	SDL_RenderTexture(selected_window->renderer, tex, NULL, &dst);

	SDL_DestroyTexture(tex);
}



void destroy_font() {
	if (!selected_font) return;

	TTF_CloseFont(selected_font->font_data);
	SDL_free(selected_font);

	selected_font = NULL;
}

#endif

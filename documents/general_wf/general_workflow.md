# GENERAL WORKFLOW
Epsilon tries to keep things as simple as possible, that's why it follows some rules in terms of syntax and structure.


## OBJECT CREATION
At the time, Epsilon has 4 objects, **window**, **texture**, **audio** and **tilemap**.

### Game windows
1. create a window object
2. set values to it
3. create a window based on that object
~~~c
	window win;            // window object
	win.title="Epsilon";   // window title
	win.w=256;             // window width
	win.h=256;             // window height

	create_window(&win);   // creates a window based on our object.
                        // it also selects that window (using the selected_window pointer)
~~~

### Textures
1. create and load texture 
3. draw
4. render
~~~c
	texture * tex = create_texture("./path/to/sprite.png"); // path relative to the game executable in bin/
	draw_texture(10,25);      // draw the texture at x=10 and y=25
	render();                 // renders into the window
~~~
### Audio
1. create and load audio
2. play
~~~c
	audio * think = create_audio("./path/to/sound.wav", true); // second argument is pre-decode, better for sound effects. 
	audio_play();
~~~
### Tilemap
1. create a tilemap
2. load a texture to it
3. draw a tile
~~~c
// options are: (tile_x_offset, tile_y_offset, tile_width, tile_height, row_amount, column_amount)
tilemap * map1 = create_tilemap(0,0, 16,16, 8,4); // 16x16 tiles and 8 rows 4 columns tilemap. 
load_texture_tilemap("./path/to/tilemap.png");
draw_tile(10, 25, 16); // x position, y position and tile.
render();
~~~

   
## THE "CURRENTLY SELECTED" SYSTEM

Epsilon relies on a selection system, let's see an example:
~~~c
selected_texture = &player_texture;
draw_texture( 15,15 );                // draws the player texture at x=15, y=15

selected_texture = &enemy_texture;
draw_texture( 50, 15 );               // draws the enemy texture at x=50, y=15
~~~
"selected_texture" is actually a pointer, then you can decide what to do with the selected texture, either change it's parameters like scale or rotation, draw them, etc.
This system is used for almost everything in Epsilon, windows, textures, sounds and tilemaps; all of them use the "currently selected" system. 

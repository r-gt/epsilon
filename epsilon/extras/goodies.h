#ifndef GOODIES_H
#define GOODIES_H

#define deg 		0.017453292519943
#define rad 		57.29577951308230

#define tau			1.570796326794896
#define euler		2.718281828459045
#define golden		1.618033988749894
#define pythagoras	1.414213562373095




//
// BEGIN MATH FUNCTIONS
//

int wrap(int index, int range) {
	return ((index % range) + range) % range;
}


float lerp(float a, float b, float f){
	return a * (1.0 - f) + (b * f);
}


float clamp(float value, float min, float max){
	if (value < min) return min;
	else if( value > max) return max;
	else return value;

}



///
/// COLLISION
///

_Bool point_in_circle(int px, int py, int cx, int cy, int radius){


	int x = px-cx;
	int y = py-cy;

	// radius squared is faster than getting a square root.
	return ( x*x + y*y < radius*radius);
}





_Bool circle_in_circle(int circle_1_x, int circle_1_y, int circle_1_radius, int circle_2_x, int circle_2_y, int circle_2_radius){

	float d =	(circle_2_x - circle_1_x) * (circle_2_x - circle_1_x) +
	(circle_2_y - circle_1_y) * (circle_2_y - circle_1_y);

	return (d < (circle_1_radius + circle_2_radius)*(circle_1_radius + circle_2_radius));
}




int point_in_box(float px, float py, float bx, float by, float w, float h) {
	return (
		px >= bx 		&&
		px <= bx + w 	&&
		py >= by 		&&
		py <= by + h
	);
}





int box_in_box (int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2){

	// i guess this algorithm was called AABB

	return !(
		x1 > x2 + w2 - 1 ||
		y1 > y2 + h2 - 1 ||
		x2 > x1 + w1 - 1 ||
		y2 > y1 + h1 - 1
	);

}


void setbit(int *n, int k){
	*n = (*n | (1 << k));
}

// turn bit number k into "0"
void clearbit(int *n, int k){
	*n = (*n & (~(1 << k)));
}

// toggles bit number k state
void togglebit(int *n, int k){
	*n = (*n ^ (1 << k));
}

// set bit number k into 1 or 0
void modifybit(int *n, int k, int p){
	*n = (*n | (p << k));
}

// returns the state of bit number N
_Bool findbit(int n, int k){
	return ((n >> k) & 1);
}

#endif

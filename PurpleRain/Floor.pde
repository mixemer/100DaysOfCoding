class Floor {
 float x;
 float y = height-10;
 float z;
 float len = map(z, 0, 20, 2, 5);
 
 float rxspeed;
 float lxspeed;
 float yspeed;
 
 Floor(float x_, float len_, float z_ ) {
   x = x_;
   z = z_;
 }
 
 void update() {
   rxspeed += 0.5;
   lxspeed -= 0.5;
   
   yspeed -= 0.5;
   
   y += yspeed;
 }
 
 void show() {
   stroke(138, 43, 226);
   ellipse(x+rxspeed, y, len, len); // right
   ellipse(x+lxspeed, y, len, len); // left
 } 
 
}

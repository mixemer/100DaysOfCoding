class Start{
 float x;
 float y;
 float z;
 
 float pz;
 
 Start(){
  x = random(-width, width); 
  y = random(-height, height);
  z = random(width);
  pz = z;
 }
 
 void update(){
   z = z - speed;
   
   if(z < 1){
     z = width;
     x = random(-width, width); 
     y = random(-height, height);
     pz = z;
   }
 }
 
 color getColor(){
   float elapsed = random(100, 255);
   
   float r = (1 + cos(elapsed * 0.0001)) * 110;
   float b = (1 + sin(elapsed * 0.02)) * 110;
   float g = (1 + sin(elapsed * 0.03)) * 110;
   
   color c = color(r, g, b);
   return c;
 }
 
 void show() {
   fill(getColor());
   noStroke();
   
   float sx = map(x / z, 0, 1, 0, width);
   float sy = map(y / z, 0, 1, 0, height);
   
   float r = map(z, 0, width, 22, 0);
   ellipse(sx, sy, r ,r );
   
   float px = map(x / pz, 0, 1, 0, width);
   float py = map(y / pz, 0, 1, 0, height);
   
   pz = z;
   stroke(255);
   line(px, py, sx, sy );
   
 }
}

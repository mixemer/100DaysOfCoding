/*
Based on The Coding Train:
https://www.youtube.com/watch?v=LG8ZK-rRkXo&index=2&list=PLRqwX-V7Uu6ZiZxtDDRCi6uhfTH4FilpH
*/

float a = 0;
color c;
ArrayList<Box> sponge;
void setup() {
  size(400,400, P3D);
  sponge = new ArrayList<Box>();
  Box b = new Box(0,0,0,200);
  sponge.add(b);
}

void mousePressed() {
  ArrayList<Box> next = new ArrayList<Box>();
  for (Box b : sponge) {
     ArrayList<Box> newBoxes = b.generate();
     next.addAll(newBoxes);
  }
  sponge = next;
}

int value = 0;
void mouseMoved() 
{
  value = value + 5;
  if (value > 255) {
    value = 0;
  }
}

void draw() {
 background(51);
 stroke(255);
 fill(200,100,100);
 lights();
 
 translate(width/2, height/2);
 rotateX(a);
 rotateY(a * 0.4);
 rotateX(a * 0.1);

 for(Box b : sponge) {
   b.show();
 }
 
 a += 0.01;
}

/*
Based on The Coding Train vidoe
https://www.youtube.com/watch?v=17WoOqgXsRM&list=PLRqwX-V7Uu6ZiZxtDDRCi6uhfTH4FilpH
*/

Start[] starts = new Start[800];
float speed;
void setup(){
  size(1000, 800);
  for (int i = 0 ; i < starts.length; i++){
    starts[i] = new Start();
  }
}

void draw() {
  speed = map(mouseX, 0, width, 0 ,40 );
  background(0);
  translate(width/2, height/2);
  
  for (int i = 0 ; i < starts.length; i++){
    starts[i].update();
    starts[i].show();
  }
}

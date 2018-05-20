// Purple Rain
// (138, 43, 226)
// (230, 230, 250) // background

Drop[] drops;
ArrayList<Floor> floors;
void setup() {
  size(800, 400);
  drops = new Drop[500];
  for (int i = 0; i < drops.length; i++){
   drops[i] = new Drop(); 
  }
  
  floors = new ArrayList<Floor>();
}

void createFloor(float x, float len, float z) {
  floors.add(new Floor(x,len,z));
}

void draw() {
  background(230, 230, 250);
  for (int i = 0; i < drops.length; i++){
   drops[i].fall();
   drops[i].show();
   
   if(drops[i].y > height-2) {
     createFloor(drops[i].x, drops[i].leng, drops[i].z);
   }
  }
  
  for (int i = 0; i < floors.size(); i++){
    floors.get(i).update();
    floors.get(i).show();
  }
  
  for (int i = floors.size()-1; i >0 ; i--){
    //print(floors.get(i).y);
    if (floors.get(i).y < height - 20){
      floors.remove(i);
    }
  }
  
}

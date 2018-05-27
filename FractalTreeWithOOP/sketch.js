var len = 100;
var tree = [];
var leaves = [];

var count = 0;

function setup() {
    createCanvas(600, 400);

    var beginPoint = createVector(width / 2, height);
    var endPoint = createVector(width / 2, height - len);
    var root = new Branch(beginPoint, endPoint);

    tree[0] = root;
      
}

function mousePressed() {
    for (var i = tree.length-1; i >= 0 ; i--){
        if (!tree[i].finished && count < 6){
            tree.push(tree[i].branchRight());
            tree.push(tree[i].branchLeft()); 
        }    
        tree[i].finished = true;   
    }
    count++;

    if (count == 6) {
        for (var i = 0; i < tree.length; i++){
            if (!tree[i].finished){
                var pos = tree[i].end.copy();
                var leaf = new Leaf(pos);
                leaves.push(leaf);
            }       
        }
    }
}

function draw() {
    background(51);
    
    for (var i = 0; i < tree.length; i++){
        tree[i].show();
        //tree[i].jitter();        
    }
    for (var i = 0; i < leaves.length; i++){
        leaves[i].update();
        leaves[i].show();
    }
}
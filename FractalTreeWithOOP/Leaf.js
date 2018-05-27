function Leaf(pos) {
    this.pos = pos;
    this.r = 0;

    this.yspeed = random(0.5, 5);
    this.xspeed = -1;

    this.update = function() {
        if (this.r < 8) {
            this.r += 0.1;
        }else if(this.pos.y < height) {
            this.pos.y += this.yspeed;
            this.pos.x += this.xspeed;
        }
    }

    this.show = function() {
        fill(255, 0, 100);
        noStroke();
        ellipse(this.pos.x, this.pos.y, this.r, this.r);

    }
}
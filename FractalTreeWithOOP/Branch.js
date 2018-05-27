
function Branch(begin, end) {
    this.begin = begin; // begining point of branch
    this.end = end; // end point of branch
    this.finished = false;

    this.jitter = function() {
        this.end.x += random(-1, 1);
        this.end.y += random(-1, 1);
        
    }

    this.show = function() {
        stroke(255);
        line(this.begin.x, this.begin.y, this.end.x, this.end.y);
    }

    this.branchRight = function() {
        var dir = p5.Vector.sub(this.end, this.begin);
        dir.rotate(PI / 6);
        dir.mult(0.67);
        var newEnd = p5.Vector.add(this.end, dir);

        var right = new Branch(this.end,newEnd );
        return right;
    }

    this.branchLeft = function() {
        var dir = p5.Vector.sub(this.end, this.begin);
        dir.rotate(-PI / 4);
        dir.mult(0.67);        
        var newEnd = p5.Vector.add(this.end, dir);

        var left = new Branch(this.end,newEnd );
        return left;
    }
}

function setup() {
	createCanvas(600,500);
	background(255)
	
	sm = new shapeManager()
  
}

function draw() {

	background(209, 237, 202)
	sm.drawShapes()
	

	if (mouseIsPressed) {
	    if (mouseButton === LEFT) {
	    	console.log('left')
			x = max(50, min(mouseX, width - 50))
			y = max(50, min(mouseY, height - 50))
			fill(44, 77, 34)
			ellipse(x, y,100)
			

		}
	    if(mouseButton === CENTER){
	    	if(x != 0){
				sm.add_ellipse(x, y, 100)
				x = 0
			}



	    }
	   
	}


}

function keyPressed() {
  if (keyCode === 32) {
    sm.shapes = []
    sm.count = 0
  } 
  if (keyCode === ENTER) {
  	let c = 0
  	let data = []
  	for (i in sm.shapes){
  		data[c] =  sm.shapes[i][0] + " " +sm.shapes[i][1] + " " +sm.shapes[i][2] 
  		c = c + 1
  	}
     
    saveStrings(data, 'out.txt')

  } 
  return false; // prevent default
}




function shapeManager(){
	this.shapes = []
	this.count = 0

	this.add_ellipse = function(x, y, r){
		this.shapes[this.count] = [x,y,r]
		this.count = this.count + 1
		print(this.shapes)
	}

	this.drawShapes = function(){
		for (shp in this.shapes){
			print("shape: ")
			print(this.shapes[shp])
			fill(44, 77, 34)
			ellipse(this.shapes[shp][0],this.shapes[shp][1],this.shapes[shp][2])
		}
	}
}


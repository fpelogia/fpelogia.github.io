let x_room = 6;
let y_room = 6;
let x_catch;
let y_catch;
let go_on;
let pg;
let inx1;
let iny1;
let inx2;
let iny2;
let inx3;
let iny3;
let inx4;
let iny4;
let x1 = 0;
let y1 = 0;
let x2 = 0;
let y2 = 0;
let x3 = 0;
let y3 = 0;
let x4 = 0;
let y4 = 0;
let x_opt = [];

let r = 1;
let all_ok = false;

let txt;
let sh_caller;
let opt_view_btn;
let sh_generator;

let sh_txt = "";

function generate_sh(){
	sh_txt = "#!/bin/bash\ngcc -O3 code/packing_4.c -L/home/fpelogia/algencan/lib -lalgencan -lgfortran -lm   -o algencan\n./algencan "
	sh_txt = sh_txt + x_room/100.0 + " " + y_room/100.0;
	sh_txt = sh_txt + " " + inx1.value();
	sh_txt = sh_txt + " " + iny1.value();
	sh_txt = sh_txt + " " + inx2.value();
	sh_txt = sh_txt + " " + iny2.value();
	sh_txt = sh_txt + " " + inx3.value();
	sh_txt = sh_txt + " " + iny3.value();
	sh_txt = sh_txt + " " + inx4.value();
	sh_txt = sh_txt + " " + iny4.value();
	
	saveStrings(split(sh_txt, "\n"), 'opt', 'sh', false)

	
}





function continue_creating(){

	

	
	x_room = 100*Number(x_catch.value());

	y_room = 100*Number(y_catch.value());

	generate_sh();

	x_catch.remove();
	y_catch.remove();
	inx1.remove();
	iny1.remove();
	inx2.remove();
	iny2.remove();
	inx3.remove();
	iny3.remove();
	inx4.remove();
	iny4.remove();


	canvas = createCanvas(x_room,y_room);
	canvas.center()
	x1 = 100*Number(inx1.value());
	y1 = height - 100*Number(iny1.value());

	x2 = 100*Number(inx2.value());
	y2 = height - 100*Number(iny2.value());

	x3 = 100*Number(inx3.value());
	y3 = height - 100*Number(iny3.value());

	x4 = 100*Number(inx4.value());
	y4 = height - 100*Number(iny4.value());


	

	background(255)
	
	sm = new shapeManager()

	let txt_dim = select('#txt_dim');
	txt_dim.remove();
	let txt_c = select('#txt_centers');
	txt_c.remove();


	opt_load_btn = select('#load_opt')
	opt_load_btn.mousePressed(loadOpt)


	opt_view_btn = select('#show_opt')
	opt_view_btn.mousePressed(opt_view)



	all_ok = true;
	print(sh_txt)
}

function loadOpt(){
	txt = loadStrings("http://localhost:8080/SOLUTION.TXT")
	print('Posições otimizadas carregadas com sucesso.')
}



function setup() {

	x_catch = select('#xtxt');
	y_catch = select('#ytxt');
	inx1 = select('#x1')
	iny1 = select('#y1')
	inx2 = select('#x2')
	iny2 = select('#y2')
	inx3 = select('#x3')
	iny3 = select('#y3')
	inx4 = select('#x4')
	iny4 = select('#y4')


	go_on = select('#btn');
	go_on.mousePressed(continue_creating)
	

}

function draw() {
	if(all_ok == true){
		go_on.remove();
		//background(209, 237, 202)
		fill(0)
		ellipse(x1,y1, 200)
		ellipse(x2,y2, 200)
		ellipse(x3,y3, 200)
		ellipse(x4,y4, 200)



		// sm.drawShapes()
		

		// if (mouseIsPressed) {
		//     if (mouseButton === LEFT) {
		//     	console.log('left')
		// 		x = max(50, min(mouseX, width - 50))
		// 		y = max(50, min(mouseY, height - 50))
		// 		fill(44, 77, 34)
		// 		ellipse(x, y,100)
				

		// 	}
		//     if(mouseButton === CENTER){
		//     	if(x != 0){
		// 			sm.add_ellipse(x, y, 100)
		// 			x = 0
		// 		}



		//     }
		   
		// }
	}


}


//function keyPressed() {
  // if (keyCode === 32) {
  //   sm.shapes = []
  //   sm.count = 0
  // } 
  // if (keyCode === ENTER) {
  // 	let c = 0
  // 	let data = []
  // 	for (i in sm.shapes){
  // 		data[c] =  sm.shapes[i][0] + " " +sm.shapes[i][1] + " " +sm.shapes[i][2] 
  // 		c = c + 1
  // 	}
     
  //   saveStrings(data, 'out.txt')

  // }

 // return false; 
//}

function opt_view(){
	for (let i = 4; i<=11; i++){
		x_opt[i-4] = Number(txt[i].split(' ')[8].substring(0,18));
	}
  	background(255)
  	x1 = 100*x_opt[0]
  	y1 = 100*x_opt[1]
  	x2 = 100*x_opt[2]
  	y2 = 100*x_opt[3]
  	x3 = 100*x_opt[4]
  	y3 = 100*x_opt[5]
  	x4 = 100*x_opt[6]
  	y4 = 100*x_opt[7]
}


function shapeManager(){
	this.shapes = []
	this.count = 0

	this.add_ellipse = function(x, y, r){
		this.shapes[this.count] = [x,y,r]
		this.count = this.count + 1
	}

	this.drawShapes = function(){
		for (shp in this.shapes){
			fill(44, 77, 34)
			ellipse(this.shapes[shp][0],this.shapes[shp][1],this.shapes[shp][2])
		}
	}
}


let angle = 0;
let img;
let cam;
let cam_or_img = 1;
let ball_or_cube = 0;

function preload(){
    img = loadImage('planet.png');
}


function setup() {
    createCanvas(600, 500, WEBGL);
    cam = createCapture(VIDEO);
    cam.hide();
}

function draw() {
    background(175);
    //translate(mouseX-width/2, mouseY-height/2 );
    //directionalLight(255,0,200,-100,-100,-100);

    push();
    rotateY(angle);
    rotateY(angle*0.1);
    rotateZ(angle*0.2);
    rectMode(CENTER);
    //rect(0,0,250,200);
    
    //fill(255,0,150);
    //normalMaterial();
    //pointLight(255,255,255,-200,0,200);
    let dx = 5;
    let dy = 10;
    let v = createVector(dx,dy,0);
    v.normalize();

    //ambientMaterial(255,255,0);
    texture(returnCI());
    //box(150);
    if(ball_or_cube == 0){
        sphere(150);
    }else{
        box(150);
    }
    pop();

    directionalLight(98, 29, 163,v);
    push();
    rotateX(PI/3);
    rotateZ(angle*0.15);
    rotateY(angle*0.05);
    specularMaterial(255,255,255);
    torus(190,25);
    pop();


    translate(0,100);
    rotateX(HALF_PI);
    noStroke();
    //plane(500,500);
    //sphere(100);
    angle += 0.07;
}

function keyPressed() {
    if (keyCode === ENTER) {
        if(cam_or_img == 0){
            cam_or_img = 1;
        }else{
            cam_or_img = 0;
        }    
    }else if(keyCode === 32){
        if(ball_or_cube == 0){
            ball_or_cube = 1;
        }else{
            ball_or_cube = 0;
        }    
    }
}

function returnCI(){
    if(cam_or_img == 0){
        return cam;
    }else{
        return img;
    }
}
    

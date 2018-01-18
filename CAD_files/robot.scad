include <RoundedBox.scad>





//smartphoneBracket();
module smartphoneBracket(){
    difference(){
        union(){
    translate([0,0,-30])
    roundedBox([155,15,20],3,false);
            x=5;
             translate([67.5+x,0,0])
    roundedBox([10,15,60],3,false);
             translate([-67.5-x,0,0])
    roundedBox([10,15,60],3,false);
            
             translate([0,10,-16])
    roundedBox([20,15,48],3,false);
            translate([0,30,5])
    roundedBox([20,40,5],2,false);
            
             translate([0,45,5])
    roundedBox([40,10,5],1,false);
     }
    LGk8();
        
    }
}


//%LGk8();
module LGk8(){
    cube([145, 8.7, 72],center=true);
    cube([190, 7, 40],center=true);
    cube([110, 20, 62],center=true);
}

//translate([35,0,-5])
//standoff();
module standoff(){
    difference(){
        cylinder(h=30, r=4, center=true, $fn=6);
        cylinder(h=35, r=1.5, center=true, $fn=60);
    }
}

servoMG995adapter();
module servoMG995adapter(){
    difference(){
        cube([60,30,4],center=true);
        servoMG995();
        translate([25,5,0])
        cylinder(h=10, d=3, center=true, $fn=50);
         translate([25,-5,0])
        cylinder(h=10, d=3, center=true, $fn=50);
         translate([-25,5,0])
        cylinder(h=10, d=3, center=true, $fn=50);
         translate([-25,-5,0])
        cylinder(h=10, d=3, center=true, $fn=50);
        
    }
}

//servoMG995();
module servoMG995(){
    cube([41,20,40],center=true);
    translate([0,0,10])
    difference(){
        cube([55,19,4],center=true);
        translate([25,5,0]){
            cylinder(h=100, r=3, center=true, $fn=20);
        }
        translate([25,-5,0]){
            cylinder(h=100, r=3, center=true, $fn=20);
        }
        translate([-25,5,0]){
            cylinder(h=100, r=3, center=true, $fn=20);
        }
        translate([-25,-5,0]){
            cylinder(h=100, r=3, center=true, $fn=20);
        }
    }
    translate([9,0,5]){
    cylinder(h=45, r=9.5/2, center=true, $fn=40);
    translate([0,0,21])
    cube([56,13.5,4], center=true);
    }    
}

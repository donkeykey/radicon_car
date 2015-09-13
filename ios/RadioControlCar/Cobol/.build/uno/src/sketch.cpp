#include <Arduino.h>

void setup();
void loop();
void setting();
void setA();
void setB();
void setC();
void setD();
void setE();
void setF();
void setG();
#line 1 "src/sketch.ino"
String str = "";
String direction_command = "";
String button_command = "";

void setup(){
	Serial.begin(9600);
	pinMode(9,OUTPUT);
	pinMode(10,OUTPUT);
	pinMode(11,OUTPUT);
}

void loop(){
	char c;
	if (Serial.available() > 0)	{
		c = Serial.read();
		str += c;
	}
	if (c == '~') { //connect して最後に送られてくるやつ
		str = "";
	} else if (c == ',') { //コマンドのデリミタ
		str.replace(",","");
		direction_command = str;
		str = "";
	} else if (c == '^') { //コマンドの最後に送られてくるやつ
		str.replace("^","");
		button_command = str;
		str = "";
		Serial.print("color : ");
		Serial.println(direction_command);
		Serial.print("pattern : ");
		Serial.println(button_command);
		setting();
	}
	//run();
}

void setting(){
	if (direction_command == "A") { // White
		setA();
	} else if (direction_command == "B") {
		setB();
	} else if (direction_command == "C") {
		setC();
	} else if (direction_command == "D") {
		setD();
	} else if (direction_command == "E") {
		setE();
	} else if (direction_command == "F") {
		setF();
	} else if (direction_command == "G") {
		setG();
	} else {
		setG();
	}
}

void setA(){
	digitalWrite(10, true);
	digitalWrite(11, false);
}

void setB(){
	digitalWrite(10, true);
	digitalWrite(11, false);
}

void setC(){
	digitalWrite(10, false);
	digitalWrite(11, true);
}

void setD(){
	digitalWrite(10, false);
	digitalWrite(11, true);
}

void setE(){
	digitalWrite(10, false);
	digitalWrite(11, true);
}

void setF(){
	digitalWrite(10, true);
	digitalWrite(11, false);
}

void setG(){
	digitalWrite(10, true);
	digitalWrite(11, true);
}

/*
void run(){
	//set pattern
	if (direction_command == "S") { //Solid
		lightSolid();
	} else if(direction_command == "F") { //flush
		lightFlush();
	} else if(direction_command == "f") { //fade
		lightFade();
	} else if(direction_command == "R") { //Rotate
		lightRotation();
	} else {
		lightSolid();
	}
}
*/

/*
void setA(){
	red = false;
	green = true;
	blue = true;
}
void setB(){
	red = true;
	green = false;
	blue = true;
}
void setC(){
	red = true;
	green = true;
	blue = false;
}
void setD(){
	red = false;
	green = false;
	blue = true;
}
void setE(){
	red = false;
	green = true;
	blue = false;
}
void setF(){
	red = true;
	green = false;
	blue = false;
}
void setG(){
	red = false;
	green = false;
	blue = false;
}
*/

/*
void lightSolid(){
	digitalWrite(red1,  red);
	digitalWrite(green1,green);
	digitalWrite(blue1, blue);
	digitalWrite(red2,  red);
	digitalWrite(green2,green);
	digitalWrite(blue2, blue);
	digitalWrite(red3,  red);
	digitalWrite(green3,green);
	digitalWrite(blue3, blue);
	digitalWrite(red4,  red);
	digitalWrite(green4,green);
	digitalWrite(blue4 ,blue);
}
void lightFlush(){
	digitalWrite(red1,  red);
	digitalWrite(green1,green);
	digitalWrite(blue1, blue);
	digitalWrite(red2,  red);
	digitalWrite(green2,green);
	digitalWrite(blue2, blue);
	digitalWrite(red3,  red);
	digitalWrite(green3,green);
	digitalWrite(blue3, blue);
	digitalWrite(red4,  red);
	digitalWrite(green4,green);
	digitalWrite(blue4 ,blue);
	delay(100);
	digitalWrite(red1,  true);
	digitalWrite(green1,true);
	digitalWrite(blue1, true);
	digitalWrite(red2,  true);
	digitalWrite(green2,true);
	digitalWrite(blue2, true);
	digitalWrite(red3,  true);
	digitalWrite(green3,true);
	digitalWrite(blue3, true);
	digitalWrite(red4,  true);
	digitalWrite(green4,true);
	digitalWrite(blue4 ,true);
	delay(100);
}
void lightFade(){
	for(int a = 0;a<=15;a++){
		digitalWrite(red1,  red);
		digitalWrite(green1,green);
		digitalWrite(blue1, blue);
		digitalWrite(red2,  red);
		digitalWrite(green2,green);
		digitalWrite(blue2, blue);
		digitalWrite(red3,  red);
		digitalWrite(green3,green);
		digitalWrite(blue3, blue);
		digitalWrite(red4,  red);
		digitalWrite(green4,green);
		digitalWrite(blue4 ,blue);
		delay(a);
		digitalWrite(red1,  true);
		digitalWrite(green1,true);
		digitalWrite(blue1, true);
		digitalWrite(red2,  true);
		digitalWrite(green2,true);
		digitalWrite(blue2, true);
		digitalWrite(red3,  true);
		digitalWrite(green3,true);
		digitalWrite(blue3, true);
		digitalWrite(red4,  true);
		digitalWrite(green4,true);
		digitalWrite(blue4 ,true);
		delay(15 - a);
	}
	for(int a = 15;a>=0;a--){
		digitalWrite(red1,  red);
		digitalWrite(green1,green);
		digitalWrite(blue1, blue);
		digitalWrite(red2,  red);
		digitalWrite(green2,green);
		digitalWrite(blue2, blue);
		digitalWrite(red3,  red);
		digitalWrite(green3,green);
		digitalWrite(blue3, blue);
		digitalWrite(red4,  red);
		digitalWrite(green4,green);
		digitalWrite(blue4 ,blue);
		delay(a);
		digitalWrite(red1,  true);
		digitalWrite(green1,true);
		digitalWrite(blue1, true);
		digitalWrite(red2,  true);
		digitalWrite(green2,true);
		digitalWrite(blue2, true);
		digitalWrite(red3,  true);
		digitalWrite(green3,true);
		digitalWrite(blue3, true);
		digitalWrite(red4,  true);
		digitalWrite(green4,true);
		digitalWrite(blue4 ,true);
		delay(15 - a);
	}
}
void lightRotation(){
	digitalWrite(red1,  red  );
	digitalWrite(green1,green);
	digitalWrite(blue1, blue );
	digitalWrite(red2,  true );
	digitalWrite(green2,true );
	digitalWrite(blue2, true );
	digitalWrite(red3,  true );
	digitalWrite(green3,true );
	digitalWrite(blue3, true );
	digitalWrite(red4,  true );
	digitalWrite(green4,true );
	digitalWrite(blue4, true );
	delay(90);
	digitalWrite(red1,  true );
	digitalWrite(green1,true );
	digitalWrite(blue1, true );
	digitalWrite(red2,  red  );
	digitalWrite(green2,green);
	digitalWrite(blue2, blue );
	digitalWrite(red3,  true );
	digitalWrite(green3,true );
	digitalWrite(blue3, true );
	digitalWrite(red4,  true );
	digitalWrite(green4,true );
	digitalWrite(blue4, true );
	delay(90);
	digitalWrite(red1,  true);
	digitalWrite(green1,true);
	digitalWrite(blue1, true);
	digitalWrite(red2,  true );
	digitalWrite(green2,true );
	digitalWrite(blue2, true );
	digitalWrite(red3,  true );
	digitalWrite(green3,true );
	digitalWrite(blue3, true );
	digitalWrite(red4,  red );
	digitalWrite(green4,green );
	digitalWrite(blue4, blue);
	delay(90);
	digitalWrite(red1,  true );
	digitalWrite(green1,true );
	digitalWrite(blue1, true );
	digitalWrite(red2,  true );
	digitalWrite(green2,true );
	digitalWrite(blue2, true );
	digitalWrite(red3,  red  );
	digitalWrite(green3,green);
	digitalWrite(blue3, blue );
	digitalWrite(red4,  true );
	digitalWrite(green4,true );
	digitalWrite(blue4, true );
	delay(90);
}
*/



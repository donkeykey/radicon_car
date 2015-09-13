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

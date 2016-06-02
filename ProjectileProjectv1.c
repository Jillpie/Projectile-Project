

//varlibes:

int MOTORMAXPOWER = 127;

int MOTORCALIPOWER = 25;

int BESTANGLEPOT = 500;

int BESTANGLETHRESHPOT = 100;

//Functions:

void simpleAngleControl(){
	if(SensorValue(buttonUpAngle) == 1){
		startMotor(motorAngle,-MOTORMAXPOWER);
	}
	if(SensorValue(buttonDownAngle) == 1){
		startMotor(motorAngle,MOTORMAXPOWER);
	}
	if(SensorValue(buttonUpAngle) == 0 && SensorValue(buttonDownAngle) == 0){
		startMotor(motorAngle,0);
	}
}

void simpleComplexAngleControl(){
	if(SensorValue(potAngle) < BESTANGLEPOT - BESTANGLETHRESHPOT){
		startMotor(motorAngle,MOTORCALIPOWER);
	}
	if(SensorValue(potAngle) > BESTANGLEPOT + BESTANGLETHRESHPOT){
		startMotor(motorAngle,-MOTORCALIPOWER);
	}
	if(SensorValue(potAngle) > BESTANGLEPOT + BESTANGLETHRESHPOT/2 || SensorValue(potAngle) < BESTANGLEPOT - BESTANGLETHRESHPOT/2){
		startMotor(motorAngle,0);
	}
}

void simpleComplexAngleControlCali(){
	if(SensorValue(buttonUpAngle) == 1){
		startMotor(motorAngle,-MOTORCALIPOWER);
	}
	if(SensorValue(buttonDownAngle) == 1){
		startMotor(motorAngle,MOTORCALIPOWER);
	}
	if(SensorValue(buttonUpAngle) == 0 && SensorValue(buttonDownAngle) == 0){
		startMotor(motorAngle,0);
	}
}

void launcherKick(){
	if(SensorValue(limitLaunch) == 1){
		startMotor(motorLaunch,MOTORMAXPOWER);
	}
	if(SensorValue(limitLaunch) == 0){
		startMotor(motorLaunch,0);
	}
}


task main(){
	simpleAngleControl();
	//simpleComplexAngleControl();
	//simpleComplexAngleControlCali();
	launcherKick();
}
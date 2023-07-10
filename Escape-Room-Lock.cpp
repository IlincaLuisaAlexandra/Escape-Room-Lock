#include <SD.h>
#include <TMRpcm.h>
#include <SPI.h>

const int SD_CS = 10;
const int Broche_HP = 9;

char fichier[8] = "CH16.wav";

TMRpcm tmrpcm;

void setup() {
	Serial.begin(9600);

	if(!SD.begin(SD_CS)) {
		Serial.println("SD fail");
		return;
	} else {
		Serial.println("SD ok");
	}

	tmrpcm.speakerPin = Broche.HP;
	tmrpcm.setVolume(7);
}

void loop() {
	if(digitalRead(3)==LOW) {
		Serial.println("Play sound");
		tmrpcm.play("CH16.wav");
		while(tmrpcm.isPlaying()) {}
		delay(2000);
	}
}
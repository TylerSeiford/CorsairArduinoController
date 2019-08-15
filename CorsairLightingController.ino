/*
 Name:		CorsairLightingController.ino
 Created:	5/24/2019 8:35:34 PM
 Author:	Tyler
*/

#include "DCFan.h"
#include "CommanderPro.h"
#include "DCFan.h"

constexpr uint8_t LEDS_PER_CHANNEL = 10;

constexpr uint8_t FAN_1_TACH = 2;
constexpr uint8_t FAN_1_PIN = 3;

constexpr uint8_t FAN_2_PIN = 5;
constexpr uint8_t FAN_2_TACH = 7;

constexpr uint8_t CHANNEL_1_PIN = 4;
constexpr uint8_t CHANNEL_2_PIN = 8;

constexpr uint8_t RED_PIN = 6;
constexpr uint8_t GREEN_PIN = 9;
constexpr uint8_t BLUE_PIN = 10;


CommanderPro<LEDS_PER_CHANNEL>* cp;

void setup() {
	cp = new CommanderPro<LEDS_PER_CHANNEL>(true);

	FastLED.addLeds<TM1803, CHANNEL_2_PIN, GBR>(cp->channel2, LEDS_PER_CHANNEL);
	FastLED.addLeds<TM1803, CHANNEL_1_PIN, GBR>(cp->channel1, LEDS_PER_CHANNEL);

	pinMode(RED_PIN, OUTPUT);
	pinMode(GREEN_PIN, OUTPUT);
	pinMode(BLUE_PIN, OUTPUT);

	//cp->addFan(0, new DCFan(FAN_1_PIN, 0, 950));
	//cp->addFan(1, new DCFan(FAN_2_PIN, 0, 950));
}

void loop() {
	if (cp->update()) {
		FastLED.show();

		analogWrite(RED_PIN, cp->channel1->r);
		analogWrite(GREEN_PIN, cp->channel1->g);
		analogWrite(BLUE_PIN, cp->channel1->b);
	}
	else {
		delay(3);
	}
}
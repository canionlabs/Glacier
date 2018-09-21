/*
* @Author: caiovictormc
* @Date:   2018-09-19 21:35:08
* @Last Modified by:   caiovictormc
* @Last Modified time: 2018-09-20 22:28:56
*/

#include "Glacier.h"


Glacier::Glacier() : irsend(G_OUTPUT_IR), powerStatus(false) {
}

void Glacier::begin() {
	irsend.begin();
	pinMode(G_OUTPUT_LED, OUTPUT);
}

bool Glacier::getStatus() {
	return powerStatus;
}

void Glacier::powerOn() {
	uint16_t rawData[229] = {9094, 4588,  524, 1782,  504, 1780,  530, 620,  502, 658,  530, 620,  530, 620,  502, 648,  530, 1762,  530, 618,  530, 1752,  502, 1780,  528, 630,  502, 648,  502, 648,  502, 648,  530, 630,  530, 622,  528, 622,  532, 1752,  530, 630,  502, 1780,  504, 648,  500, 650,  502, 658,  502, 1782,  502, 1780,  528, 622,  528, 632,  528, 1754,  502, 1780,  530, 1754,  500, 658,  506, 646,  502, 648,  528, 622,  530, 630,  500, 650,  502, 648,  502, 650,  500, 658,  500, 648,  508, 644,  502, 650,  502, 658,  530, 620,  506, 644,  500, 650,  502, 652,  502, 8172,  528, 604,  522, 652,  530, 624,  502, 650,  530, 622,  504, 650,  530, 622,  502, 650,  502, 650,  502, 650,  526, 626,  502, 650,  506, 646,  500, 652,  502, 650,  502, 650,  506, 646,  500, 652,  502, 650,  502, 650,  500, 652,  502, 650,  502, 650,  528, 624,  530, 622,  502, 650,  526, 626,  500, 652,  502, 652,  500, 650,  530, 622,  502, 650,  502, 652,  528, 602,  522, 650,  502, 652,  502, 650,  502, 650,  532, 622,  502, 650,  502, 652,  502, 650,  502, 650,  502, 650,  528, 624,  530, 622,  532, 620,  502, 650,  502, 652,  502, 650,  502, 652,  500, 650,  530, 622,  502, 652,  500, 652,  526, 684,  526, 1756,  530, 1752,  528, 1754,  502, 658,  530, 620,  502, 1782,  502, 1780,  532, 624,  502};  // UNKNOWN 683D2DFF
	sendIR(rawData);
	powerStatus = true;
}

void Glacier::powerOff() {
	uint16_t rawData[229] = {9094, 4588,  524, 1782,  504, 1780,  530, 620,  502, 658,  530, 620,  530, 620,  502, 648,  530, 1762,  530, 618,  530, 1752,  502, 1780,  528, 630,  502, 648,  502, 648,  502, 648,  530, 630,  530, 622,  528, 622,  532, 1752,  530, 630,  502, 1780,  504, 648,  500, 650,  502, 658,  502, 1782,  502, 1780,  528, 622,  528, 632,  528, 1754,  502, 1780,  530, 1754,  500, 658,  506, 646,  502, 648,  528, 622,  530, 630,  500, 650,  502, 648,  502, 650,  500, 658,  500, 648,  508, 644,  502, 650,  502, 658,  530, 620,  506, 644,  500, 650,  502, 652,  502, 8172,  528, 604,  522, 652,  530, 624,  502, 650,  530, 622,  504, 650,  530, 622,  502, 650,  502, 650,  502, 650,  526, 626,  502, 650,  506, 646,  500, 652,  502, 650,  502, 650,  506, 646,  500, 652,  502, 650,  502, 650,  500, 652,  502, 650,  502, 650,  528, 624,  530, 622,  502, 650,  526, 626,  500, 652,  502, 652,  500, 650,  530, 622,  502, 650,  502, 652,  528, 602,  522, 650,  502, 652,  502, 650,  502, 650,  532, 622,  502, 650,  502, 652,  502, 650,  502, 650,  502, 650,  528, 624,  530, 622,  532, 620,  502, 650,  502, 652,  502, 650,  502, 652,  500, 650,  530, 622,  502, 652,  500, 652,  526, 684,  526, 1756,  530, 1752,  528, 1754,  502, 658,  530, 620,  502, 1782,  502, 1780,  532, 624,  502};  // UNKNOWN 683D2DFF
	sendIR(rawData);
	powerStatus = false;
}

void Glacier::setTurbo() {
	uint16_t rawData[229] = {9094, 4588,  524, 1782,  504, 1780,  530, 620,  502, 658,  530, 620,  530, 620,  502, 648,  530, 1762,  530, 618,  530, 1752,  502, 1780,  528, 630,  502, 648,  502, 648,  502, 648,  530, 630,  530, 622,  528, 622,  532, 1752,  530, 630,  502, 1780,  504, 648,  500, 650,  502, 658,  502, 1782,  502, 1780,  528, 622,  528, 632,  528, 1754,  502, 1780,  530, 1754,  500, 658,  506, 646,  502, 648,  528, 622,  530, 630,  500, 650,  502, 648,  502, 650,  500, 658,  500, 648,  508, 644,  502, 650,  502, 658,  530, 620,  506, 644,  500, 650,  502, 652,  502, 8172,  528, 604,  522, 652,  530, 624,  502, 650,  530, 622,  504, 650,  530, 622,  502, 650,  502, 650,  502, 650,  526, 626,  502, 650,  506, 646,  500, 652,  502, 650,  502, 650,  506, 646,  500, 652,  502, 650,  502, 650,  500, 652,  502, 650,  502, 650,  528, 624,  530, 622,  502, 650,  526, 626,  500, 652,  502, 652,  500, 650,  530, 622,  502, 650,  502, 652,  528, 602,  522, 650,  502, 652,  502, 650,  502, 650,  532, 622,  502, 650,  502, 652,  502, 650,  502, 650,  502, 650,  528, 624,  530, 622,  532, 620,  502, 650,  502, 652,  502, 650,  502, 652,  500, 650,  530, 622,  502, 652,  500, 652,  526, 684,  526, 1756,  530, 1752,  528, 1754,  502, 658,  530, 620,  502, 1782,  502, 1780,  532, 624,  502};  // UNKNOWN 683D2DFF
	sendIR(rawData);
	powerStatus = true;
}

void Glacier::notifyLed() {
	digitalWrite(G_OUTPUT_LED, HIGH);
	delay(100);
	digitalWrite(G_OUTPUT_LED, LOW);
}

void Glacier::sendIR(uint16_t *rawCode) {
	irsend.sendRaw(rawCode, 229, 38000);
}
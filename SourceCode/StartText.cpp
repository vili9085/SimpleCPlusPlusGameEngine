#include "StartText.h"



using namespace preydator;

void StartText::init() {
	myText = getComponent<Text>();
	myText->editText(false);
}

void StartText::update() {

}

StartText::StartText() {

}

StartText::~StartText() {

}
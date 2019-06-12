#include "StartText2.h"
#include "SceneManager.h"

using namespace preydator;

void StartText2::init() {
	myText = getComponent<Text>();
	myText->editText(true);
}

void StartText2::update() {
	if (input.getKey(InputKeys::ENTER)) {
		sceneManager.loadScene(1);

	}
}

StartText2::StartText2() {

}

StartText2::~StartText2() {

}

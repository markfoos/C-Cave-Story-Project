#include "input.h"

//keep track of the state of the keyboard

//this functon that's called at the beginning of each frame to clear nonrelevent key strokes

void Input::beginNewFrame() {
	this->_pressedKeys.clear();
	this->_releasedKeys.clear();
}

//this function is called when a key is pressed.
void Input::keyDownEvent(const SDL_Event& event) {
	this->_pressedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = true;

}
//this function is called when a key is released
void Input::keyUpEvent(const SDL_Event& event) {
	this->_releasedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = false;
}
//check is key was pressed in the current frame.
bool Input::wasKeyPressed(SDL_Scancode key) {
	return this->_pressedKeys[key];
}

//check and see if key is released in current frame
bool Input::wasKeyReleased(SDL_Scancode key) {
	return this->_releasedKeys[key];
}

//check if key is currently being held.
bool Input::isKeyHeld(SDL_Scancode key) {
	return this->_heldKeys[key];
}
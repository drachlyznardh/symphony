#include "Input.hpp"

using namespace Polycode;
using namespace tbd;

tbd::Input::Input() {
    up = down = left = right = 0.0;
    x = y = 0.0;
	alive = true;
}

void tbd::Input::changeInput(Core* core) {
    CoreInput* c = core->getInput();
    get()->xres = core->getXRes();
    get()->yres = core->getYRes();
    c->addEventListener(get(), InputEvent::EVENT_KEYDOWN);
    c->addEventListener(get(), InputEvent::EVENT_KEYUP);
    c->addEventListener(get(), InputEvent::EVENT_MOUSEMOVE);
    c->addEventListener(get(), InputEvent::EVENT_MOUSEDOWN);
    c->addEventListener(get(), InputEvent::EVENT_MOUSEUP);
}

Input* tbd::Input::get() {
    static Input input;
    return &input;
}

double tbd::Input::Up() {
    return up;
}

double tbd::Input::Down() {
    return down;
}

double tbd::Input::Left() {
    return left;
}

double tbd::Input::Right() {
    return right;
}

bool tbd::Input::isAlive() {
	return alive;
}

bool tbd::Input::isButton1() {
    return button1;
}

double tbd::Input::X() {
    return x;
}

double tbd::Input::Y() {
    return y;
}

void tbd::Input::handleEvent(Polycode::Event *e) {
    InputEvent *inputEvent = (InputEvent*) e;
    switch (e->getEventCode()) {
        case InputEvent::EVENT_KEYDOWN:
            switch (inputEvent->keyCode()) {
                case KEY_LEFT:
                case KEY_a:
                    left = 1.0;
                    break;
                case KEY_RIGHT:
                case KEY_d:
                    right = 1.0;
                    break;
                case KEY_UP:
                case KEY_w:
                    up = 1.0;
                    break;
                case KEY_DOWN:
                case KEY_s:
                    down = 1.0;
                    break;
				case KEY_ESCAPE:
				case KEY_q:
					alive = false;
					break;
            }
            break;
        case InputEvent::EVENT_KEYUP:
            switch (inputEvent->keyCode()) {
                case KEY_LEFT:
                case KEY_a:
                    left = 0.0;
                    break;
                case KEY_RIGHT:
                case KEY_d:
                    right = 0.0;
                    break;
                case KEY_UP:
                case KEY_w:
                    up = 0.0;
                    break;
                case KEY_DOWN:
                case KEY_s:
                    down = 0.0;
                    break;
				case KEY_ESCAPE:
				case KEY_q:
					alive = true;
					break;
            }
            break;
        case InputEvent::EVENT_MOUSEMOVE:
            x = inputEvent->getMousePosition().x;
            y = inputEvent->getMousePosition().y;
            y = y / yres - 0.5;
            x = x - xres / 2;
            x = x / yres;
            break;
        case InputEvent::EVENT_MOUSEDOWN:
            button1 = true;
            break;
        case InputEvent::EVENT_MOUSEUP:
            button1 = false;
            break;

    }
}

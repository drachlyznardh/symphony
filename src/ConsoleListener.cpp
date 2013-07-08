#include "ConsoleListener.hpp"
#include <iostream>

using namespace tbd;
using namespace std;

ConsoleListener::ConsoleListener() {
    messages = new queue<string > ();

    th = thread([this->messages]() {
	string line;
	while (true) {
		getline(cin, line);
	    lock_guard<mutex> guard(mymutex);
	    this->messages->push(line);
	}
    });
}

bool ConsoleListener::hasMessage() {
    return !messages->empty();
}

string ConsoleListener::getMessage() {
    if (messages->empty())
	return "";
    lock_guard<mutex> guard(mymutex);
    string line = messages->front();
    messages->pop();
    return line;
}

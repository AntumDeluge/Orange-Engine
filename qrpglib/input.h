#ifndef INPUT_H
#define INPUT_H 1

class Input {
public:
  Input();
  bool up, down, left, right, ok, cancel, action, console, menu;
};

extern Input * input;

#endif

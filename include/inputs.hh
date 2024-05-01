// Inputs singleton

#ifndef INPUT_SINGLETON_HH
#define INPUT_SINGLETON_HH

class InputSingleton {
public:
  static InputSingleton* GetInstance();
private:
  InputSingleton();
  ~InputSingleton();

  static InputSingleton* instance;
};

#endif
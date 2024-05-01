#include "inputs.hh"

InputSingleton* InputSingleton::GetInstance(){
  if (!instance){
    instance = new InputSingleton();
  }
  return instance;
}
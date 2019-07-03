#ifndef _STRTOMOR_H
#define _STRTOMOR_H
class Morse
{
  public:
    Morse(int pin);
	void Trans(int a); 
    void dot();
    void dash();
    void c_space();
	void w_space(); 
	void s_space();
  private:
    int _pin;
};
#endif /*_MORSE_H*/

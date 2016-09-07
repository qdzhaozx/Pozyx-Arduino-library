
#ifndef POZYX_SERIAL_H_
#define POZYX_SERIAL_H_

class SerialClass
{
protected:

public:
	void begin(int baud);

	void print(const char *str);
	void print(int d, int dec=1);

	void println(const char *str=NULL);
	void println(int d, int dec=1);

private:

};

extern SerialClass Serial;

#define HEX			0
#define DEC			1
#define BIN			2

#endif

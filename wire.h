#ifndef POZYX_WIRE_H_
#define POZYX_WIRE_H_
#include "Pozyx.h"

class WireClass 
{
public:
	void begin();
	void setPozyxAddr(uint8_t addr);
	void beginTransmission(uint8_t addr);
	int i2c_write(uint8_t data);
	int i2c_write(const uint8_t *data, int len);
	int i2c_writeread(uint8_t reg, uint8_t *wr_data, int wr_len,
				  uint8_t *rd_data, int rd_len);
	int i2c_writewrite(uint8_t reg, const uint8_t *wr_data1, int wr_len1,
				  const uint8_t *wr_data2, int wr_len2);
	// Third parameter is true: release I2C-bus after data is read.
	int requestFrom(unsigned addr, int len, boolean release);
	//datas whether arrived
	int available();
	//return a 8-bits data.
	uint8_t i2c_read();
	int i2c_read(uint8_t *buf, int len);
	int endTransmission(boolean end); 
private:
	int fd;
};

extern WireClass Wire;
#endif

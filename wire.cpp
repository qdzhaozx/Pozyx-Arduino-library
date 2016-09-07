#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termio.h>
#include <termios.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>

#include <linux/i2c-dev.h>
#include <linux/i2c.h>

#include "wire.h"
#include "serial.h"

void WireClass::begin()
{
	#define I2C_FILE	"/dev/i2c-0"

	fd = open (I2C_FILE, O_RDWR, 0);
	if (fd<0) 
	{
		Serial.println("open i2c dev failed!");
		abort();
	}
	ioctl(fd, I2C_TENBIT, 0); // 7-bits mode
	ioctl(fd, I2C_TIMEOUT, 10);
	printf("get i2c fd %d \n", fd);
};

void WireClass::setPozyxAddr(uint8_t addr)
{
	//I2C_SLAVE_FORCE
	if (ioctl(fd, I2C_SLAVE, addr) < 0) 
	{
		// ÉèÖÃÐ¾Æ¬µØÖ·
		printf("oictl:setslave address failed/n");
		abort();
	}
}
void WireClass::beginTransmission(uint8_t addr)
{
/*
	//I2C_SLAVE_FORCE
	if (ioctl(fd, I2C_SLAVE, addr) < 0) 
	{
		// ÉèÖÃÐ¾Æ¬µØÖ·
		printf("oictl:setslave address failed/n");
		abort();
	}
*/
}

int WireClass::endTransmission(boolean end)
{
	int ret=0;

	return(ret);
}

int WireClass::i2c_write(uint8_t data)
{
	int ret=0;
	
	ret = write(fd, &data, 1);

	return(ret);
}
int WireClass::i2c_write(const uint8_t *data, int len)
{
	int ret=0;

	ret = write(fd, data, len);

	return(ret);
}


int WireClass::i2c_writeread(uint8_t reg, uint8_t *wr_data, int wr_len,
			  uint8_t *rd_data, int rd_len)
{
	struct i2c_rdwr_ioctl_data ioctl_data;
	struct i2c_msg msgs[2];
	int ret;

	memset(msgs, 0x00, sizeof(msgs));
	msgs[0].addr = reg;
	msgs[0].buf= wr_data;
	msgs[0].len= wr_len;

	msgs[1].addr = reg;
	msgs[1].flags|= I2C_M_RD;
	msgs[1].buf= rd_data;
	msgs[1].len= rd_len;

	ioctl_data.nmsgs= 2;
	ioctl_data.msgs= msgs;
	ret = ioctl(fd, I2C_RDWR, &ioctl_data);

	return(ret);
}

int WireClass::i2c_writewrite(uint8_t reg, const uint8_t *wr_data1, int wr_len1,
			  const uint8_t *wr_data2, int wr_len2)
{
	struct i2c_rdwr_ioctl_data ioctl_data;
	struct i2c_msg msgs[2];
	int ret;

	memset(msgs, 0x00, sizeof(msgs));
	msgs[0].addr = reg;
	msgs[0].buf= (uint8_t *)wr_data1;
	msgs[0].len= wr_len1;

	msgs[1].addr = reg;
	msgs[1].buf= (uint8_t *)wr_data2;
	msgs[1].len= wr_len2;

	ioctl_data.nmsgs= 2;
	ioctl_data.msgs= msgs;
	ret = ioctl(fd, I2C_RDWR, &ioctl_data);

	return(ret);
}

uint8_t WireClass::i2c_read()
{
	uint8_t data=0;

	read(fd, &data, 1);

	return(data);
}

int WireClass::i2c_read(uint8_t *buf, int len)
{
	int ret;

	ret = read(fd, buf, len);

	return(ret);
}

int WireClass::available()
{
	int ret=1; /* always true */

	return(ret);
}

int WireClass::requestFrom(unsigned addr, int len, boolean release)
{
	int ret=0;

	return(ret);
}

WireClass Wire;


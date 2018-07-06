#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<sys/ioctl.h>
#include <linux/fs.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>



int WriteSectors(int fd, char *p, int offset) {//offset±íÊ¾¿éºÅ


	if (lseek(fd, pagesize*offset, SEEK_SET) == -1) {
		return (-1);//seek failed
	}

	return write(fd, p, pagesize);
}

int ReadSectors(int fd, char *p, int offset) {


	if (lseek(fd, pagesize*offset, SEEK_SET) == -1) {
		return (-1);//seek failed
	}

	return read(fd, p, pagesize);
}

int main(int argc, char* argv[])
{
	char *d;
	int size;

	char* iobuf = NULL;
	int pagesize = getpagesize();
	iobuf = memalign(getpagesize(), getpagesize());//2.6version = 512;
	//int fd = open("/dev/block/mmcblk0p26", O_RDWR | O_DIRECT, 606);

	return (0);
}
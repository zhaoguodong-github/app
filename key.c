#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>
#include <fcntl.h>
#include <linux/input.h>


int main(int argc, char **argv)
{
	int fd;
	int a;
	int i;
	int flag11;
	unsigned char strOutput[8];
	struct input_event inmyself;

	fd=open("/dev/input/event0",O_RDWR);
	if(fd==-1)
	{	
		printf ("open keyboard err:%d\n",fd);
		exit(1);
	}

       while(1)
	{
		flag11=read(fd, &inmyself, sizeof(inmyself));
		if(inmyself.type == EV_KEY)
		{
        		printf ("type :%d,code :%d,value :%d\n",inmyself.type,inmyself.code,inmyself.value);
		}
	}

        close(fd);

        return 0;
}

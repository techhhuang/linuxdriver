#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	char buf[20];
	int fd;
	fd = open("/dev/test", O_RDWR);
	if(fd < 0)
	{
		printf("open error!\n");
		return -1;
	}
	int count = read(fd, buf ,20);
	printf("buf read is: %s \n",buf);

	count = write(fd,(const void*)(0),20);
	close(fd);

	return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	char str[128] = {0,};
	int fd = open("temp.txt", O_RDWR);
	pid_t pid;
	pid = fork();
	if(pid > 0){ // parent
	write(fd, "Can you hear me?", 17);
	sleep(2);
	lseek(fd, 17,SEEK_SET);
	read(fd, str, 12);
	printf("parent(%X): %s \n", getpid(),str);
	close(fd);
	}
	else if(pid == 0) { // child
	sleep(1);
	lseek(fd,0,SEEK_SET);
	read(fd, str, 17);
	printf("child(%X): %s \n", getpid(), str);
	write(fd, "Yes, I can!", 12);
	}
	return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main() {
    int fd[2];
    char message[] = "Hello, child!";
    char buffer[100];
    pid_t pid;

    pipe(fd);  // 파이프 생성
    pid = fork();

    if (pid > 0)
	{  // 부모 프로세스
        close(fd[0]);  // 읽기 끝 닫기 (부모는 쓰기만 함)
        write(fd[1], message, strlen(message) + 1);
        close(fd[1]);  // 쓰기 끝 닫기
    }
	else
	{  // 자식 프로세스
        close(fd[1]);  // 쓰기 끝 닫기 (자식은 읽기만 함)
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(fd[0]);  // 읽기 끝 닫기
    }
    return 0;
}

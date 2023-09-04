# 동기화?

프로세스들의 수행 시기를 맞추는 것

# 동기화가 필요한 이유?

* 실행 순서 제어
* 상호 배제

# 상호 배제가 뭔가?

한 프로세스가 임계 구역에 진입했다면 다른 프로세스는 들어올 수 없다.

# 동시에 실행하면 문제가 발생하는 자원에 접근하는 코드 영역?

임계 영역

# Race condition이란?

임계 구역에 동시에 접근하면 자원의 일관성이 깨질 수 있다

# inter process communication은 어떻게 할 수 있을까?

# 생산자

# 뮤텍스 락 수도를 작성해라

```c++
void *전역변수;

void acquire() { // 임계 구역을 잠금.
    while (lock == true); //busy waiting
    lock = true;
}

void release() { // 임계 구역 잠금 해제
    lock = false;
}

int main() {
    acquire();
    //임계 구역
    release();
}
```

# 세마포 수도 작성해라

```c
int usable_shared_var;

void wait() { //임계 구역에 들어가도 되는지 알려줌
    while ( usable_shared_var <= 0);
     usable_shared_var--;
}

void signal() { //임계 구역에 이제 드가라고 신호주는 역할
     usable_shared_var++;
}

int main() {
    wait();
    //임계 구역
    signal();
}
```

#  Busy waiting이 왜 안좋으냐.

cpu 사이클 낭비

# Busy waiting이 없는 세마포 수도 작성해라

```c
int  usable_shared_var;

void wait() {
     usable_shared_var--;
    if ( usable_shared_var < 0) {
        //요 프로세스 대기 큐에 삽입
        sleep();
    }
}

void signal() {
     usable_shared_var++;
    if ( usable_shared_var <= 0) {
        //대기 큐에서 한놈(p) 제거
        wakeup(p)
    }
}

int main() {
    wait();
    //임계 영역
    signal();
}
```



# 실행 순서 동기화 용으로 수도

세마포의 변수를 0으로 두고 
먼저 실행할 프로세스 뒤에 signal()
다음에 실행할 프로세스 앞에 wait()

# 공용 파일과 파이프는 반 양방향 통신이다

엿. 단방향 통신임.

#  데이터 받는 쪽이 busy waiting인 통신은 대기가 있다.

없음.

# fork()하면 fd를 공유한다

ㅇㅇ

# pipe는 가족이 아닌 프로세스 간에 데이터를 주고 받을 수 있다.

ㅗ. fifo만 가능. 

# shared memory는 메모리 크기 변화가 있다.

없음.

# message queue는 동기화를 고려할 필요가 없다.

맞음.

# 
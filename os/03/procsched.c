#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE1(get_pcount, int pid)
{
    struct task_struct *task;
    struct sched_info si;

    task = pid_task(find_vpid(pid), PIDTYPE_PID); // 해당 PID에 대한 task_struct 구조체 가져오기
    if (!task)
        return -ESRCH;

    rcu_read_lock(); // read-side lock을 획득
    si = task->sched_info; // task_struct 내부의 sched_info 구조체 가져오기
    rcu_read_unlock(); // read-side lock 해제

    return si.pcount; // pcount 값 반환
}


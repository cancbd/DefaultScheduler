#include <linux/getprocinfoF22.h>
#include <linux/sched.h>
#include <asm/current.h>
#include <linux/types.h>
#include <linux/mm.h>
#include <asm/uaccess.h>

asmlinkage int sys_getprocinfoF22(struct processdatF22 *data){
	cli();
	struct processdatF22 kernelSpace;
	if((copy_from_user(&kernelSpace,data,sizeof(struct processdatF22))) != 0){
	return -1;
	}
	
	if(kernelSpace.f <=22 && kernelSpace.f >= 0){
	kernelSpace.pid = current->pid;
	struct task_struct *parent;
	parent = current->p_pptr;
	kernelSpace.pidparentproc = parent->pid;
	
	kernelSpace.proccounter = current->counter;
	kernelSpace.nice = current->nice;
	kernelSpace.uid = current->uid;
	kernelSpace.w = 20+(current->counter)-(current->nice);
	
	kernelSpace.priority = current->rt_priority;
	}
	else if (kernelSpace.f > 22) {
	kernelSpace.w = 20+(current->counter)-(current->nice);
	}
	else{
	return -1;
	}
	
	if((copy_to_user(data,&kernelSpace,sizeof(struct processdatF22))) != 0){
	return -1;
	}
	
	sti();
	return 0;
					








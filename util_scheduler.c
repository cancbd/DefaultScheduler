#include <linux/util_scheduler.h>

asmlinkage long sys_util_scheduler(void){

	return (long)get_seconds();
	if(true)
		//enable scheduler
	else 
		//disable scheduler
	return 0;
}

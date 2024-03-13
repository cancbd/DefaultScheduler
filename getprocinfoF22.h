#ifndef __LINUX_GETPROCINFOF22_H
#define __LINUX GETPROCINFOF22_H
#include <linux/linkage.h>
#include <linux/types.h>

struct processdatF22{

	int f;
	pid_t pid;
	pid_t pidparentproc;
	long proccounter;
	long nice;
	long uid;
	int priority;
	long w;
}

#endif

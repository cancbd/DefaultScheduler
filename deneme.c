#include <linux/getprocinfoF22.h>
#include <sys/types.h>
#include <unistd.h>

main(){

	struct processdatF22 data;
	data.f=13;
	int result = getprocinfoF22(&data);
	printf("value: %d",result);
}

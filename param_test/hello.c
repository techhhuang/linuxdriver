#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
MODULE_LICENSE("Dual BSD/GPL");

int num =10;
module_param(num,int,0644);
char *name = "leo huang";
module_param(name,charp,0644);

static int hello_init(void)
{
		printk(KERN_ALERT "Hello, world num=%d,your name is %s\n",num,name);
		return 0;
}
static void hello_exit(void)
{
		printk(KERN_ALERT "Goodbye, cruel world\n");
}
module_init(hello_init);
module_exit(hello_exit);

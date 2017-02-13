#include <linux/init.h>
#include <linux/module.h>
#include "../include/util.h"

MODULE_LICENSE("GPL");
MODULE_VERSION("1.0.0");
MODULE_AUTHOR("leo huang");

static int hello_init(void)
{
		printk(KERN_ALERT "Hello, world\n");
		say();
		return 0;
}
static void hello_exit(void)
{
		printk(KERN_ALERT "Goodbye, cruel world\n");
}
module_init(hello_init);
module_exit(hello_exit);

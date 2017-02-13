#include <linux/module.h>
#include <linux/init.h>
#include "../include/util.h"

int say(void)
{
	printk("say hello from util\n");
	return 0;
}

EXPORT_SYMBOL(say);
MODULE_LICENSE("GPL");
MODULE_VERSION("1.0.0");
MODULE_AUTHOR("leo huang");

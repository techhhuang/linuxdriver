#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

unsigned int major = 240;
struct file_operations test_fops;

static int __init test_init(void)
{
	register_chrdev(major,"test_driver",&test_fops);
	printk("hello kernel\n");
	return 0;
}

static void  __exit test_exit(void)
{
	unregister_chrdev(major,"test_driver");
	printk("good bye kernel\n");
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("leo huang");
MODULE_VERSION("1.0.0");
MODULE_DESCRIPTION("this is a test driver!");




#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

unsigned int major = 0;
unsigned int minor = 0;
dev_t devno;
struct file_operations test_fops;

static int __init test_init(void)
{
	//register_chrdev(major,"test_driver",&test_fops);
	devno = MKDEV(major,minor);
	register_chrdev_region(devno,1,"test_driver");
	printk("hello kernel\n");
	return 0;
}

static void  __exit test_exit(void)
{
	//unregister_chrdev(major,"test_driver");
	unregister_chrdev_region(devno,1);
	printk("good bye kernel\n");
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("leo huang");
MODULE_VERSION("1.0.0");
MODULE_DESCRIPTION("this is a test driver!");




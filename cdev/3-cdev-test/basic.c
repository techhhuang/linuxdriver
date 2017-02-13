#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>

unsigned int major = 0;
unsigned int minor = 0;
dev_t devno;
struct cdev test_cdev;
struct file_operations test_fops;

static int __init test_init(void)
{
	if(major){
		devno = MKDEV(major,minor);
		register_chrdev_region(devno,1,"test_new_driver");
	}else{
		alloc_chrdev_region(&devno,minor,1,"test_alloc_driver");
	}
	cdev_init(&test_cdev,&test_fops);
	test_cdev.owner = THIS_MODULE;

	cdev_add(&test_cdev,devno,1);

	printk("hello kernel\n");
	return 0;
}


static void  __exit test_exit(void)
{
	cdev_del(&test_cdev);
	unregister_chrdev_region(devno,1);
	printk("good bye kernel\n");
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("leo huang");
MODULE_VERSION("1.0.0");
MODULE_DESCRIPTION("this is a test driver!");




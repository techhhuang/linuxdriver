#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>

unsigned int major = 240;
unsigned int minor = 0;
dev_t devno;
struct cdev test_cdev;

int test_open(struct inode *node, struct file *filp)
{
	printk("open device\n");
	return 0;
}

int test_close(struct indoe *node, struct file *filp)
{
	printk("close device\n");
	return 0;
}

struct file_operations test_fops={
	.open = test_open,
	.release = test_close,
};

static int __init test_init(void)
{
	int result = 0;
	if(major){
		devno = MKDEV(major,minor);
		result = register_chrdev_region(devno,1,"test_new_driver");
	}else{
		result = alloc_chrdev_region(&devno,minor,1,"test_alloc_driver");
		major = MAJOR(devno);
		minor = MINOR(devno);
	}

	if(result < 0){
		printk("register devno error!\n");
		goto err0;
	}
	
	printk("major:%d minor:%d \n",major,minor);

	cdev_init(&test_cdev,&test_fops);
	test_cdev.owner = THIS_MODULE;

	cdev_add(&test_cdev,devno,1);

	printk("hello kernel \n");
	return 0;

err1:

err0:
	return result;
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




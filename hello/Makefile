obj-m := hello.o  
KERNELDIR ?= /lib/modules/$(shell uname -r)/build  
PWD := $(shell pwd)  
default:  
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules  

clean:
	rm -rf *.o *.mod.c *.mod.o *.ko modules.order Module.symvers



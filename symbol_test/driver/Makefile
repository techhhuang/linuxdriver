obj-m := hello.o  
KERNELDIR ?= /lib/modules/$(shell uname -r)/build  
PWD := $(shell pwd)  
#KBUILD_EXTRA_SYMBOLS += /home/xnhz/linuxdriver/symbol_test/core/Module.symvers
default:  
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules  

clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions modules.order  Module.symvers 

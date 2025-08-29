# If KERNELDIR is not set, use the default kernel source directory
KERNELDIR ?= /lib/modules/$(shell uname -r)/build

# Module name
MODULE_NAME := show_time

# Source files
obj-m := $(MODULE_NAME).o

# Default target
all:
	make -C $(KERNELDIR) M=$(PWD) modules

# Clean target
clean:
	make -C $(KERNELDIR) M=$(PWD) clean
	rm -f Module.symvers
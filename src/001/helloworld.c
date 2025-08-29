#include <linux/module.h>

static int __init hello_init(void) {
    printk(KERN_INFO "Hello, World! Driver initialized.\n");
    return 0;
}

static void __exit hello_exit(void) {
    printk(KERN_INFO "Goodbye, World! Driver exiting.\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("caishi wei");
MODULE_DESCRIPTION("A simple Hello World Linux driver");
MODULE_VERSION("1.0");
#include <linux/ktime.h>
#include <linux/module.h>
#include <linux/time.h>

// UTC+8
#define TIMEZONE_OFFSET (8 * 3600) 

void show_time(char *desc)
{
    char time_str[64];
    struct timespec64 ts;
    struct tm tm;
    time64_t local_sec;

    ktime_get_real_ts64(&ts);
    local_sec = ts.tv_sec + TIMEZONE_OFFSET;
    time64_to_tm(local_sec, 0, &tm);
    snprintf(time_str, sizeof(time_str), "%04d-%02d-%02d %02d:%02d:%02d.%06ld", tm.tm_year + 1900, tm.tm_mon + 1,
             tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, ts.tv_nsec / 1000);

    printk(KERN_INFO "[%s]===================================================\n", desc);
    printk(KERN_INFO "[%s]Current time: %s\n", desc, time_str);
    printk(KERN_INFO "[%s]===================================================\n", desc);
}

static int __init show_init(void)
{
    show_time(__FUNCTION__);
    dump_stack();
    return 0;
}

static void __exit show_exit(void)
{
    show_time(__FUNCTION__);
    dump_stack();
}

module_init(show_init);
module_exit(show_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("caishi wei");
MODULE_DESCRIPTION("A simple show time Linux driver");
MODULE_VERSION("1.0");
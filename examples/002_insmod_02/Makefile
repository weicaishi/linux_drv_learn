mod_file	:=../../src/002/show_time.ko
target		:=insmod_02

all:${target}

${target}:${target}.c
	gcc -o $@ $^

test:
	-sudo rmmod ${mod_file}
	sleep 1
	-sudo ./${target} ${mod_file}

.PHONY: all ${target} test clean
clean:
	-rm -f ${target}
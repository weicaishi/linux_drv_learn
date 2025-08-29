mod_file	:=../../src/002/show_time.ko
target		:=insmod_01

all:${target}

${target}:${target}.c
	gcc -o $@ $^

test:
	-sudo rmmod ${mod_file}
	sleep 3
	-sudo ./${target} ${mod_file}

.PHONY: all ${target} test clean
clean:
	-rm -f ${target}
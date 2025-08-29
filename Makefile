MKS		+=$(shell find ./src -name "Makefile" -type f)
MKS		+=$(shell find ./examples -name "Makefile" -type f)

all:
	@for mk in $(MKS); do \
		cd $$(dirname $$mk) || exit 1;\
		$(MAKE) all || exit 1; \
		cd -; \
	done

clean:
	@for mk in $(MKS); do \
		cd $$(dirname $$mk) || exit 1;\
		$(MAKE) clean || exit 1; \
		cd -; \
	done

.PHONY: all clean
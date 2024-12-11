SUBDIRS := $(wildcard */)

.PHONY: all clean $(SUBDIRS)
.DEFAULT_GOAL := all

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

clean: $(SUBDIRS)
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done
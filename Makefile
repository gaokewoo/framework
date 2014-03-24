include ./global.mk

define make_subdir
@for subdir in $(SUBDIRS) ; do \
    ( cd $$subdir && make $1) \
    done;
endef

.PHONY:install

all:
	$(call make_subdir , all)

install:
	$(call make_subdir , install)

debug:
	$(call make_subdir , debug)

clean:
	rm -rf bin/* lib/*
	$(call make_subdir , clean)


$(warning "tom Makefile begin")
include deps.mk
include kconfig.mk
.PHONY: clean
clean:
	rm -f aa
	rm -f bb
aa :
	$(warning "tom 11=$(KCONFIG_DEPS)")
	@echo "abc"
	@echo $(CURDIR)
$(warning "tom Makefile end")

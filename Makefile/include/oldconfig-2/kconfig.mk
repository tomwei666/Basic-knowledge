$(warning tom kconfig.mk begin)
$(eval $(call check_dep_exec,python3,KCONFIG_DEPS))
$(eval $(call check_dep_py3lib,kconfiglib,KCONFIG_DEPS))
T := $(CURDIR)
HV_CONFIG := .config                                                                                                                                                                                                                    
HV_DEFCONFIG := defconfig                                                       
HV_CONFIG_H := config.h                                                 
HV_CONFIG_MK := config.mk                                               

-include $(CURDIR)/$(HV_CONFIG_MK)
$(CURDIR)/$(HV_CONFIG): oldconfig                                            
	@echo "tom 2=$(HV_OBJDIR) $(HV_CONFIG)"                                     
	@true                                                                       
                                                                                
# Note: This target must not depend on a phony target (e.g. oldconfig) because  
# it'll trigger endless re-execution of make.                                   
$(CURDIR)/$(HV_CONFIG_MK): $(CURDIR)/$(HV_CONFIG)                         
	@echo "tom 3=$@ 3-1=$(HV_OBJDIR) $(HV_CONFIG)"                              
	@mkdir -p $(dir $@)                                                         
	@sed 's/="\(.*\)"$$/=\1/g' $(CURDIR)/$(HV_CONFIG) > $@

oldconfig: $(KCONFIG_DEPS)                                                      
	@echo "tom 1= $(HV_CONFIG)"                                     
	@echo "tom 1=$(CURDIR)"                                                     
	#@touch $(CURDIR)/$(HV_CONFIG)

$(warning tom kconfig.mk 19)
$(warning tom kconfig.mk end)

	

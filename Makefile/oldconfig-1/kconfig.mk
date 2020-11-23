$(warning tom kconfig.mk begin)
$(eval $(call check_dep_exec,python3,KCONFIG_DEPS))
$(eval $(call check_dep_py3lib,kconfiglib,KCONFIG_DEPS))
T := $(CURDIR)
HV_CONFIG := .config                                                                                                                                                                                                                    
HV_DEFCONFIG := defconfig                                                       
HV_CONFIG_H := config.h                                                 
HV_CONFIG_MK := config.mk                                               
                                                                                
# This target invoke silentoldconfig to generate a .config only if a .config       
# does not exist. Useful as a dependency for source compilation.                
$(CURDIR)/$(HV_CONFIG):                                                      
	@echo "tom generate .config"                                                               
	@touch .config
                                                                                
$(CURDIR)/$(HV_CONFIG_MK): $(CURDIR)/$(HV_CONFIG)                         
	@echo "tom generate config.mk"                                                               

$(warning tom kconfig.mk 19)
-include $(CURDIR)/$(HV_CONFIG_MK)
$(warning tom kconfig.mk end)

	

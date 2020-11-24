# usage: check_dep_exec <executable name> <variable>                            
#                                                                               
# Create a target that checks the existence of the specified executable, and       
# append that target to the given variable.                                     

define check_dep_exec =                                                         
$(warning "check_dep_exec begin")
$(2) += check_exec_$(1)                                                         
check_exec_$(1):                                                                
	@echo "Function check_exec_$(1)"
endef                                                                           
                                                                                
# usage: check_dep_py3lib <library name> <variable>                             
#                                                                               
# Create a target that checks the existence of the specified python 3 library, and
# append that target to the given variable.                                     
define check_dep_py3lib =                                                       
$(warning "check_dep_py3lib begin")
$(2) += check_py3lib_$(1)                                                       
check_py3lib_$(1):                                                              
	@echo "Function check_py3lib__$(1)"
endef

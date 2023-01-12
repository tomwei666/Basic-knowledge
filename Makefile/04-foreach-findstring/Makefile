str1 := a b c
str2 := b c
build_lk_env_list := SD_BUILD_LK_SPL_NAME
sd_env := $(shell env | grep SD_BUILD)
build_lk_env_list := SD_BUILD_LK_SPL_NAME \
    SD_BUILD_LK_SSYSTEM_NAME \
    SD_BUILD_LK_DLOADER_NAME \
    SD_BUILD_LK_PRELOADER_NAME \
    SD_BUILD_LK_CLUSTERPRELOADER_NAME \
    SD_BUILD_LK_IVIBOOTLOADER_NAME \
    SD_BUILD_LK_CLUSTERBOOTLOADER_NAME \
    SD_BUILD_LK_MP_NAME \
    SD_BUILD_LK_SDPE_NAME \
    SD_BUILD_LK_BOOTLOADER_NAME \
    SD_BUILD_LK_DIL2_PARALLEL_NAME
build_lk_target := $(foreach bld,$(build_lk_env_list),$(findstring $(bld),$(sd_env)))
all:
	@echo $(findstring a,$(str1))
	@echo $(findstring a,$(str2))
	@echo $(build_lk_target)

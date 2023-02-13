################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1220/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/kevine/workspace_v12/empty_EK_TM4C123GXL_TI" --include_path="C:/Users/kevine/workspace_v12/empty_EK_TM4C123GXL_TI" --include_path="C:/ti/tirtos_tivac_2_14_04_31/products/TivaWare_C_Series-2.1.1.71b" --include_path="C:/ti/tirtos_tivac_2_14_04_31/packages/ti/drivers/wifi/cc3100/Simplelink" --include_path="C:/ti/tirtos_tivac_2_14_04_31/packages/ti/drivers/wifi/cc3100/Simplelink/Include" --include_path="C:/ti/ccs1220/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=ccs --define=TIVAWARE -g --gcc --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-881623425:
	@$(MAKE) --no-print-directory -Onone -f subdir_rules.mk build-881623425-inproc

build-881623425-inproc: ../empty.cfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: XDCtools'
	"C:/ti/xdctools_3_31_01_33_core/xs" --xdcpath="C:/ti/tirtos_tivac_2_14_04_31/packages;C:/ti/tirtos_tivac_2_14_04_31/products/bios_6_42_03_35/packages;C:/ti/tirtos_tivac_2_14_04_31/products/ndk_2_24_03_35/packages;C:/ti/tirtos_tivac_2_14_04_31/products/uia_2_00_02_39/packages;" xdc.tools.configuro -o configPkg -t ti.targets.arm.elf.M4F -p ti.platforms.tiva:TM4C123GH6PM -r release -c "C:/ti/ccs1220/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS" --compileOptions "-mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path=\"C:/Users/kevine/workspace_v12/empty_EK_TM4C123GXL_TI\" --include_path=\"C:/Users/kevine/workspace_v12/empty_EK_TM4C123GXL_TI\" --include_path=\"C:/ti/tirtos_tivac_2_14_04_31/products/TivaWare_C_Series-2.1.1.71b\" --include_path=\"C:/ti/tirtos_tivac_2_14_04_31/packages/ti/drivers/wifi/cc3100/Simplelink\" --include_path=\"C:/ti/tirtos_tivac_2_14_04_31/packages/ti/drivers/wifi/cc3100/Simplelink/Include\" --include_path=\"C:/ti/ccs1220/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include\" --define=ccs=\"ccs\" --define=PART_TM4C123GH6PM --define=ccs --define=TIVAWARE -g --gcc --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi  " "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

configPkg/linker.cmd: build-881623425 ../empty.cfg
configPkg/compiler.opt: build-881623425
configPkg/: build-881623425



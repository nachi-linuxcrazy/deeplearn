#
_XDCBUILDCOUNT = 0
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /opt/ti/ccsv5/ccs_base;/opt/ti/bios_6_33_08_55/packages;/home/chipes/TI_DSP_Workspace/Memory_Package;/home/chipes/TI_DSP_Workspace/dsp_deeplearn_sysbios_core0/.config
override XDCROOT = /opt/ti/xdctools_3_24_06_63
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /opt/ti/ccsv5/ccs_base;/opt/ti/bios_6_33_08_55/packages;/home/chipes/TI_DSP_Workspace/Memory_Package;/home/chipes/TI_DSP_Workspace/dsp_deeplearn_sysbios_core0/.config;/opt/ti/xdctools_3_24_06_63/packages;..
HOSTOS = Linux
endif
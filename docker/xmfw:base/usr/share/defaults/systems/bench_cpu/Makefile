# XAL_PATH: path to the XTRATUM directory
XAL_PATH := /opt/xm/xal

APPS       := $(wildcard *-app)
BUILDS     := $(patsubst %,%/build,$(APPS))
TARGETS    := $(patsubst %-app,%,$(APPS))
PARTITIONS := $(patsubst %-app,%.xef,$(APPS))
APPS_CLEAN := $(patsubst %,%/.clean,$(APPS))

CONTAINER = container.bin
RSW = resident_sw.elf

all: $(CONTAINER) $(RSW)
include $(XAL_PATH)/common/rules.mk

# XMLCF: path to the XML configuration file
XMLCF := xm_cf.$(ARCH).xml

export XAL_PATH XMLCF

resident_sw.elf: resident_sw
	cp resident_sw resident_sw.elf

$(TARGETS): % : %-app/build
	cp $< $@

$(BUILDS):
	$(MAKE) -C $(@D) $(@F)

clean: $(APPS_CLEAN)

$(APPS_CLEAN):
	$(MAKE) -C $(@D) $(@F:.%=%)

PACK_ARGS=-h $(XMCORE):xm_cf.xef.xmc \
	-p 0:looper.xef \
	-p 1:logger.xef

$(CONTAINER): $(PARTITIONS) xm_cf.xef.xmc
	$(XMPACK) check xm_cf.xef.xmc $(PACK_ARGS)
	$(XMPACK) build $(PACK_ARGS) $@
	@exec echo -en "> Done [container]\n"

.PHONY: $(BUILDS) $(APPS_CLEAN) clean-apps

XAL_PATH := /opt/xm/xal

APPS       := $(wildcard *-app)
BUILDS     := $(patsubst %,%/build,$(APPS))
TARGETS    := $(patsubst %-app,%,$(APPS))
PARTITIONS := $(patsubst %-app,%.xef,$(APPS))
APPS_CLEAN := $(patsubst %,%/.clean,$(APPS))

CONTAINER = container.bin
RSW = resident_sw.elf

# TODO The value of this variable should be automated in future work
PACK_ARGS=-h $(XMCORE):xm_cf.xef.xmc \
	-p 0:memory0.xef \
	-p 1:memory1.xef \
	-p 2:logger.xef

all: $(CONTAINER) $(RSW)
include $(XAL_PATH)/common/rules.mk

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

$(CONTAINER): $(PARTITIONS) xm_cf.xef.xmc
	$(XMPACK) check xm_cf.xef.xmc $(PACK_ARGS)
	$(XMPACK) build $(PACK_ARGS) $@
	@exec echo -en "> Done [container]\n"

.PHONY: $(BUILDS) $(APPS_CLEAN) clean

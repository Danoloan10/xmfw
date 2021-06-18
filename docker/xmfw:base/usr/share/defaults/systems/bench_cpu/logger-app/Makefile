include $(XAL_PATH)/common/rules.mk

XMLCF := ../$(XMLCF)

build: partition.o
	$(TARGET_LD) -o $@ $^ $(TARGET_LDFLAGS) -Ttext=$(shell $(XPATHSTART) 1 $(XMLCF))

clean:
	rm -f partition.o build

.PHONY: clean

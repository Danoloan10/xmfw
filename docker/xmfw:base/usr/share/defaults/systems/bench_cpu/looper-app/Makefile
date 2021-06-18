PARTITION_NUMBER := 0

OBJECTS := partition.o

include $(XAL_PATH)/common/rules.mk
XMLCF := ../$(XMLCF)

build: partition.o
	$(TARGET_LD) -o $@ $^ $(TARGET_LDFLAGS) -Ttext=$(shell $(XPATHSTART) 0 $(XMLCF))

clean:
	rm -f $(OBJECTS) build

.PHONY: clean

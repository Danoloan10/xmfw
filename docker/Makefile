DOCKER=docker
REPOSITORY=danoloan/

CONTAINERS := $(wildcard xmfw*)
CONTAINERS := $(subst :,$$,$(CONTAINERS))
CONTAINERS := $(subst xmfw$$base,,$(CONTAINERS))

all: $(CONTAINERS)

$(CONTAINERS): xmfw$$base
$(CONTAINERS) xmfw$$base:
	$(DOCKER) build -t $(REPOSITORY)$(subst $$,:,$@) $(subst $$,:,$@)
	@touch $(subst $$,:,$@)

.PHONY: all $(CONTAINERS) xmfw$$base

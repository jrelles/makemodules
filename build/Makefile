MODULES = A B C
.PHONY: $(MODULES)

all: TARGET
	$(info all)

VPATH=..

OBJ_DIR = obj
SRCS = main.c
DEPS = C

C_DEPS = B A 
C_DIR = c
C_SRCS = c/c.c

B_DEPS = A
B_DIR = b
B_SRCS = b/b.c

A_DEPS =
A_DIR = a
A_SRCS = a/a.c

OBJS = $(addsuffix .o, $(basename $(SRCS)))

TARGET: $(DEPS)
	$(info :::$@)

OBJ_MODULE_DIR = $(OBJ_DIR)/modules
$(foreach mod, $(MODULES), $(eval $(mod)_OBJ_DIR := $(OBJ_DIR)/$($(mod)_DIR)))
$(foreach mod, $(MODULES), $(eval $(mod)_O := $(OBJ_MODULE_DIR)/$(mod).o))
$(foreach mod, $(MODULES), $(eval $(mod)_OBJS := $(addprefix $(OBJ_DIR)/,$(addsuffix .o,$(basename $($(mod)_SRCS))))))
$(foreach mod, $(MODULES), $(eval $(mod)_CLEAN_DEPS := $(addsuffix _CLEAN, $($(mod)_DEPS))))
MODULES_CLEAN := $(foreach mod, $(MODULES), $(mod)_CLEAN)

.SECONDARY:
.SECONDEXPANSION:

$(OBJ_MODULE_DIR)/%.o: $$($$*_OBJS)
	$(info :::$@ from $^)
	$(info MOD2 = $(MODULE))
	ld -r -o $@ $^

.PHONY: $(MODULES)
$(MODULES): $$($$@_DEPS) | $(OBJ_MODULE_DIR)/.
	$(info :::$@)
	+make MODULE=$@ $($@_O)

.PHONY: clean
clean: $(addsuffix _CLEAN,$(DEPS))
	$(info )

$(info MODULES_CLEAN=$(MODULES_CLEAN))
$(MODULES_CLEAN): $$($$@_DEPS)
$(MODULES_CLEAN): $$(subst _CLEAN,-CLEAN,$$@)
	$(info :::$@)

%-CLEAN:
	$(info :::$@)
	rm -rf $($*_OBJS)

$(OBJ_DIR)/%.o : %.c | $$(@D)/.
	$(info :::$@ from $^)
	$(info MODULE=$(MODULE))
	cc    -c -o $@ $<

%/. :
	$(info :::$@)
	mkdir -p $@

$(info $(.INCLUDE_DIRS))

.INCLUDE_DIRS = ..
$(info $(.INCLUDE_DIRS))


RUSTC=rustc
TARGETS= \
    problem1

all: $(TARGETS)

clean: $(TARGETS)
	-rm $^

.SUFFIXES: .rs

%: %.rs
	$(RUSTC) $^


RUSTC=rustc
TARGETS= \
    problem1 \
    problem2

all: $(TARGETS)

clean: $(TARGETS)
	-rm $^

.SUFFIXES: .rs

%: %.rs
	$(RUSTC) $^


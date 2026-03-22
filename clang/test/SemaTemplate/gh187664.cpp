// RUN: %clang_cc1 -fblocks -fsyntax-only -verify %s

class A {
public:
    class B {};
};

using X = A::B;

class C {
    template <typename T = X class A::B> void f();
    // expected-error@-1 {{cannot combine with previous 'type-name' declaration specifier}}
    // expected-error@-2 {{expected ',' or '>' in template-parameter-list}}
};

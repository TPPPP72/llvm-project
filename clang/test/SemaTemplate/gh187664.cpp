// RUN: %clang_cc1 -fsyntax-only -verify %s

struct A {
  struct B{};
};

A struct A::B i; // expected-error {{cannot combine with previous 'type-name' declaration specifier}}
// expected-note@-1 + {{previous definition is here}}

struct S{};
S struct A::B i;
// expected-error@-1 {{cannot combine with previous 'type-name' declaration specifier}}
// expected-error@-2 {{redefinition of 'i' with a different type: 'S' vs 'A'}}

using T = int;
T struct A::B i;
// expected-error@-1 {{cannot combine with previous 'type-name' declaration specifier}}
// expected-error@-2 {{redefinition of 'i' with a different type: 'T' (aka 'int') vs 'A'}}

namespace NS {
  struct Scoped{};
};

S struct NS::Scoped i;
// expected-error@-1 {{cannot combine with previous 'type-name' declaration specifier}}
// expected-error@-2 {{redefinition of 'i' with a different type: 'S' vs 'A'}}

S struct ::S i;
// expected-error@-1 {{cannot combine with previous 'type-name' declaration specifier}}
// expected-error@-2 {{redefinition of 'i' with a different type: 'S' vs 'A'}}

// Pushdown Automata (Formal Definition)
// A Pushdown Automata is formally defined by 7 Tuples as shown below:
// represented by a.b.o.

// a finite set of States
typedef void *Q;
// a finite set of Input Symbols
typedef void *Σ;
// a finite Stack Alphabet
typedef void *Γ;
// the start State
typedef void *q0;
// the start Stack Symbol
typedef void *z0;
// the set of Final / Accepting States
typedef void *F;
// the transition Function
typedef void (*δ)(void (*o)(void *p, // is a new state
                            void *y // is a string of stack symols that replaces
                                    // X at top of the stack
                                    // Eg. If y = ε then the stack is popped
                                    //     If y = X then the stack unchanged
                                    //     If y = YZ then X is repleaced by Z
                                    //     and Y is pushed onto the stack
                            ),
                  void *q, // is a state in Q
                  void *a, // is either an Input Symbol in Σ or ε
                  void *X  // is Stack Symbol, that is member of Γ
);
typedef void (*pda)(Q, Σ, Γ, δ, q0, z0, F);

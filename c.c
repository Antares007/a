typedef void (*pith_t)(void *, const char *, void *, void *, void *);
typedef void (*bark_t)(pith_t, void *);

void noop() {}
void id() {}
void plus() {}
void mul() {}
void lparen() {}
void rparen() {}

void expr(pith_t, void *);
void term(pith_t, void *);
void factor(pith_t, void *);

void G24(pith_t o, void *s) { o(s, "G", G24, noop, 0); }
void A25(pith_t o, void *s) { o(s, "A", A25, term, G24); }
void G26(pith_t o, void *s) { o(s, "G", G26, noop, A25); }
void A27(pith_t o, void *s) { o(s, "A", A27, term, G26); }
void T28(pith_t o, void *s) { o(s, "T", T28, plus, A27); }
void expr(pith_t o, void *s) { o(s, "expr", expr, expr, T28); }

void G30(pith_t o, void *s) { o(s, "G", G30, noop, 0); }
void A31(pith_t o, void *s) { o(s, "A", A31, factor, G30); }
void G32(pith_t o, void *s) { o(s, "G", G32, noop, A31); }
void A33(pith_t o, void *s) { o(s, "A", A33, factor, G32); }
void T34(pith_t o, void *s) { o(s, "T", T34, mul, A33); }
void term(pith_t o, void *s) { o(s, "term", term, term, T34); }

void G36(pith_t o, void *s) { o(s, "G", G36, noop, 0); }
void T37(pith_t o, void *s) { o(s, "T", T37, id, G36); }
void G38(pith_t o, void *s) { o(s, "G", G38, noop, T37); }
void T39(pith_t o, void *s) { o(s, "T", T39, rparen, G38); }
void A40(pith_t o, void *s) { o(s, "A", A40, expr, T39); }
void T41(pith_t o, void *s) { o(s, "T", T41, lparen, A40); }
void factor(pith_t o, void *s) { o(s, "factor", factor, factor, T41); }

// Generated by cpp11: do not edit by hand


#include "cpp11/declarations.hpp"

// string_metrics.h
list get_string_shape_c(strings string, integers id, strings path, integers index, doubles size, doubles res, doubles lineheight, integers align, doubles hjust, doubles vjust, doubles width, doubles tracking, doubles indent, doubles hanging, doubles space_before, doubles space_after);
extern "C" SEXP _textshaping_get_string_shape_c(SEXP string, SEXP id, SEXP path, SEXP index, SEXP size, SEXP res, SEXP lineheight, SEXP align, SEXP hjust, SEXP vjust, SEXP width, SEXP tracking, SEXP indent, SEXP hanging, SEXP space_before, SEXP space_after) {
  BEGIN_CPP11
    return cpp11::as_sexp(get_string_shape_c(cpp11::unmove(cpp11::as_cpp<strings>(string)), cpp11::unmove(cpp11::as_cpp<integers>(id)), cpp11::unmove(cpp11::as_cpp<strings>(path)), cpp11::unmove(cpp11::as_cpp<integers>(index)), cpp11::unmove(cpp11::as_cpp<doubles>(size)), cpp11::unmove(cpp11::as_cpp<doubles>(res)), cpp11::unmove(cpp11::as_cpp<doubles>(lineheight)), cpp11::unmove(cpp11::as_cpp<integers>(align)), cpp11::unmove(cpp11::as_cpp<doubles>(hjust)), cpp11::unmove(cpp11::as_cpp<doubles>(vjust)), cpp11::unmove(cpp11::as_cpp<doubles>(width)), cpp11::unmove(cpp11::as_cpp<doubles>(tracking)), cpp11::unmove(cpp11::as_cpp<doubles>(indent)), cpp11::unmove(cpp11::as_cpp<doubles>(hanging)), cpp11::unmove(cpp11::as_cpp<doubles>(space_before)), cpp11::unmove(cpp11::as_cpp<doubles>(space_after))));
  END_CPP11
}
// string_metrics.h
doubles get_line_width_c(strings string, strings path, integers index, doubles size, doubles res, logicals include_bearing);
extern "C" SEXP _textshaping_get_line_width_c(SEXP string, SEXP path, SEXP index, SEXP size, SEXP res, SEXP include_bearing) {
  BEGIN_CPP11
    return cpp11::as_sexp(get_line_width_c(cpp11::unmove(cpp11::as_cpp<strings>(string)), cpp11::unmove(cpp11::as_cpp<strings>(path)), cpp11::unmove(cpp11::as_cpp<integers>(index)), cpp11::unmove(cpp11::as_cpp<doubles>(size)), cpp11::unmove(cpp11::as_cpp<doubles>(res)), cpp11::unmove(cpp11::as_cpp<logicals>(include_bearing))));
  END_CPP11
}

extern "C" {
/* .Call calls */
extern SEXP _textshaping_get_line_width_c(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP _textshaping_get_string_shape_c(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"_textshaping_get_line_width_c",   (DL_FUNC) &_textshaping_get_line_width_c,    6},
    {"_textshaping_get_string_shape_c", (DL_FUNC) &_textshaping_get_string_shape_c, 16},
    {NULL, NULL, 0}
};
}

void export_string_metrics(DllInfo* dll);

extern "C" void R_init_textshaping(DllInfo* dll){
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  export_string_metrics(dll);
}

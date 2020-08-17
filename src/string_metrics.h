#pragma once

#define R_NO_REMAP

#include <cpp11.hpp>

using namespace cpp11;

[[cpp11::register]]
list get_string_shape_c(strings string, integers id, strings path, integers index,
                        doubles size, doubles res, doubles lineheight, integers align,
                        doubles hjust, doubles vjust, doubles width, doubles tracking,
                        doubles indent, doubles hanging, doubles space_before,
                        doubles space_after);

[[cpp11::register]]
doubles get_line_width_c(strings string, strings path, integers index, doubles size,
                         doubles res, logicals include_bearing);
int string_width(const char* string, const char* fontfile, int index,
                 double size, double res, int include_bearing, double* width);
int string_shape(const char* string, const char* fontfile, int index,
                 double size, double res, double* x, double* y, int* id, int* n_glyphs, unsigned int max_length);
[[cpp11::init]]
void export_string_metrics(DllInfo* dll);

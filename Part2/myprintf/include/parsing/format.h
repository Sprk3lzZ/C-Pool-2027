/*
** EPITECH PROJECT, 2022
** specification.h
** File description:
** Header of specification
*/

#pragma once

#include <stdint.h>

#include "variant.h"

#define FLAG_ALTERNATE_FORM 0x1u
#define FLAG_ZERO_PADDED    0x2u
#define FLAG_LEFT_ADJUSTED  0x4u
#define FLAG_BLANK          0x8u
#define FLAG_SIGN           0x10u

static char const *const LENGTH_MODIFIER_TOKENS[10] = {
    "hh", "ll", "q", "h", "l", "L", "j", "z", "t", 0};

static char const CONVERSION_TOKENS[22] = {'d', 'i', 'o', 'u', 'x', 'X', 'e',
    'E', 'f', 'F', 'g', 'G', 'a', 'A', 'c', 's', 'p', 'n', '%', 'b', 'S', 0};

static type_t const TOKENS_TO_TYPE[10][22] = {
    // hh
    {TYPE_CHAR, TYPE_CHAR, TYPE_UNSIGNED_CHAR, TYPE_UNSIGNED_CHAR,
        TYPE_UNSIGNED_CHAR, TYPE_UNSIGNED_CHAR, TYPE_DOUBLE, TYPE_DOUBLE,
        TYPE_DOUBLE, TYPE_DOUBLE, TYPE_DOUBLE, TYPE_DOUBLE, TYPE_DOUBLE,
        TYPE_DOUBLE, TYPE_UNSIGNED_CHAR, TYPE_STRING, TYPE_POINTER,
        TYPE_POINTER, TYPE_UNDEFINED, TYPE_UNSIGNED_CHAR, TYPE_STRING,
        TYPE_UNDEFINED},
    // ll
    {TYPE_LONG_LONG_INT, TYPE_LONG_LONG_INT, TYPE_UNSIGNED_LONG_LONG_INT,
        TYPE_UNSIGNED_LONG_LONG_INT, TYPE_UNSIGNED_LONG_LONG_INT,
        TYPE_UNSIGNED_LONG_LONG_INT, TYPE_LONG_DOUBLE, TYPE_LONG_DOUBLE,
        TYPE_LONG_DOUBLE, TYPE_LONG_DOUBLE, TYPE_LONG_DOUBLE, TYPE_LONG_DOUBLE,
        TYPE_LONG_DOUBLE, TYPE_LONG_DOUBLE, TYPE_WINT, TYPE_WSTRING,
        TYPE_POINTER, TYPE_POINTER, TYPE_UNDEFINED,
        TYPE_UNSIGNED_LONG_LONG_INT, TYPE_WSTRING, TYPE_UNDEFINED},
    // q
    {TYPE_LONG_LONG_INT, TYPE_LONG_LONG_INT, TYPE_UNSIGNED_LONG_LONG_INT,
        TYPE_UNSIGNED_LONG_LONG_INT, TYPE_UNSIGNED_LONG_LONG_INT,
        TYPE_UNSIGNED_LONG_LONG_INT, TYPE_LONG_DOUBLE, TYPE_LONG_DOUBLE,
        TYPE_LONG_DOUBLE, TYPE_LONG_DOUBLE, TYPE_LONG_DOUBLE, TYPE_LONG_DOUBLE,
        TYPE_LONG_DOUBLE, TYPE_LONG_DOUBLE, TYPE_WINT, TYPE_WSTRING,
        TYPE_POINTER, TYPE_POINTER, TYPE_UNDEFINED,
        TYPE_UNSIGNED_LONG_LONG_INT, TYPE_WSTRING, TYPE_UNDEFINED},
    // h
    {TYPE_SHORT, TYPE_SHORT, TYPE_UNSIGNED_SHORT, TYPE_UNSIGNED_SHORT,
        TYPE_UNSIGNED_SHORT, TYPE_UNSIGNED_SHORT, TYPE_DOUBLE, TYPE_DOUBLE,
        TYPE_DOUBLE, TYPE_DOUBLE, TYPE_DOUBLE, TYPE_DOUBLE, TYPE_DOUBLE,
        TYPE_DOUBLE, TYPE_UNSIGNED_CHAR, TYPE_STRING, TYPE_POINTER,
        TYPE_POINTER, TYPE_UNDEFINED, TYPE_UNSIGNED_SHORT, TYPE_STRING,
        TYPE_UNDEFINED},
    // l
    {TYPE_LONG_INT, TYPE_LONG_INT, TYPE_UNSIGNED_LONG_INT,
        TYPE_UNSIGNED_LONG_INT, TYPE_UNSIGNED_LONG_INT, TYPE_UNSIGNED_LONG_INT,
        TYPE_DOUBLE, TYPE_DOUBLE, TYPE_DOUBLE, TYPE_DOUBLE, TYPE_DOUBLE,
        TYPE_DOUBLE, TYPE_DOUBLE, TYPE_DOUBLE, TYPE_WINT, TYPE_WSTRING,
        TYPE_POINTER, TYPE_POINTER, TYPE_UNDEFINED, TYPE_UNSIGNED_LONG_INT,
        TYPE_WSTRING, TYPE_UNDEFINED},
    // L
    {TYPE_LONG_LONG_INT, TYPE_LONG_LONG_INT, TYPE_UNSIGNED_LONG_LONG_INT,
        TYPE_UNSIGNED_LONG_LONG_INT, TYPE_UNSIGNED_LONG_LONG_INT,
        TYPE_UNSIGNED_LONG_LONG_INT, TYPE_LONG_DOUBLE, TYPE_LONG_DOUBLE,
        TYPE_LONG_DOUBLE, TYPE_LONG_DOUBLE, TYPE_LONG_DOUBLE, TYPE_LONG_DOUBLE,
        TYPE_LONG_DOUBLE, TYPE_LONG_DOUBLE, TYPE_WINT, TYPE_WSTRING,
        TYPE_POINTER, TYPE_POINTER, TYPE_UNDEFINED,
        TYPE_UNSIGNED_LONG_LONG_INT, TYPE_WSTRING, TYPE_UNDEFINED},
    // j
    {TYPE_INT_MAX, TYPE_INT_MAX, TYPE_UNSIGNED_INT_MAX, TYPE_UNSIGNED_INT_MAX,
        TYPE_UNSIGNED_INT_MAX, TYPE_UNSIGNED_INT_MAX, TYPE_DOUBLE, TYPE_DOUBLE,
        TYPE_DOUBLE, TYPE_DOUBLE, TYPE_DOUBLE, TYPE_DOUBLE, TYPE_DOUBLE,
        TYPE_DOUBLE, TYPE_WINT, TYPE_WSTRING, TYPE_POINTER, TYPE_POINTER,
        TYPE_UNDEFINED, TYPE_UNSIGNED_INT_MAX, TYPE_WSTRING, TYPE_UNDEFINED},
    // z
    {TYPE_SSIZE, TYPE_SSIZE, TYPE_SIZE, TYPE_SIZE, TYPE_SIZE, TYPE_SIZE,
        TYPE_DOUBLE, TYPE_DOUBLE, TYPE_DOUBLE, TYPE_DOUBLE, TYPE_DOUBLE,
        TYPE_DOUBLE, TYPE_DOUBLE, TYPE_DOUBLE, TYPE_WINT, TYPE_WSTRING,
        TYPE_POINTER, TYPE_POINTER, TYPE_UNDEFINED, TYPE_SSIZE, TYPE_WSTRING,
        TYPE_UNDEFINED},
    // t
    {TYPE_PTRDIFF, TYPE_PTRDIFF, TYPE_UNSIGNED_LONG_INT,
        TYPE_UNSIGNED_LONG_INT, TYPE_UNSIGNED_LONG_INT, TYPE_UNSIGNED_LONG_INT,
        TYPE_DOUBLE, TYPE_DOUBLE, TYPE_DOUBLE, TYPE_DOUBLE, TYPE_DOUBLE,
        TYPE_DOUBLE, TYPE_DOUBLE, TYPE_DOUBLE, TYPE_WINT, TYPE_WSTRING,
        TYPE_POINTER, TYPE_POINTER, TYPE_UNDEFINED, TYPE_UNSIGNED_LONG_INT,
        TYPE_WSTRING, TYPE_UNDEFINED},
    // None
    {TYPE_INT, TYPE_INT, TYPE_UNSIGNED_INT, TYPE_UNSIGNED_INT,
        TYPE_UNSIGNED_INT, TYPE_UNSIGNED_INT, TYPE_DOUBLE, TYPE_DOUBLE,
        TYPE_DOUBLE, TYPE_DOUBLE, TYPE_DOUBLE, TYPE_DOUBLE, TYPE_DOUBLE,
        TYPE_DOUBLE, TYPE_CHAR, TYPE_STRING, TYPE_POINTER, TYPE_POINTER,
        TYPE_UNDEFINED, TYPE_UNSIGNED_INT, TYPE_STRING, TYPE_UNDEFINED}};

typedef struct {
    uint8_t resolve;
    uint32_t index;
} resolve_t;

typedef struct {
    uint32_t length;
    uint8_t flags;
    resolve_t width;
    resolve_t precision;
    resolve_t value;
    uint32_t length_modifier;
    uint32_t conversion;
    int8_t error;
} format_resolution_t;

typedef struct {
    format_resolution_t *formats;
    uint32_t length;
    uint32_t capacity;
} format_resolution_array_t;

format_resolution_array_t *format_resolution_array_create(void);
void format_resolution_array_destroy(format_resolution_array_t *array);
void format_resolution_array_push(
    format_resolution_array_t *array, format_resolution_t *spec);

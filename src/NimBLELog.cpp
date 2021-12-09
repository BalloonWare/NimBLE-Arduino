
#include "NimBLELog.h"
#include <stdarg.h>
#include <Arduino.h>

#define NIMBLE_LOG_LINE_LENGTH 256

const char *fmt_snprintf(const char *format, ...) {
  static char *buf;
  if (!buf) {
    buf = (char *)heap_caps_malloc(NIMBLE_LOG_LINE_LENGTH, MALLOC_CAP_SPIRAM);
  }
  if (buf) {
    va_list args;
    va_start(args, format);
    vsnprintf(buf, NIMBLE_LOG_LINE_LENGTH, format, args);

    va_end (args);
    return buf;
  }
  return "<ps_malloc fail>";
}

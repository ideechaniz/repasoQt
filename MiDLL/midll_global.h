#ifndef MIDLL_GLOBAL_H
#define MIDLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MIDLL_LIBRARY)
#  define MIDLLSHARED_EXPORT Q_DECL_EXPORT
#else
#  define MIDLLSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // MIDLL_GLOBAL_H

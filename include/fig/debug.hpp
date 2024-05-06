#ifndef FIG_DEBUG_H
#define FIG_DEBUG_H

#if defined(FIG_DEBUG_OFF_MODE)
#define FIG_DEBUG(stmt)
#else
#define FIG_DEBUG(stmt)                                                        \
  do {                                                                         \
    stmt                                                                       \
  } while (0)
#endif

#endif
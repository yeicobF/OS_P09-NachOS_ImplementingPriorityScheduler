# NOTE: this is a GNU Makefile.  You must use "gmake" rather than "make".
#
# Makefile for the threads assignment.  The threads assignment must
#  be done first!
#
# Copyright (c) 1992 The Regents of the University of California.
# All rights reserved.  See copyright.h for copyright notice and limitation 
# of liability and disclaimer of warranty provisions.

DEFINES = -DTHREADS
INCPATH = -I../threads -I../machine
HFILES = $(THREAD_H)
CFILES = $(THREAD_C)
C_OFILES = $(THREAD_O)

include ../Makefile.common
include ../Makefile.dep
#-----------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend uses it
# DEPENDENCIES MUST END AT END OF FILE
main.o: ../threads/main.cc ../threads/copyright.h ../threads/utility.h \
  ../threads/copyright.h ../machine/sysdep.h /usr/include/stdio.h \
  /usr/include/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/cdefs.h /usr/include/machine/_types.h \
  /usr/include/i386/_types.h /usr/include/string.h ../threads/system.h \
  ../threads/copyright.h ../threads/utility.h ../threads/thread.h \
  ../threads/copyright.h ../threads/utility.h ../threads/scheduler.h \
  ../threads/copyright.h ../threads/list.h ../threads/copyright.h \
  ../threads/utility.h ../threads/thread.h ../machine/interrupt.h \
  ../machine/stats.h ../machine/timer.h
list.o: ../threads/list.cc ../threads/copyright.h ../threads/list.h \
  ../threads/copyright.h ../threads/utility.h ../threads/copyright.h \
  ../machine/sysdep.h /usr/include/stdio.h /usr/include/_types.h \
  /usr/include/sys/_types.h /usr/include/sys/cdefs.h \
  /usr/include/machine/_types.h /usr/include/i386/_types.h \
  /usr/include/string.h
scheduler.o: ../threads/scheduler.cc ../threads/copyright.h \
  ../threads/scheduler.h ../threads/copyright.h ../threads/list.h \
  ../threads/copyright.h ../threads/utility.h ../threads/copyright.h \
  ../machine/sysdep.h /usr/include/stdio.h /usr/include/_types.h \
  /usr/include/sys/_types.h /usr/include/sys/cdefs.h \
  /usr/include/machine/_types.h /usr/include/i386/_types.h \
  /usr/include/string.h ../threads/thread.h ../threads/copyright.h \
  ../threads/utility.h ../threads/system.h ../threads/copyright.h \
  ../threads/utility.h ../threads/thread.h ../threads/scheduler.h \
  ../machine/interrupt.h ../machine/stats.h ../machine/timer.h
synch.o: ../threads/synch.cc ../threads/copyright.h ../threads/synch.h \
  ../threads/copyright.h ../threads/thread.h ../threads/copyright.h \
  ../threads/utility.h ../threads/copyright.h ../machine/sysdep.h \
  /usr/include/stdio.h /usr/include/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/cdefs.h /usr/include/machine/_types.h \
  /usr/include/i386/_types.h /usr/include/string.h ../threads/list.h \
  ../threads/copyright.h ../threads/utility.h ../threads/system.h \
  ../threads/copyright.h ../threads/utility.h ../threads/thread.h \
  ../threads/scheduler.h ../threads/copyright.h ../threads/list.h \
  ../threads/thread.h ../machine/interrupt.h ../machine/stats.h \
  ../machine/timer.h
synchlist.o: ../threads/synchlist.cc ../threads/copyright.h \
  ../threads/synchlist.h ../threads/copyright.h ../threads/list.h \
  ../threads/copyright.h ../threads/utility.h ../threads/copyright.h \
  ../machine/sysdep.h /usr/include/stdio.h /usr/include/_types.h \
  /usr/include/sys/_types.h /usr/include/sys/cdefs.h \
  /usr/include/machine/_types.h /usr/include/i386/_types.h \
  /usr/include/string.h ../threads/synch.h ../threads/copyright.h \
  ../threads/thread.h ../threads/copyright.h ../threads/utility.h \
  ../threads/list.h
system.o: ../threads/system.cc ../threads/copyright.h ../threads/system.h \
  ../threads/copyright.h ../threads/utility.h ../threads/copyright.h \
  ../machine/sysdep.h /usr/include/stdio.h /usr/include/_types.h \
  /usr/include/sys/_types.h /usr/include/sys/cdefs.h \
  /usr/include/machine/_types.h /usr/include/i386/_types.h \
  /usr/include/string.h ../threads/thread.h ../threads/copyright.h \
  ../threads/utility.h ../threads/scheduler.h ../threads/copyright.h \
  ../threads/list.h ../threads/copyright.h ../threads/utility.h \
  ../threads/thread.h ../machine/interrupt.h ../machine/stats.h \
  ../machine/timer.h
thread.o: ../threads/thread.cc ../threads/copyright.h ../threads/thread.h \
  ../threads/copyright.h ../threads/utility.h ../threads/copyright.h \
  ../machine/sysdep.h /usr/include/stdio.h /usr/include/_types.h \
  /usr/include/sys/_types.h /usr/include/sys/cdefs.h \
  /usr/include/machine/_types.h /usr/include/i386/_types.h \
  /usr/include/string.h ../threads/switch.h ../threads/copyright.h \
  ../threads/synch.h ../threads/copyright.h ../threads/thread.h \
  ../threads/list.h ../threads/copyright.h ../threads/utility.h \
  ../threads/system.h ../threads/copyright.h ../threads/utility.h \
  ../threads/thread.h ../threads/scheduler.h ../threads/copyright.h \
  ../threads/list.h ../threads/thread.h ../machine/interrupt.h \
  ../machine/stats.h ../machine/timer.h
utility.o: ../threads/utility.cc ../threads/copyright.h \
  ../threads/utility.h ../threads/copyright.h ../machine/sysdep.h \
  /usr/include/stdio.h /usr/include/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/cdefs.h /usr/include/machine/_types.h \
  /usr/include/i386/_types.h /usr/include/string.h \
  /usr/lib/gcc/i686-apple-darwin9/4.0.1/include/stdarg.h
threadtest.o: ../threads/threadtest.cc ../threads/copyright.h \
  ../threads/system.h ../threads/copyright.h ../threads/utility.h \
  ../threads/copyright.h ../machine/sysdep.h /usr/include/stdio.h \
  /usr/include/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/cdefs.h /usr/include/machine/_types.h \
  /usr/include/i386/_types.h /usr/include/string.h ../threads/thread.h \
  ../threads/copyright.h ../threads/utility.h ../threads/scheduler.h \
  ../threads/copyright.h ../threads/list.h ../threads/copyright.h \
  ../threads/utility.h ../threads/thread.h ../machine/interrupt.h \
  ../machine/stats.h ../machine/timer.h
interrupt.o: ../machine/interrupt.cc ../threads/copyright.h \
  ../machine/interrupt.h ../threads/list.h ../threads/copyright.h \
  ../threads/utility.h ../threads/copyright.h ../machine/sysdep.h \
  /usr/include/stdio.h /usr/include/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/cdefs.h /usr/include/machine/_types.h \
  /usr/include/i386/_types.h /usr/include/string.h ../threads/system.h \
  ../threads/copyright.h ../threads/utility.h ../threads/thread.h \
  ../threads/copyright.h ../threads/utility.h ../threads/scheduler.h \
  ../threads/copyright.h ../threads/list.h ../threads/thread.h \
  ../machine/stats.h ../machine/timer.h
sysdep.o: ../machine/sysdep.cc ../threads/copyright.h \
  /usr/include/stdio.h /usr/include/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/cdefs.h /usr/include/machine/_types.h \
  /usr/include/i386/_types.h /usr/include/string.h /usr/include/signal.h \
  /usr/include/sys/signal.h /usr/include/sys/appleapiopts.h \
  /usr/include/machine/signal.h /usr/include/i386/signal.h \
  /usr/include/i386/_structs.h /usr/include/sys/_structs.h \
  /usr/include/machine/_structs.h /usr/include/mach/i386/_structs.h \
  /usr/include/sys/types.h /usr/include/machine/types.h \
  /usr/include/i386/types.h /usr/include/machine/endian.h \
  /usr/include/i386/endian.h /usr/include/sys/_endian.h \
  /usr/include/libkern/_OSByteOrder.h \
  /usr/include/libkern/i386/_OSByteOrder.h /usr/include/sys/time.h \
  /usr/include/time.h /usr/include/_structs.h /usr/include/sys/_select.h \
  /usr/include/sys/socket.h /usr/include/machine/_param.h \
  /usr/include/i386/_param.h /usr/include/sys/file.h \
  /usr/include/sys/fcntl.h /usr/include/sys/unistd.h \
  /usr/include/sys/queue.h /usr/include/sys/un.h /usr/include/sys/mman.h \
  /usr/include/unistd.h /usr/include/sys/select.h ../machine/interrupt.h \
  ../threads/list.h ../threads/copyright.h ../threads/utility.h \
  ../threads/copyright.h ../machine/sysdep.h ../threads/system.h \
  ../threads/copyright.h ../threads/utility.h ../threads/thread.h \
  ../threads/copyright.h ../threads/utility.h ../threads/scheduler.h \
  ../threads/copyright.h ../threads/list.h ../threads/thread.h \
  ../machine/stats.h ../machine/timer.h
stats.o: ../machine/stats.cc ../threads/copyright.h ../threads/utility.h \
  ../threads/copyright.h ../machine/sysdep.h /usr/include/stdio.h \
  /usr/include/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/cdefs.h /usr/include/machine/_types.h \
  /usr/include/i386/_types.h /usr/include/string.h ../machine/stats.h
timer.o: ../machine/timer.cc ../threads/copyright.h ../machine/timer.h \
  ../threads/utility.h ../threads/copyright.h ../machine/sysdep.h \
  /usr/include/stdio.h /usr/include/_types.h /usr/include/sys/_types.h \
  /usr/include/sys/cdefs.h /usr/include/machine/_types.h \
  /usr/include/i386/_types.h /usr/include/string.h ../threads/system.h \
  ../threads/copyright.h ../threads/utility.h ../threads/thread.h \
  ../threads/copyright.h ../threads/utility.h ../threads/scheduler.h \
  ../threads/copyright.h ../threads/list.h ../threads/copyright.h \
  ../threads/utility.h ../threads/thread.h ../machine/interrupt.h \
  ../machine/stats.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above

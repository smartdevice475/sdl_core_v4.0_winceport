/*
 * Copyright (c) 2016, Ford Motor Company
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of the Ford Motor Company nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef OS_WINCE
#include <csignal>
#endif
#include <cstdlib>
#include <stdint.h>

#include "utils/signals.h"

bool utils::UnsibscribeFromTermination() {
  // Disable some system signals receiving in thread
  // by blocking those signals
  // (system signals processes only in the main thread)
  // Mustn't block all signals!
  // See "Advanced Programming in the UNIX Environment, 3rd Edition"
  // (http://poincare.matf.bg.ac.rs/~ivana//courses/ps/sistemi_knjige/pomocno/apue.pdf,
  // "12.8. Threads and Signals".
#if defined(OS_WIN32) || defined(OS_WINCE)
  return true;
#else
  sigset_t signal_set;
  sigemptyset(&signal_set);
  sigaddset(&signal_set, SIGINT);
  sigaddset(&signal_set, SIGTERM);

  return !pthread_sigmask(SIG_BLOCK, &signal_set, NULL);
#endif
}

namespace {
bool CatchSIGSEGV(sighandler_t handler) {
#if defined(OS_WIN32) || defined(OS_WINCE)
    return true;
#else
  struct sigaction act;

  act.sa_handler = handler;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;

  return !sigaction(SIGSEGV, &act, NULL);
#endif
}
}  // namespace

bool utils::WaitTerminationSignals(sighandler_t sig_handler) {
#if defined(OS_WIN32) || defined(OS_WINCE)
    return true;
#else
  sigset_t signal_set;
  int sig = -1;

  sigemptyset(&signal_set);
  sigaddset(&signal_set, SIGINT);
  sigaddset(&signal_set, SIGTERM);

  if (!CatchSIGSEGV(sig_handler)) {
    return false;
  }

  if (!sigwait(&signal_set, &sig)) {
    sig_handler(sig);
    return true;
  }
  return false;
#endif
}

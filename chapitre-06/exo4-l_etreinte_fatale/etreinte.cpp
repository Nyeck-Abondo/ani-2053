#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKThreading/NkThreadPool.h"
#include "NKThreading/NkThread.h"
#include "NKContainers/Sequential/NkVector.h"
#include "NKTime/NkChrono.h"
#include "NKTime/NkElapsedTime.h"
#include "NKThreading/NkScopedLock.h"
#include "NKThreading/NkMutex.h"

int nkmain(const nkentseu::NkEntryState& state) {
    nkentseu::threading::NkMutex m1;
    nkentseu::threading::NkMutex m2;
    
    nkentseu::threading::NkThread a([&] (void *) {
         nkentseu::threading::NkScopedLock<nkentseu::threading::NkMutex> guard(m1);
         nkentseu::NkChrono::SleepMicroseconds(100);
         nkentseu::threading::NkScopedLock<nkentseu::threading::NkMutex> lock(m2);
    });
    
    nkentseu::threading::NkThread b([&] (void*) {
        nkentseu::threading::NkScopedLock<nkentseu::threading::NkMutex> lock(m2);
        nkentseu::NkChrono::SleepMicroseconds(100);
        nkentseu::threading::NkScopedLock<nkentseu::threading::NkMutex> guard(m1);
    });
    
    a.SetName("Thread A");
    b.SetName("Thread B");
    
    a.Join();
    b.Join();
    return 0;
}
#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKThreading/NkThreadPool.h"
#include "NKThreading/NkThread.h"
#include "NKContainers/Sequential/NkVector.h"
#include "NKTime/NkChrono.h"
#include "NKTime/NkElapsedTime.h"

void SimpleTask(int& i) {
    for (int j = 0; i < 1.e7; j++)
        i++;
}

int nkmain(const nkentseu::NkEntryState& state) {
    nkentseu::NkChrono chrono;
    nkentseu::NkElapsedTime elapsed = {};

    // std::cout << "frfrfr";
    nkentseu::threading::NkThreadPool threadPool;
    int a = 0;
    for (int i = 0; i < 200; ++i) {
        threadPool.Enqueue([&] () {
            SimpleTask(a);
        });
    }
    threadPool.Join();
    std::cout << "[VERSION 01] : temps ecoule : " << chrono.Reset().milliseconds << " --  Ouvriers : " << threadPool.GetNumWorkers() << std::endl;

    a = 0;
    nkentseu::NkVector<nkentseu::threading::NkThread> threadList;
    for (int i = 0; i < 200; i++) {
        threadList.EmplaceBack([&] (auto&&...) {
                    SimpleTask(a);
        });
    }
    for (int i = 0; i < threadList.size(); i++) {
        threadList[i].Join();
    }
    std::cout << "[VERSION 01] : temps ecoule : " << chrono.Reset().milliseconds <<" -- Ouvriers : " << threadList.size();
    return 0;
}
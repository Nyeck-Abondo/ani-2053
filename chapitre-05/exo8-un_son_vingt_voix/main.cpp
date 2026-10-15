#include <iostream>
#include <cstdint>
#include <vector>

struct Audio{
    int currentTime = 0;
    int endLoading = 0;
    int beginLoading = 0;
    int duration = 0;
    int retard = 0;
    int voiceCount = 0;
    bool isFirstLoading = false;
    
    friend std::istream& operator>> (std::istream& is, Audio& a) {
        return is >> a.currentTime;
    }
    
    void calculateStats(int soundDuration, int loadingDelta, int lastLoadEnd = 0) {
        duration = currentTime + soundDuration;
        if (isFirstLoading)
            beginLoading = currentTime;
        else
            beginLoading = std::max(currentTime, lastLoadEnd);
        endLoading = beginLoading + loadingDelta;
        retard = endLoading - currentTime;
    }
};

int main() {
    int n = 0;
    int c = 0, d = 0;
    int voixMax = 0, retardMax = 0, coupes = 0;
    std::vector<Audio> allAudio;
    std::cin >> d >> c >> n;
    
    allAudio.resize(n);
    for (int i = 0; i < n; i++)
        std::cin >> allAudio[i];
        
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            allAudio[i].isFirstLoading = true;
            allAudio[i].calculateStats(d, c);
            allAudio[i].voiceCount = 1;
            if (allAudio[i].endLoading + d > allAudio[i + 1].currentTime) {
                    std::cout << allAudio[i].currentTime << " " << allAudio[i].voiceCount << " "  << allAudio[i].retard << " COUPE" << std::endl;
                    coupes++;
            }
            else {
                std::cout << allAudio[i].currentTime << " " << allAudio[i].voiceCount << " "  << allAudio[i].retard << " ENTIER" << std::endl;
            }
        }
        else {
            allAudio[i].calculateStats(d, c, allAudio[i - 1].endLoading);
            for (int j = 0; j <= i; j++) {
                if (d + allAudio[j].endLoading > allAudio[i].currentTime) {
                    allAudio[i].voiceCount++;
                }
                else {
                    allAudio[i].voiceCount = 0;
                }
            }
            if (i != n - 1) {
                if (allAudio[i].endLoading +  d > allAudio[i + 1].currentTime) {
                    std::cout << allAudio[i].currentTime << " " << allAudio[i].voiceCount << " "  << allAudio[i].retard << " COUPE" << std::endl;
                    coupes++;
                }
                else {
                    std::cout << allAudio[i].currentTime << " " << allAudio[i].voiceCount << " "  << allAudio[i].retard << " ENTIER" << std::endl;
                }
            }
            else {
                std::cout << allAudio[i].currentTime << " " << allAudio[i].voiceCount << " "  << allAudio[i].retard << " ENTIER" << std::endl;
            }
        }
        voixMax = std::max(voixMax, allAudio[i].voiceCount);
        retardMax = std::max(retardMax, allAudio[i].retard);
    }
    
    std::cout << "VOIX_MAX " << voixMax << std::endl;
    std::cout << "RETARD_MAX " << retardMax << std::endl;
    std::cout << "COUPES " << coupes << std::endl;
    
    return 0;
}

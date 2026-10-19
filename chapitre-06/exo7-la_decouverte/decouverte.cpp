#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKNetwork/NKNetwork.h"
#include "NKTime/NkClock.h"

enum class NetRole{
    NONE,
    SERVER,
    CLIENT  
};

int nkmain(const nkentseu::NkEntryState& state) {
    NetRole role = NetRole::NONE;
    nkentseu::NkString arg = state.args[1];
    nkentseu::NkString ip = state.args[state.args.Size() > 2 ? 2 : 0];
    nkentseu::uint16 port = 7777;

    if (arg == "--server") {
        role = NetRole::SERVER;
    }
    else if (arg == "--client") {
        role = NetRole::CLIENT;
        if (ip.Empty()) {
            logger.Error("[APP] : Omission de l'IP du serveur !");
            return -2;
        }
    }

    if (nkentseu::net::NkSocket::PlatformInit() != nkentseu::net::NkNetResult::NK_NET_OK) {
        logger.Error("[APP] : Echec d'initialisation de la plateforme");
        return -3;
    }

    if (role == NetRole::CLIENT) {
        nkentseu::NkVector<nkentseu::net::NkDiscovery::ServerInfo> servers;
        if (nkentseu::net::NkDiscovery::Listen(10000, servers) == nkentseu::net::NkNetResult::NK_NET_OK) {
            for (const auto& svr : servers)
            logger.Warn("[APP] : Adresse serveur : {0} Nom : {1}", svr.addr.ToString(), svr.name);
        }    
    }

    if (role == NetRole::SERVER) {
        nkentseu::net::NkDiscovery::ServerInfo info;
        info.addr = nkentseu::net::NkAddress::Any(7777);
        std::strcpy(info.name, "My LAN Server");
        std::strcpy(info.gameMode, "team_deathmatch");

        info.maxPlayers = 16;
        info.hasPassword = false;

        nkentseu::uint64 ellapsed = 0;
        nkentseu::float32 dt = 0;
        nkentseu::float32 count = 0;
        nkentseu::NkClock chrono;
        while (ellapsed < 10000) {
            dt = chrono.Tick().delta;
            count += dt;
            if (count >= 2.f) {
                count = 0;
               nkentseu::net::NkNetResult result = nkentseu::net::NkDiscovery::Broadcast(info);
               if (result != nkentseu::net::NkNetResult::NK_NET_OK) {
                   logger.Warn("[APP] : impossible de diffuser les informations du serveur");
               }
               logger.Info("[APP] : Diffusion des infomations du serveur");
            }
            nkentseu::NkChrono::SleepMilliseconds(17);
        }
    }

    return 0;
}
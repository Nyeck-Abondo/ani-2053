#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKNetwork/NKNetwork.h"

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
    nkentseu::NkConnectionManager manager;

    if (role == NetRole::CLIENT){
        manager.onPeerConnected = [] (nkentseu::net::NkPeerId) {
            logger.Warn("[APP] : Serveur connecte avec succes");
        };
        nkentseu::net::NkAddress address(ip.CStr(), port);
        if (!address.IsValid()) {
            logger.Error("[APP] : Adresse invalide");
            return -4;
        }
        const auto result = manager.Connect(address);
        if (result != nkentseu::net::NkNetResult::NK_NET_OK) {
            logger.Error("[APP] : Erreur de connexion du client au serveur");
        }

        //temps d'atente de connexion
        nkentseu::uint64 ellapsed = 0;
        for (nkentseu::uint64 i = 0; i < 1000000000; ++i) {
            ellapsed++;
            if (ellapsed >= 300000000) {
                logger.Info("[APP] : RECHERCHE DU SERVEUR");
                nkentseu::NkString msg = "Bonjour depuis le client trs cher serveur.";
                nkentseu::NkVector<nkentseu::uint8> convertMsg(msg.Size());
                std::memcpy(convertMsg.Data(), msg.Data(), msg.Size());
                nkentseu::net::NkNetResult r = manager.SendTo(nkentseu::net::NkPeerId::Server(), convertMsg.Data(), convertMsg.Size());
                if (r != nkentseu::net::NkNetResult::NK_NET_OK) {
                    logger.Warn("[APP] : Erreur d'envoie du message sur le fil");
                }
                logger.Warn("[APP] : Message envoye");
                ellapsed = 0;   
            }
        }


    }        

    else if (role == NetRole::SERVER) {
        manager.onPeerConnected = [] (nkentseu::net::NkPeerId) {
            logger.Warn("[APP] : Client connecte avec succes");
        };
        nkentseu::net::NkNetResult result = manager.StartServer(port, 8);
        //temps d'atente de connexion
        nkentseu::uint64 ellapsed = 0;
        for (nkentseu::uint64 i = 0; i < 1000000000; ++i) {
            ellapsed++;
            if (ellapsed >= 300000000) {
                logger.Info("[APP] : RECHERCHE DU CLIENT");
                ellapsed = 0;   
            }
            if (manager.ConnectedPeerCount() >= 1) {
                break;
            }
        }
        //collecte des messages
        ellapsed = 0;
        while (ellapsed < 1000000000) {
            nkentseu::NkVector<nkentseu::net::NkReceiveMsg> msgs;
            msgs.Clear();
            manager.DrainAll(msgs);
            for (int i = 0; i < msgs.Size(); i++) {
                const auto& msg = msgs[i];
                nkentseu::NkString clientMsg{reinterpret_cast<const char*>(msg.data), msg.size};
                logger.Warn("[Client] : {0} --  ID : {1}",clientMsg.CStr(),msg.from.value);
            }   
        }
    }

    return 0;
}
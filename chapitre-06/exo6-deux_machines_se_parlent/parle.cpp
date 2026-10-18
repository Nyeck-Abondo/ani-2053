#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include "NKNetwork/NKNetwork.h"

enum class NetRole{
    NONE,
    SERVER,
    CLIENT  
};
//gestion du choix du role en ligne de commande style Gemcrush
nkentseu::NkString ParseText(const nkentseu::NkVector<nkentseu::NkString>& args, const char* option) {
    nkentseu::int32 optionLengh = nkentseu::NkString(option).Size();
    for (int i = 0; i < args.Size(); ++i) {
        if (args[i].StartsWith(option))
        return args[i].SubStr(optionLengh);
    }
    return nkentseu::NkString();
}

int nkmain(const nkentseu::NkEntryState& state) {
    NetRole role = NetRole::NONE;
    nkentseu::NkString arg = state.args[1];
    nkentseu::NkString ip = state.args[state.args.Size() > 2 ? 2 : 0];
    nkentseu::uint16 port = 7777;
    logger.Warn("[APP] ARGUMENT : {0}, ip : {1}", arg.CStr(), ip.CStr());

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
                ellapsed = 0;   
            }
            if (manager.ConnectedPeerCount() >= 1) {
                break;
            }
        }
        
        nkentseu::NkString msg = "Bonjour depuis le client trs cher serveur.";
        nkentseu::NkVector<nkentseu::uint8> convertMsg(msg.Size());
        std::memcpy(convertMsg.Data(), msg.Data(), msg.Size());
        nkentseu::net::NkNetResult r = manager.SendTo(nkentseu::net::NkPeerId::Server(), convertMsg.Data(), convertMsg.Size());
        if (r != nkentseu::net::NkNetResult::NK_NET_OK) {
            logger.Warn("[APP] : Erreur d'envoie du message sur le fil");
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
        nkentseu::NkVector<nkentseu::net::NkReceiveMsg> msgs;
        manager.DrainAll(msgs);
        for (int i = 0; i < msgs.Size(); i++) {
            const auto msg = msgs[i];
            nkentseu::NkString clientMsg{reinterpret_cast<const char*>(msg.data), msg.size - 1};
            std::cout << "[Client] : " << clientMsg.CStr() << " ID : " << msg.from.value << std::endl;
        }
    }

    return 0;
}
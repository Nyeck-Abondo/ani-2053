#include "fenetre.h"

fenetre::fenetre() {
    
}

fenetre::~fenetre() {
}

void fenetre::OnRender(nkentseu::renderer::NkRenderWindow &target) {
    target.Clear({2, 31, 15});
}

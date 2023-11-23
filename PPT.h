#ifndef PPT_H
#define PPT_H

#include "Juego.h"

class PPT : public Juego {
public:
    PPT();
    bool jugar() override;
};

#endif

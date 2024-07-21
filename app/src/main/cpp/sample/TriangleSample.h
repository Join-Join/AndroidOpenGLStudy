//
// Created by ZSP on 2024-07-21.
//

#ifndef OPENGLNDKSTUDY_TRIANGLESAMPLE_H
#define OPENGLNDKSTUDY_TRIANGLESAMPLE_H

#include "BaseSample.h"

class TriangleSample : public BaseSample{

public:
    TriangleSample();
    virtual ~TriangleSample();

    virtual void Destroy() = 0;
    virtual void Draw(int screenWidth, int screenHeight) = 0;
    virtual void Init() = 0;
};

#endif //OPENGLNDKSTUDY_TRIANGLESAMPLE_H

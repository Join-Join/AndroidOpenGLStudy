//
// Created by ZSP on 2024-07-21.
//

#ifndef OPENGLNDKSTUDY_TRIANGLESAMPLE_H
#define OPENGLNDKSTUDY_TRIANGLESAMPLE_H

#include "BaseSample.h"
#include "../util/GLUtils.h"
#include "../util/LogUtil.h"

class TriangleSample : public BaseSample {

public:
    TriangleSample() ;
    virtual ~TriangleSample();
    virtual void Init();
    virtual void Draw(int screenWidth, int screenHeight);
    virtual void Destroy();

    //virtual void Destroy() = 0; 是错误的
};

#endif //OPENGLNDKSTUDY_TRIANGLESAMPLE_H

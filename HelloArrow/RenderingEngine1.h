//
//  RenderingEngine1.h
//  HelloArrow
//
//  Created by Allan Davis on 1/22/13.
//  Copyright (c) 2013 Cajun Code. All rights reserved.
//

#ifndef __HelloArrow__RenderingEngine1__
#define __HelloArrow__RenderingEngine1__

#include <iostream>
#include "IRenderingEngine.h"
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>


class RenderingEngine1 : public IRenderingEngine{
public:
    RenderingEngine1();
    void initialize(int width, int height);
    void render() const;
    void update_animation(float time_step) {}
    void on_rotate(DeviceOrientation new_orientation) {}
    
private:
    GLuint frameBuffer;
    GLuint renderBuffer;
};



#endif /* defined(__HelloArrow__RenderingEngine1__) */

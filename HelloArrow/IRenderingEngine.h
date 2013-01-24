//
//  IRenderingEngine.h
//  HelloArrow
//
//  Created by Allan Davis on 1/4/13.
//  Copyright (c) 2013 Cajun Code. All rights reserved.
//

#ifndef HelloArrow_IRenderingEngine_h
#define HelloArrow_IRenderingEngine_h

enum DeviceOrientation{
    DeviceOrientationUnknown,
    DeviceOrientationPortrait,
    DeviceOrientationPortraitUpsideDown,
    DeviceOrientationLandscapeLeft,
    DeviceOrientationLandscapeRight,
    DeviceOrientationFaceUp,
    DeviceOrientationFaceDown,
};


class IRenderingEngine {
    
public:
    virtual void initialize(int width, int height) = 0;
    virtual void render() const = 0;
    virtual void update_animation(float time_step) = 0;
    virtual void on_rotate(DeviceOrientation new_orientation) = 0;
    virtual ~IRenderingEngine(){};
};

IRenderingEngine * CreateRenderer1();
#endif

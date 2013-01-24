//
//  GLView.h
//  HelloArrow
//
//  Created by Allan Davis on 1/3/13.
//  Copyright (c) 2013 Cajun Code. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <OpenGLES/EAGL.h>
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>
#import <QuartzCore/QuartzCore.h>

#import "IRenderingEngine.h"

@interface GLView : UIView

- (void) drawView:(CADisplayLink *)displayLink;
- (void) didRotate: (NSNotification *) notification;

@end

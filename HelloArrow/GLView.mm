//
//  GLView.m
//  HelloArrow
//
//  Created by Allan Davis on 1/3/13.
//  Copyright (c) 2013 Cajun Code. All rights reserved.
//

#import "GLView.h"
#import <OpenGLES/EAGLDrawable.h>
#import <OpenGLES/ES2/gl.h>
#import "mach/mach_time.h"

@interface GLView()

@property EAGLContext *context;
@property IRenderingEngine *engine;
@property float timestamp;

@end

@implementation GLView

+(Class) layerClass{
    return [CAEAGLLayer class];
}

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        CAEAGLLayer *glLayer = (CAEAGLLayer *) super.layer;
        glLayer.opaque = YES;
        
        _context = [[EAGLContext alloc] initWithAPI: kEAGLRenderingAPIOpenGLES1];
        if (!_context || ![EAGLContext setCurrentContext:_context]) {
            return nil;
        }
        // Initialization code
        
        self.engine = CreateRenderer1();
        
        [_context renderbufferStorage:GL_RENDERBUFFER fromDrawable:glLayer];
        
        self.engine->initialize(CGRectGetWidth(frame), CGRectGetHeight(frame));
        
        [self drawView: nil];
        self.timestamp = CACurrentMediaTime();
        
        CADisplayLink * displayLink;
        displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(drawView:)];
        [displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
        [[UIDevice currentDevice] beginGeneratingDeviceOrientationNotifications];
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(didRotate:) name:UIDeviceOrientationDidChangeNotification object:nil];
        
        
    }
    return self;
}
- (void) drawView:(CADisplayLink *)displayLink{
   
    if (displayLink != nil) {
        float elapsedSeconds = displayLink.timestamp - self.timestamp;
        self.timestamp = displayLink.timestamp;
        self.engine->update_animation(elapsedSeconds);
    }
    self.engine->render();
    [self.context presentRenderbuffer:GL_RENDERBUFFER];
}
- (void) didRotate: (NSNotification *) notification{
    UIDeviceOrientation orientation = [[UIDevice currentDevice] orientation];
    
    self.engine->on_rotate((DeviceOrientation) orientation);
    [self drawView:nil];
}




@end

//
//  MadNetStyleConfig.h
//  MADNET iOS SDK -> http://help.madnet.ru
//
//  Copyright 2014 MADNET. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum
{
    etsDefault = 0,
    etsBlack = 1,
} EMadNetToolbarStyle;

@interface MadNetStyleConfig : NSObject

@property (nonatomic, assign) UIBarStyle toolbarStyle;
@property (nonatomic, retain) UIColor *toolbarTintColor;

@property (nonatomic, retain) UIColor *barButtonItemTintColor;
@property (nonatomic, retain) UIColor *closeButtonTintColor;

- (void) setMadNetToolbarStyle: (EMadNetToolbarStyle) aStyle;

+ (MadNetStyleConfig *) sharedConfig;

@end

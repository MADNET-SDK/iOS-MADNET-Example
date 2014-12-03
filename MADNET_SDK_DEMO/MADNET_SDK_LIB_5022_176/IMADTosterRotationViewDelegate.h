//
//  IMADTosterRotationViewDelegate.h
//  MADNET iOS SDK -> http://help.madnet.ru
//
//  Copyright 2014 MADNET. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IMADRotationViewDelegate.h"

@class MADTosterRotationView;
@protocol IMADTosterRotationViewDelegate <IMADRotationViewDelegate>

@optional
/**
 This method is invoked when the user clicks on the cross.
 Returning NO, you can restrict the user to close the banner or ask him to make
 an additional purchase to remove the banner.
 */
- (BOOL) tosterAdViewWillClose: (MADTosterRotationView *) aTosterAdView;

- (void) tosterAdViewDidClose: (MADTosterRotationView *) aTosterAdView;

@end

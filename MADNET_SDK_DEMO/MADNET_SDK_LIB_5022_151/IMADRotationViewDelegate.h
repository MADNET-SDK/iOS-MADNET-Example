//
//  IMADRotationViewDelegate.h
//  MADNET iOS SDK -> http://help.madnet.ru
//
//  Copyright 2014 MADNET. All rights reserved.
//


#import <Foundation/Foundation.h>
@class MADRotationView;

@protocol IMADRotationViewDelegate <NSObject>

@optional

- (void) rotationViewDidReceiveAd: (MADRotationView *) aRotationView;
- (void) rotationView: (MADRotationView *) aRotationView didFailToReceiveAdWithError: (NSError *) aError;

- (void) rotationViewClick: (MADRotationView *) aRotationView;

- (void) rotationViewDidShow: (MADRotationView *) aRotationView;

- (void) rotationViewDidExtraAction: (MADRotationView *) aRotationView;

- (void) rotationViewShouldSuspendApp: (MADRotationView *) aRotationView;
- (void) rotationViewShouldResumeApp: (MADRotationView *) aRotationView;

- (void) rotationViewWillPresentModal:(MADRotationView *)aRotationView;
- (void) rotationViewWillDismissModal:(MADRotationView *)aRotationView;
- (void) rotationViewDidDismissModal:(MADRotationView *)aRotationView;
- (void) rotationViewWillLeaveApplication: (MADRotationView *)aRotationView;

- (void) rotationViewDidPauseServerRequest: (MADRotationView *)aRotationView;
- (void) rotationViewDidResumeServerRequest: (MADRotationView *)aRotationView;

- (BOOL) rotationViewTestingMode: (MADRotationView *)aRotationView;

@required
- (UIViewController *) MADViewController;

@end